
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <climits>
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

struct comp
{
public:
    bool operator()(const stack<int>& a, const stack<int>& b) const {
        return a.top() > b.top();
    };
};

int turno(priority_queue<stack<int>, vector<stack<int>>, comp>& pq, int min) {
    int i = 1;
    stack<int> a;
    int aux;
    do
    {
        a = pq.top(); pq.pop();
        aux = a.top();
        if (aux == min) return i;

        a.pop();
        if(!a.empty())
            pq.push(a);
        ++i;
    } while (aux != min);

    return i;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int nComics;
    int min = INT_MAX;
    priority_queue<stack<int>, vector<stack<int>>, comp> pq;
    for (int i = 0; i < N; ++i) {
        cin >> nComics;
        int aux;
        stack<int> sAux;
        for (int j = 0; j < nComics; ++j) {
            cin >> aux;
            if (aux < min)
                min = aux;
            sAux.push(aux);
        }
        pq.push(sAux);
    }

    cout << turno(pq, min) << '\n';

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
