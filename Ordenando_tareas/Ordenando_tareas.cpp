
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "CicloDirigido.h"
#include "OrdenTopologico.h"
//#include "Ordenando.h"
//#include "BFSDirigido.h"
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
    int N;
    // leer los datos de la entrada
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;
    Digrafo g(N);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int v, w;
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    // resolver el caso posiblemente llamando a otras funciones
    //OrdenTopologico ot(g);
    CicloDirigido cd(g);
    OrdenTopologico bfs(g);
    if (!cd.hayCiclo()) {
        for (auto e : bfs.orden()) {
            cout << e + 1 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "Imposible\n";
    }
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
