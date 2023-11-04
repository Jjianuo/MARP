
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (MARPXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int d) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), dMax(d), visit(g.V(), false), num(0) {
        dist[origen] = 0;
        visit[origen] = true;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    int sol() { return num; }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    deque<AristaDirigida<Valor>> camino(int v) const {
        deque<AristaDirigida<Valor>> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    std::vector<bool> visit;
    int dMax;
    int num;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() && dist[v] + a.valor() <= dMax) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            if (!visit[w]) {
                visit[w] = true;
                ++num;
            }
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leemos la entrada
    int D, P, C;
    cin >> D >> P >> C;

    if (!cin)
        return false;

    // leer el resto del caso y resolverlo
    DigrafoValorado<int> dgv(P + 1);
    int v, w, val;
    for (int i = 0; i < C; ++i) {
        cin >> v >> w >> val;
        AristaDirigida<int> aux(v, w, val);
        AristaDirigida<int> aux2(w, v, val);
        dgv.ponArista(aux);
        dgv.ponArista(aux2);
    }

    cin >> val;
    for (int i = 0; i < val; ++i) {
        cin >> v;
        AristaDirigida<int> aux(0, v, 0);
        dgv.ponArista(aux);
    }
    Dijkstra<int> dj(dgv, 0, D);
    cout << dj.sol() << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
