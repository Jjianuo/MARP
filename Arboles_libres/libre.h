#pragma once
#include "Grafo.h"
class libre
{
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	Grafo const& g;

	void esLibreAux(Grafo const& g, int v, bool& ret) {
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (!visit[w]) { //si no se ha visitado aun
				ant[w] = v; //se asigna el anterior
				esLibreAux(g, w, ret); //se avanza en profundidad
			}
			else if(w != ant[v]) { //ya se ha visitado
				ret = false;
				return;
			}
		}
	}

public:
	libre(Grafo const& _g) : g(_g), visit(_g.V(), false), ant(_g.V()) {};
	bool esLibre(int v) {
		bool ret = true;
		esLibreAux(g, v, ret);
		return ret;
	}

};

