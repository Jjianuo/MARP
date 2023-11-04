
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <math.h>
#include "BFSDirigido.h"
using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 O(N*N*K) donde N es el tamanio del tablero y K es el tamanio del dado

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int N, K, S, E;
    // leer los datos de la entrada
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    Digrafo g(N * N);
    int v, w;
    for (int i = 0; i < S; ++i) {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    for (int i = 0; i < E; ++i) {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    for (int i = 0; i < N*N; ++i) {
        if (g.ady(i).size() < 1) {
            for (int j = 1; j <= K; ++j) { 
                int sig = i + j;
                if (sig < N * N) {
                    if (g.ady(sig).size() > 0) //es una escalera
                        g.ponArista(i, g.ady(sig).front());
                    else
                        g.ponArista(i, sig);
                }
            }
        }
    }
    // escribir la soluci�n
    BFSDirigido bfs(g, 0);
    Camino c = bfs.camino((N * N) - 1);

    cout << c.size() - 1<< "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
