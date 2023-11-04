/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Jianuo Wen
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "TreeSet_AVL_tami.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema.

 Se ha aniadido la variable tam_i.
 Se ha modificado rotaIz, rota_dr e inserta para que se mantenga correcto el valor de tam_i en cada cambio de arbol
 La operacion kesimo pasa el valor de k como variable. Si el valor de k es menor que el valor tam_i del arbol se busca por la rama izquierda.
 Si el valor de k es mayor que el valor tam_i del arbol se busca por la rama derecha, ademas se le resta a k el valor de tam_i para buscar el numero kesimo del arbol derecho
 El coste es O(log n) donde n es el numero de nodos

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0)
        return false;

    // los valores de la entrada se insertan en el conjunto
    Set<int> cjto;
    int valor;
    for (int i = 0; i < N; ++i) {
        cin >> valor;
        cjto.insert(valor);
    }

    // COMPLETAR
    cin >> N;
    for (int i = 0; i < N; ++i) {
        try {
            cin >> valor;
            int out = cjto.kesimo(valor);
            cout << out;
        }
        catch (std::out_of_range& e) {
            cout << e.what();
        }
        cout << endl;
    }
    cout << "---\n";

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

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
