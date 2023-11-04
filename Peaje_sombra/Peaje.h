#pragma once
#include "Grafo.h"
#include <queue>

using namespace std;
using Camino = std::deque<int>; // para representar caminos

class Peaje
{
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
	int s; // vértice origen

	void bfs(Grafo const& g) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
		}
	}
public:
	Peaje(const Grafo& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s)
	{
		bfs(g);
	}

	// ¿hay camino del origen a v?
	bool hayCamino(int v) const {
		return visit[v];
	}

	// devuelve un camino desde el origen a v (debe existir)
	Camino camino(int v) const {
		if (!hayCamino(v))
			throw std::domain_error("No existe camino");
		Camino cam;
		// recuperamos el camino retrocediendo
		for (int x = v; x != s; x = ant[x])
			cam.push_front(x);
		cam.push_front(s);
		return cam;
	}

	int distancia(int v) const {
		return dist[v];
	}

};

