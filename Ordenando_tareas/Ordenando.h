#pragma once
#include <queue>
#include <algorithm>
#include "Digrafo.h"

using namespace std;
using Camino = std::deque<int>; // para representar caminos

class Ordenando
{
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	Camino cam;
	queue<int> orden;
	int s;
	void bfs(Digrafo const& g) {
		std::queue<int> q;
		q.push(s);
		Digrafo inv = g.inverso();
		//camino.push_back(1);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto e : inv.ady(v)) {
				if (!visit[e]) {
					cam.push_back(e);
					visit[e] = true;
				}
			}
		}

		for (int i = 0; i < visit.size(); ++i) {
			if (!visit[i])
				cam.push_back(i);
		}
	}
public:
	Ordenando(Digrafo const& g, int s) : visit(g.V(), false) {
		bfs(g);
	}
	bool hayCamino(int v) const {
		return visit[v];
	}

	Camino ordenando() {
		return cam;
	}
};

