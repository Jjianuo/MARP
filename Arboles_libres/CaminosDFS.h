#pragma once
#include "Grafo.h"
#include <deque>
#include <unordered_set>

using namespace std;
using Camino = std::deque<int>; // para representar caminos

class CaminosDFS
{
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> frenn;
	//std::unordered_set<int> frenn;
	int s; // vértice origen
	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				frenn.push_back(visit[w]);
				ant[w] = v;
				dfs(G, w);
			}
		}
	}
public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		dfs(g, s);
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
	vector<int> amigos(int v) {
		return frenn;
	}

	bool todasVisitadas() {
		for (auto e : visit) if (!e) return false;
		return true;
	}
};

