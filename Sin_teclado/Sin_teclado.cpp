
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, vector<int> const& tc) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), fin(g.V() - 1) {
        dist[origen] = tc[0];
        pq.push(origen, tc[0]);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a, tc);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    Valor distancia() const { return dist[fin]; }
    deque<Valor> camino(int v) const {
        deque<Valor> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a.desde());
        //cam.push_front(a.valor());
        return cam;
    }

    //int coste(vector<int> const& tc) {
    //    int ret = dist[fin];
    //    deque<Valor> c = camino(fin);
    //    for (auto e : camino(fin))
    //        ret += tc[e];
    //    return ret;
    //}
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int fin;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a, vector<int> const& tc) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + tc[w]) {
            dist[w] = dist[v] + a.valor() + tc[w]; ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    vector<int> tiempoCarga(N);
    for (auto& e : tiempoCarga)
        cin >> e;
    DigrafoValorado<int> dgv(N);
    int M;
    cin >> M;
    int v, w, val;
    for (int i = 0; i < M; ++i) {
        cin >> v >> w >> val;
        --v; --w;
        AristaDirigida<int> ad(v, w, val);
        dgv.ponArista(ad);
    }
    // resolver el caso posiblemente llamando a otras funciones
    Dijkstra<int> dj(dgv, 0, tiempoCarga);
    // escribir la solución
    dj.hayCamino(N - 1) ? cout << dj.distancia() << '\n' : cout << "IMPOSIBLE\n";

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
