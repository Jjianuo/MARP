
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

#include "Conectados.h"

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
    int n, m;
    cin >> n >> m;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(n);

    for (int i = 0; i < m; ++i) {
        int in; //tamanio del grupo
        cin >> in;
        if (in > 0) {
            int v;
            cin >> v;
            for (int j = 0; j < in - 1; ++j) {
                int w;
                cin >> w;
                g.ponArista(v - 1, w - 1);
            }
        }
    }

    Conectados c(g, 0);

    for (auto f : c.frennns()) {
        cout << f << " ";
    }
    cout << "\n";
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
