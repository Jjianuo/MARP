#pragma once
#include "Grafo.h"
#include <deque>

using namespace std;
using Camino = std::deque<int>; // para representar caminos

class Conectados 
{
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	std::vector<int> all_frens;
	int s; // vértice origen
	void dfs(Grafo const& G, int v, vector<int>& fren) {
		visit[v] = true;
		fren.push_back(v);
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dfs(G, w, fren);
			}
		}
	}
public:
	Conectados(const Grafo& g, int s) : visit(g.V(), false), ant(g.V()), all_frens(g.V()), s(s)
	{
		for (int i = 0; i < g.V(); ++i) {
			if (!visit[i]) {
				vector<int> fren;
				dfs(g, i, fren);
				for (auto f : fren) 
					all_frens[f] = fren.size();
			}
		}
	}
	~Conectados() {};

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

	vector<int> frennns() {
		return all_frens;
	}
};
