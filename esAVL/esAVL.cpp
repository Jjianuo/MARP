
/*@ <answer>
 *
 * Nombre y Apellidos: Jianuo Wen MARP48
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

// propios o los de las estructuras de datos de clase
#include "bintree.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool esBinario(int r, int i, int d) {
    return i < r && r < d;
}

//bool resuelve(const BinTree<int>& tree, int& h, int iz, int dr) {
//    if (tree.empty()) {
//        h = 0;
//        return true;
//    }
//    int hiz, hdr, maxiz, mindr;
//    hiz = hdr = -1;
//    bool riz = resuelve(tree.left(), hiz, iz, tree.root());
//    bool rdr = resuelve(tree.right(), hdr, tree.root(), dr);
//    
//    h = max(hiz, hdr);
//    ++h;
//    return riz && rdr && (abs(hiz - hdr) < 2) && esBinario(tree.root(), iz, dr);
//}

template <typename T>
bool resuelve(const BinTree<T>& tree, int& h, T& mi, T& ma) {
    //si el arbol esta vacio
    if (tree.empty()) {
        h = 0;
        return true; 
    }
    //si el arbol es una hoja
    if (tree.left().empty() && tree.right().empty()){
        h = 1;
        mi = ma = tree.root(); 
        return true;
    }
    //recursion
    int hiz, hdr;
    T miniz, maxiz, mindr, maxdr;

    bool riz = resuelve(tree.left(), hiz, miniz, maxiz);
    bool rdr = resuelve(tree.right(), hdr, mindr, maxdr);

    //para comprobar si es binario
    bool binario = ((tree.left().empty() || maxiz < tree.root()) && (tree.right().empty() || mindr > tree.root()));

    //para determinar la altura de la rama
    h = max(hiz, hdr);
    ++h;

    //para determinar el minimo y el maximo del arbol
    mi = miniz;
    ma = maxdr; 
    if (tree.left().empty()) mi = tree.root();
    if (tree.right().empty()) ma = tree.root();

    return riz && rdr && (abs(hiz - hdr) < 2) && binario;
}

bool resuelveCaso() {
    char tipo;
    cin >> tipo;

    if (!std::cin)  // fin de la entrada
        return false;

    if (tipo == 'N') {
        // leer los datos de la entrada
        BinTree<int> tree = read_tree<int>(cin);
        // resolver el caso posiblemente llamando a otras funciones
        // escribir la solución
        int h = 0;
        int mi, ma;

        cout << (resuelve(tree, h, mi, ma) ? "SI" : "NO") << endl;
    }
    else {
        BinTree<string> tree = read_tree<string>(cin);
        int h = 0;
        string mi, ma;

        cout << (resuelve(tree, h, mi, ma) ? "SI" : "NO") << endl;
    }

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
