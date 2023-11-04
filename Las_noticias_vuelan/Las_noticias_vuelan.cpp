
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

    // escribir la soluci�n

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
