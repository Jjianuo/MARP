
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 Coste de N log (N/2) donde N es el numeros de pajaros que se aniaden a la bandada

 Se guarda en un int el pajaro que esta en la mitad, y se usan dos colas de prioridad para conseguir el pajaro con edad mas grande de los que son menores y viceversa
 Se comprueba si las dos colas no son del mismo tamanio se equilibran pasando la mitad a la cola mas pequnia y asignando el top de la cola mas grande a la mitad
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    priority_queue<int> menores;
    int mitad = n;
    priority_queue<int, vector<int>, greater<int>> mayores;
    // escribir la soluci�n
    int p1, p2;
    for (int i = 0; i < p; ++i) {
        cin >> p1 >> p2;
        if (p1 < mitad)
            menores.push(p1);
        else mayores.push(p1);
        if (p2 < mitad)
            menores.push(p2);
        else mayores.push(p2);

        if (menores.size() < mayores.size()) {
            menores.push(mitad);
            mitad = mayores.top(); mayores.pop();
        }
        else if (mayores.size() < menores.size()) {
            mayores.push(mitad);
            mitad = menores.top(); menores.pop();
        }
        cout << mitad << " ";
    }
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
