#pragma once
#include "Grafo.h"

using namespace std;

using Mapa = vector<string>; // grafo impl�cito en el mapa

class Manchas
{
public:
	Manchas(Mapa const& M) : F(M.size()), C(M[0].size()),
		visit(F, vector<bool>(C, false)), num(0), maxim(0) {
		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) {
				if (!visit[i][j] && M[i][j] == '#') { // se recorre una nueva mancha
					++num;
					int nuevotam = dfs(M, i, j);
					maxim = max(maxim, nuevotam);
				}
			}
		}
	}

	int numero() const { return num; }
	int maximo() const { return maxim; }

private:
	int F, C; // tama�o del mapa
	vector<vector<bool>> visit; // visit[i][j] = se ha visitado el p�xel <i,j>?
	int num; // n�mero de manchas
	int maxim; // tama�o de la mancha m�s grande
	bool correcta(int i, int j) const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}
	const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };
	int dfs(Mapa const& M, int i, int j) {
		visit[i][j] = true;
		int tam = 1;
		for (auto d : dirs) {
			int ni = i + d.first, nj = j + d.second;
			if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
				tam += dfs(M, ni, nj);
			}
		}
		return tam;
	}
};

