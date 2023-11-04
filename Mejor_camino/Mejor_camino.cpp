
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
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
        dist(g.V(), INF), ulti(g.V()), pq(g.V()), visit(g.V(), false), distBFS(g.V()), menorCam(g.V()) {
        dist[origen] = 0;
        menorCam[0] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
        bfs(g, orig);
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    int masCorto(int v) const {
        return distBFS[v];
    }
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
    std::vector<int> menorCam;
    IndexPQ<Valor> pq;
    std::vector<bool> visit;
    std::vector<int> distBFS;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() || (dist[w] == dist[v] + a.valor() && menorCam[w] > menorCam[v] + 1)) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            menorCam[w] = menorCam[v] + 1;
            pq.update(w, dist[w]);
        }
    }
    
    void bfs(DigrafoValorado<Valor> const& g, int s) {
        std::queue<int> q;
        distBFS[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto w : g.ady(v)) {
                if (!visit[w.hasta()]) {
                    distBFS[w.hasta()] = distBFS[v] + 1; visit[w.hasta()] = true;
                    q.push(w.hasta());
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
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

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> v >> w;
        --v; --w;
        Dijkstra<int> dj(dgv, v);
        if (dj.hayCamino(w)) {
            cout << dj.distancia(w);
            int calles = dj.camino(w).size();
            if (dj.masCorto(w) == calles) cout << " SI";
            else cout << " NO";
        }
        else
            cout << "SIN CAMINO";
        cout << '\n';
    }
    cout << "---\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

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
