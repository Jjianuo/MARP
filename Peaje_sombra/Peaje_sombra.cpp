
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    cout << costeMin << "\n";

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
