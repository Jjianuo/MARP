/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * MARP16 Pedro Leon Miranda
  * MARP48 Jianuo Wen Hu
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

#include "IndexPQ.h"

using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 Se utiliza una cola de prioridades variables para **ordenar y almacenar el tema**, el numero de citas y el tiempo (que va indicado por el indice del bucle) 
 en el que se han actualizado por ultima vez.
 Siendo el mas prioritario el que mas numero de citas tenga. Se utiliza ademas un unordered_map auxiliar que guarda el tema y ayuda a actualizar el numero de citas 
 para poder acceder al valor de cada tema facilmente.

 O(N log N) donde N es el numero de eventos

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

struct prio {
    int prioridad;
    int reciente;
public:
    bool operator <(const prio& other) const {
        return prioridad < other.prioridad || (prioridad == other.prioridad && reciente < other.reciente);
    }

    bool operator >(const prio& other) const {
        return other < *this;
    }
};

bool resuelveCaso() {

    int numEventos;
    cin >> numEventos;

    if (!cin)
        return false;

    IndexPQ<string, prio, greater<prio>> masCitados;
    unordered_map<string, int> temas;
    // leer el resto del caso y resolverlo
    for (int i = 0; i < numEventos; ++i) {
        string operacion;
        cin >> operacion;
        string tema;
        int citas;
        if (operacion == "C") {
            cin >> tema >> citas;
            temas[tema] += citas;
            masCitados.update(tema, { temas[tema], i });
        }
        else if (operacion == "E") {
            cin >> tema >> citas;
            temas[tema] -= citas;
            masCitados.update(tema, { temas[tema], i });
        }
        else if (operacion == "TC") {
            int j = 0;
            int max = 3;
            vector<pair<string, prio>> aux;
            while (!masCitados.empty() && j < max) {
                auto a = masCitados.top(); masCitados.pop();
                cout << (j + 1) << " " << a.elem << "\n";
                aux.push_back({ a.elem, {a.prioridad.prioridad, a.prioridad.reciente} });
                ++j;
            }
            for (auto e : aux)
                masCitados.push(e.first, e.second);
        }
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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
