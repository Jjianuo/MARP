#pragma once
#include <deque>
#include "Digrafo.h"

class OrdenTopologico
{
	std::vector<bool> visit;
	std::deque<int> _orden; // ordenaci�n topol�gica
	void dfs(Digrafo const& g, int v) {
		visit[v] = true;
		for (int w : g.ady(v))
			if (!visit[w])
				dfs(g, w);
		_orden.push_front(v);
	}
public:
	// g es DAG
	OrdenTopologico(Digrafo const& g) : visit(g.V(), false) {
		for (int v = 0; v < g.V(); ++v)
			if (!visit[v])
				dfs(g, v);
	}
	// devuelve la ordenaci�n topol�gica
	std::deque<int> const& orden() const {
		return _orden;
	}
};

