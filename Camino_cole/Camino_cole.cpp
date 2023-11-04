
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), fin(g.V() - 1), caminos(0), formasLlegar(g.V(), 0) {
        dist[origen] = 0;
        pq.push(origen, 0);
        formasLlegar[0] = 1;
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)) {
                relajar(a);
            }
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    Valor distancia() const { return dist[fin]; }
    int caminosMinimos() const { return formasLlegar[fin]; }
    deque<Valor> camino(int v) const {
        deque<Valor> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a.desde());
        //cam.push_front(a.valor());
        return cam;
    }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int fin;
    int caminos;
    std::vector<Valor> dist;
    std::vector<int> formasLlegar;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) { //si el camino tiene coste menor
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            formasLlegar[w] = 0;
            formasLlegar[w] += formasLlegar[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) { //si el camino tiene mismo coste y llega al final
            formasLlegar[w] += formasLlegar[v];
        }
    }
};

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    int C;
    cin >> C;

    DigrafoValorado<int> dgv(N);
    int v, w, val;
    for (int i = 0; i < C; ++i) {
        cin >> v >> w >> val;
        --v; --w;
        AristaDirigida<int> aux(v, w, val);
        AristaDirigida<int> aux2(w, v, val);
        dgv.ponArista(aux);
        dgv.ponArista(aux2);
    }
    Dijkstra<int> dj(dgv, 0);
    cout << dj.caminosMinimos() << '\n';
    //dj.hayCamino(N - 1) ? cout << dj.caminosMinimos() << '\n' : cout << "IMPOSIBLE\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
