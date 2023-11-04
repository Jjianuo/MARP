
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 O(N * K * (log(n1) + log(n2))
 N es el numero de vuelos que se pueden hacer con las pilas
 K es el numero de drones
 n1 es el numero de pilas del primer tipo
 n2 es el numero de pilas del segundo tipo

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int nDrones;
    cin >> nDrones;
    if (!std::cin)  // fin de la entrada
        return false;
    int nPilas1, nPilas2;
    cin >> nPilas1 >> nPilas2;
    priority_queue<int> p1;
    priority_queue<int> p2;
    int n;
    for (int i = 0; i < nPilas1; ++i) {
        cin >> n;
        p1.push(n);
    }
    for (int i = 0; i < nPilas2; ++i) {
        cin >> n;
        p2.push(n);
    }
    // resolver el caso posiblemente llamando a otras funciones
    while (!p1.empty() && !p2.empty()) {
        int acu = 0;
        int pila1, pila2;
        int i = 0;
        vector<int> usadas1;
        vector<int> usadas2;
        while (!p1.empty() && !p2.empty() && i < nDrones) {
            pila1 = p1.top(); p1.pop();
            pila2 = p2.top(); p2.pop();
            if (pila1 < pila2) {
                acu += pila1;
                pila2 -= pila1;
                usadas2.push_back(pila2);
            }
            else if (pila2 < pila1) {
                acu += pila2;
                pila1 -= pila2;
                usadas1.push_back(pila1);
            }
            else acu += pila1;
            ++i;
        }
        while (usadas1.size() > 0) {
            p1.push(usadas1.back());
            usadas1.pop_back();
        }
        while (usadas2.size() > 0) {
            p2.push(usadas2.back());
            usadas2.pop_back();
        }
        cout << acu << " ";
    }
    // escribir la soluci�n
    cout << '\n';
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
