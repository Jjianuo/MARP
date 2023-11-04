#pragma once
#include "Grafo.h"
#include <algorithm>
class MaximaCompConexa
{
public:
	MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
		for (int v = 0; v < g.V(); ++v) {
			if (!visit[v]) { // se recorre una nueva componente conexa
				int tam = dfs(g, v);
				maxim = std::max(maxim, tam);
			}
		}
	}
	// tama�o m�ximo de una componente conexa
	int maximo() const {
		return maxim;
	}
private:
	std::vector<bool> visit; // visit[v] = se ha visitado el v�rtice v?
	int maxim; // tama�o de la componente mayor
	int dfs(Grafo const& g, int v) {
		visit[v] = true;
		int tam = 1;
		for (int w : g.ady(v)) {
			if (!visit[w])
				tam += dfs(g, w);
		}
		return tam;
	}
};

