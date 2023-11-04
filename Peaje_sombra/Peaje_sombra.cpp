
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Peaje.h"
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, C, c1, c2, t;
    cin >> N >> C >> c1 >> c2 >> t;
    if (!std::cin)  // fin de la entrada
        return false;

    int v, w;
    Grafo g(N);
    for (int i = 0; i < C; ++i) {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }

    Peaje pc1(g, c1 - 1);
    Peaje pc2(g, c2 - 1);
    Peaje pct(g, t - 1);
    Camino camc1t = pc1.camino(t - 1); //camino de casa 1 al trabajo
    Camino camc2t = pc2.camino(t - 1); //camino de casa 2 al trabajo

    int aux;
    int costeMin = pc1.distancia(t - 1) + pc2.distancia(t - 1);
    int a, b, c;
    for (int i = 0; i < g.V(); ++i) {
        aux = pc1.distancia(i) + pc2.distancia(i) + pct.distancia(i);
        if (aux < costeMin)
            costeMin = aux;
    }


    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << costeMin << "\n";

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
