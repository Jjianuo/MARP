#pragma once
#include <queue>
#include <algorithm>
#include "Digrafo.h"

using namespace std;
using Camino = std::deque<int>; // para representar caminos

class BFSDirigido
{
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> dist; // dist[v] = aristas en el camino s->v más corto
	Camino cam;
	queue<int> orden;
	std::vector<bool> added; // visit[v] = ¿hay camino de s a v?
	int s;
	void bfs(Digrafo const& g) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		q.push(s);
		Digrafo inv = g.inverso();
		//camino.push_back(1);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto e : inv.ady(v)) {
				if (!added[e]) {
					cam.push_back(e);
					added[e] = true;
				}
			}
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
			if (g.ady(v).empty())
				q.push(++s);
		}

		for (int i = 0; i < added.size(); ++i) {
			if (!added[i])
				cam.push_back(i);
		}
	}
public:
	BFSDirigido(Digrafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), dist(g.V()), s(s), added(g.V(), false) {
		bfs(g);
	}
	bool hayCamino(int v) const {
		return visit[v];
	}
	int distancia(int v) const {
		return dist[v];
	}
	Camino camino(int v) const {
		if (!hayCamino(v)) throw std::domain_error("No existe camino");
		Camino cam;
		for (int x = v; x != s; x = ant[x])
			cam.push_front(x);
		cam.push_front(s);
		return cam;
	}

	Camino ordenando() {
		return cam;
	}
};

