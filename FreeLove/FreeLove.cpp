
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct sInfo {
    pair<int, int> casilla;
    int extension;
};

using Mapa = vector<string>; // grafo implícito en el mapa
class Manchas {
    int F, C; // tamaño del mapa
    vector<vector<bool>> visit; // visit[i][j] = se ha visitado el píxel <i,j>?
    std::vector<vector<int>> dist;
    bool correcta(int i, int j) const {
        return 0 <= i && i < F && 0 <= j && j < C;
    }
    const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };


    void bfs(Mapa const& M, int i, int j) {
        std::queue<pair<int, int>> q;
        visit[i][j] = true;
        q.push({i, j});
        if (M[i][j] == '!')
            return;
        while (!q.empty()) {
            pair<int, int> v = q.front(); q.pop();
            for (auto d : dirs) {
                int ni = v.first + d.first, nj = v.second + d.second;
                if (correcta(ni, nj)) {
                    if ((M[ni][nj] == '.' || M[ni][nj] == 'P') && !visit[ni][nj]) {
                        dist[ni][nj] = dist[v.first][v.second] + 1; visit[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }

    void ponSensores(Mapa& mapa, const vector<sInfo>& sensores) {
        for (auto e : sensores) {
            int x = e.casilla.first; int y = e.casilla.second;
            mapa[x][y] = '!';
            for (auto d : dirs) {
                int j = 1;
                bool pared = false;
                while (j <= e.extension && correcta(x + (d.first * j), y + (d.second * j)) && !pared) {
                    int x2 = x + (d.first * j); int y2 = y + (d.second * j);
                    char aux = mapa[x2][y2];
                    if (aux != '#')
                        mapa[x2][y2] = '!';
                    else
                        pared = true;
                    ++j;
                }
            }
        }
    }
public:

    Manchas(Mapa& M, const vector<sInfo>& sensores, pair<int, int> const& entrada) : F(M.size()), C(M[0].size()),
        visit(F, vector<bool>(C, false)), dist(F, vector<int>(C, 0)) {
        ponSensores(M, sensores);
        bfs(M, entrada.first, entrada.second);
    }

    int distancia(pair<int, int> v) const {
        return dist[v.first][v.second];
    }

    bool hayCamino(pair<int, int> v) const {
        return visit[v.first][v.second];
    }
};

void resuelveCaso() {
    int ancho, alto;
    cin >> ancho >> alto;
    vector<string> mapa(alto);
    vector<sInfo> sensores;
    pair<int, int> entrada;
    pair<int, int> salida;
    const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };
    for (int i = 0; i < alto; ++i) {
        cin >> mapa[i];
        for (int j = 0; j < ancho; ++j) {
            if (mapa[i][j] != '.' && mapa[i][j] != '#' && mapa[i][j] != 'E' && mapa[i][j] != 'P') { // es un snesor
                sInfo aux;
                aux.casilla = { i, j };
                aux.extension = mapa[i][j] - '0';
                sensores.push_back(aux);
            }
            else if (mapa[i][j] == 'E') {
                entrada = { i, j };
            }
            else if (mapa[i][j] == 'P') {
                salida = { i, j };
            }
        }
    }

    Manchas m(mapa, sensores, entrada);
    // resolver el caso posiblemente llamando a otras funciones
    m.hayCamino(salida) ? cout << m.distancia(salida) << '\n' : cout << "NO\n";
    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
