
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Coste de N log (N/2) donde N es el numeros de pajaros que se aniaden a la bandada

 Se guarda en un int el pajaro que esta en la mitad, y se usan dos colas de prioridad para conseguir el pajaro con edad mas grande de los que son menores y viceversa
 Se comprueba si las dos colas no son del mismo tamanio se equilibran pasando la mitad a la cola mas pequnia y asignando el top de la cola mas grande a la mitad
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
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
    // escribir la solución
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
