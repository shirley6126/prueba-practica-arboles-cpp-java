//  PRUEBA PRÁCTICA - ÁRBOLES BINARIOS DE BÚSQUEDA EN C++
#include <iostream>
#include <queue>      // Necesaria para el recorrido BFS por niveles
#include <string>
#include <iomanip>    // formatea la salida con setprecision
#include <limits>     // limpia el buffer del cin
using namespace std;

// ESTRUCTURA ESTUDIANTE
// guarda toda la info de un estudiante de la UTA
struct Estudiante {
    string cedula;      // clave principal del árbol (por aquí se ordena)
    string apellidos;
    string nombres;
    float  notaFinal;   // nota sobre 10
    string carrera;
    string nivel;       // por ejemplo "Tercer Semestre"
};

// NODO DEL ÁRBOL
// cada nodo guarda un estudiante y dos punteros a sus hijos
struct Nodo {
    Estudiante dato;    // la info del estudiante dentro del nodo
    Nodo* izquierdo;    // hijo izquierdo (cédulas menores)
    Nodo* derecho;      // hijo derecho  (cédulas mayores)

    // Constructor: cuando creo un nodo nuevo arranco los hijos en null
    Nodo(Estudiante e) {
        dato       = e;
        izquierdo  = nullptr;
        derecho    = nullptr;
    }
};

// CLASE ArbolBST
// acá viven todas las operaciones del árbol
class ArbolBST {

private:
    Nodo* raiz;   // puntero al nodo raíz del árbol

    // Inserta un nodo de forma recursiva
    // compara cédulas: si la nueva es menor va a la izquierda, si es mayor a la derecha
    Nodo* insertar(Nodo* nodo, Estudiante e) {
        if (nodo == nullptr) {
            // llegué a un lugar vacío: acá pongo el nuevo nodo
            return new Nodo(e);
        }
        if (e.cedula < nodo->dato.cedula) {
            nodo->izquierdo = insertar(nodo->izquierdo, e);
        } else if (e.cedula > nodo->dato.cedula) {
            nodo->derecho = insertar(nodo->derecho, e);
        } else {
            // si la cédula ya existe no inserto duplicados
            cout << "\n[!] Ya existe un estudiante con la cedula " << e.cedula << endl;
        }
        return nodo;
    }

    // Busca un nodo por cédula y devuelve su puntero (o null si no está)
    Nodo* buscar(Nodo* nodo, string cedula) {
        if (nodo == nullptr) return nullptr;         
        if (cedula == nodo->dato.cedula) return nodo;

        if (cedula < nodo->dato.cedula)
            return buscar(nodo->izquierdo, cedula);
        return buscar(nodo->derecho, cedula);
    }

    // Encuentra el nodo con la cédula más pequeña en un subárbol
    // lo uso para la eliminación (buscar sucesor inorden)
    Nodo* minimoNodo(Nodo* nodo) {
        while (nodo->izquierdo != nullptr)
            nodo = nodo->izquierdo;
        return nodo;
    }

    // Elimina un nodo del árbol con los 3 casos clásicos
    Nodo* eliminar(Nodo* nodo, string cedula) {
        if (nodo == nullptr) return nullptr;

        if (cedula < nodo->dato.cedula) {
            nodo->izquierdo = eliminar(nodo->izquierdo, cedula);
        } else if (cedula > nodo->dato.cedula) {
            nodo->derecho = eliminar(nodo->derecho, cedula);
        } else {
            // Caso 1: nodo hoja (sin hijos) - simplemente lo borro
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                delete nodo;
                return nullptr;
            }
            // Caso 2: solo tiene hijo derecho
            else if (nodo->izquierdo == nullptr) {
                Nodo* temp = nodo->derecho;
                delete nodo;
                return temp;
            }
            // Caso 2b: solo tiene hijo izquierdo
            else if (nodo->derecho == nullptr) {
                Nodo* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }
            // Caso 3: tiene dos hijos
            // busco el sucesor inorden
            else {
                Nodo* sucesor = minimoNodo(nodo->derecho);
                nodo->dato    = sucesor->dato;
                nodo->derecho = eliminar(nodo->derecho, sucesor->dato.cedula);
            }
        }
        return nodo;
    }

    // RECORRIDO INORDEN: izquierda → raíz → derecha
    // resultado: estudiantes ordenados por cédula de menor a mayor
    void inorden(Nodo* nodo) {
        if (nodo == nullptr) return;
        inorden(nodo->izquierdo);
        imprimirEstudiante(nodo->dato);
        inorden(nodo->derecho);
    }

    // RECORRIDO PREORDEN: raíz → izquierda → derecha
    // resultado: empieza desde la raíz y baja
    void preorden(Nodo* nodo) {
        if (nodo == nullptr) return;
        imprimirEstudiante(nodo->dato);
        preorden(nodo->izquierdo);
        preorden(nodo->derecho);
    }

    // RECORRIDO POSTORDEN: izquierda → derecha → raíz
    // resultado: la raíz sale al último
    void postorden(Nodo* nodo) {
        if (nodo == nullptr) return;
        postorden(nodo->izquierdo);
        postorden(nodo->derecho);
        imprimirEstudiante(nodo->dato);
    }

    // Cuenta todos los nodos del árbol recursivamente
    int contarNodos(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        // cuento este nodo más todos los del subárbol izq y der
        return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
    }

    // Calcula la altura del árbol 
    int calcularAltura(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int altIzq = calcularAltura(nodo->izquierdo);
        int altDer = calcularAltura(nodo->derecho);
        // la altura es 1 + el máximo de las dos ramas
        return 1 + max(altIzq, altDer);
    }

    // Recorre todo el árbol buscando la nota más alta
    void buscarNotaMayor(Nodo* nodo, Nodo*& mayor) {
        if (nodo == nullptr) return;
        if (mayor == nullptr || nodo->dato.notaFinal > mayor->dato.notaFinal)
            mayor = nodo;
        buscarNotaMayor(nodo->izquierdo, mayor);
        buscarNotaMayor(nodo->derecho, mayor);
    }

    // Recorre todo el árbol buscando la nota más baja
    void buscarNotaMenor(Nodo* nodo, Nodo*& menor) {
        if (nodo == nullptr) return;
        if (menor == nullptr || nodo->dato.notaFinal < menor->dato.notaFinal)
            menor = nodo;
        buscarNotaMenor(nodo->izquierdo, menor);
        buscarNotaMenor(nodo->derecho, menor);
    }

    // Muestra solo los que tienen nota >= 7 (aprobados)
    void mostrarAprobados(Nodo* nodo) {
        if (nodo == nullptr) return;
        mostrarAprobados(nodo->izquierdo);
        if (nodo->dato.notaFinal >= 7.0f)
            imprimirEstudiante(nodo->dato);
        mostrarAprobados(nodo->derecho);
    }

    // Muestra solo los que tienen nota < 7 (reprobados)
    void mostrarReprobados(Nodo* nodo) {
        if (nodo == nullptr) return;
        mostrarReprobados(nodo->izquierdo);
        if (nodo->dato.notaFinal < 7.0f)
            imprimirEstudiante(nodo->dato);
        mostrarReprobados(nodo->derecho);
    }

public:
    // Constructor: el árbol empieza vacío
    ArbolBST() { raiz = nullptr; }

 
    void imprimirEstudiante(const Estudiante& e) {
        cout << "  +----------------------------------+" << endl;
        cout << "  | Cedula   : " << left << setw(22) << e.cedula    << "|" << endl;
        cout << "  | Apellidos: " << left << setw(22) << e.apellidos  << "|" << endl;
        cout << "  | Nombres  : " << left << setw(22) << e.nombres    << "|" << endl;
        cout << "  | Nota     : " << left << setw(22) << fixed << setprecision(2) << e.notaFinal << "|" << endl;
        cout << "  | Carrera  : " << left << setw(22) << e.carrera    << "|" << endl;
        cout << "  | Nivel    : " << left << setw(22) << e.nivel      << "|" << endl;
        cout << "  +----------------------------------+" << endl;
    }

   

    void insertarEstudiante(Estudiante e) {
        raiz = insertar(raiz, e);
        cout << "\n Estudiante insertado correctamente." << endl;
    }

    void buscarEstudiante(string cedula) {
        Nodo* resultado = buscar(raiz, cedula);
        if (resultado != nullptr) {
            cout << "\nEstudiante encontrado:" << endl;
            imprimirEstudiante(resultado->dato);
        } else {
            cout << "\n No se encontro estudiante con cedula: " << cedula << endl;
        }
    }

    void eliminarEstudiante(string cedula) {
        // primero verifico que exista antes de intentar borrar
        if (buscar(raiz, cedula) == nullptr) {
            cout << "\n No existe un estudiante con esa cedula." << endl;
            return;
        }
        raiz = eliminar(raiz, cedula);
        cout << "\n Estudiante eliminado." << endl;
    }

    void recorridoInorden() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        cout << "\n===== RECORRIDO INORDEN (izq - raiz - der) =====" << endl;
        cout << "  Resultado: cedulas de menor a mayor" << endl;
        inorden(raiz);
    }

    void recorridoPreorden() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        cout << "\n===== RECORRIDO PREORDEN (raiz - izq - der) =====" << endl;
        cout << "  Resultado: empieza desde la raiz" << endl;
        preorden(raiz);
    }

    void recorridoPostorden() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        cout << "\n===== RECORRIDO POSTORDEN (izq - der - raiz) =====" << endl;
        cout << "  Resultado: la raiz sale al final" << endl;
        postorden(raiz);
    }

    // BFS: uso una cola (queue) para ir procesando nodo por nodo en cada nivel
    void recorridoPorNiveles() {
        if (raiz == nullptr) { cout << "\nEl arbol esta vacio." << endl; return; }
        cout << "\n===== RECORRIDO POR NIVELES - BFS =====" << endl;

        queue<Nodo*> cola;  // la cola guarda los nodos pendientes de visitar
        cola.push(raiz);    // arranco con la raíz
        int nivel = 1;

        while (!cola.empty()) {
            // proceso todos los nodos del nivel actual antes de bajar al siguiente
            int tamañoNivel = (int)cola.size();
            cout << "\n  --- Nivel " << nivel << " ---" << endl;

            for (int i = 0; i < tamañoNivel; i++) {
                Nodo* actual = cola.front();
                cola.pop();
                imprimirEstudiante(actual->dato);

                // agrego los hijos a la cola para procesarlos en el siguiente nivel
                if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
                if (actual->derecho   != nullptr) cola.push(actual->derecho);
            }
            nivel++;
        }
    }

    void contarNodos() {
        int total = contarNodos(raiz);
        cout << "\n  Total de estudiantes en el arbol: " << total << endl;
    }

    void calcularAltura() {
        int h = calcularAltura(raiz);
        cout << "\n  Altura del arbol: " << h << " nivel(es)" << endl;
    }

    void buscarNotaMayor() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        Nodo* mayor = nullptr;
        buscarNotaMayor(raiz, mayor);
        cout << "\n  Estudiante con la nota MAS ALTA:" << endl;
        imprimirEstudiante(mayor->dato);
    }

    void buscarNotaMenor() {
        if (raiz == nullptr) { cout << "\nEl arbol esta vacio." << endl; return; }
        Nodo* menor = nullptr;
        buscarNotaMenor(raiz, menor);
        cout << "\n  Estudiante con la nota MAS BAJA:" << endl;
        imprimirEstudiante(menor->dato);
    }

    void mostrarAprobados() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        cout << "\n===== ESTUDIANTES APROBADOS (nota >= 7) =====" << endl;
        mostrarAprobados(raiz);
    }

    void mostrarReprobados() {
        if (raiz == nullptr) { cout << "\n El arbol esta vacio." << endl; return; }
        cout << "\n===== ESTUDIANTES REPROBADOS (nota < 7) =====" << endl;
        mostrarReprobados(raiz);
    }
};

// ==================================================================
// FUNCIONES DE UTILIDAD PARA EL MENÚ
// ==================================================================

// Limpia el buffer de entrada (sirve para evitar que cin se trabe)
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Muestra el menú principal y retorna la opción elegida
int mostrarMenu() {
    int opcion;
    cout << "\n+--------------------------------------+" << endl;
    cout << "    SISTEMA ACADEMICO - ARBOL BST        " << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "  1.  Insertar estudiante             " << endl;
    cout << "  2.  Buscar estudiante por cedula    " << endl;
    cout << "  3.  Eliminar estudiante             " << endl;
    cout << "  4.  Recorrido Inorden               " << endl;
    cout << "  5.  Recorrido Preorden              " << endl;
    cout << "  6.  Recorrido Postorden             " << endl;
    cout << "  7.  Recorrido por niveles (BFS)     " << endl;
    cout << "  8.  Contar estudiantes              " << endl;
    cout << "  9.  Calcular altura del arbol       " << endl;
    cout << " 10.  Estudiante con mayor nota       " << endl;
    cout << " 11.  Estudiante con menor nota       " << endl;
    cout << " 12.  Mostrar aprobados               " << endl;
    cout << " 13.  Mostrar reprobados              " << endl;
    cout << " 14.  Salir                           " << endl;
    cout << "  Seleccione una opcion: ";
    cin >> opcion;
    limpiarBuffer();
    return opcion;
}

// Pide los datos de un estudiante al usuario con validaciones básicas
Estudiante pedirDatosEstudiante() {
    Estudiante e;

    cout << "\n  Ingrese cedula (10 digitos): ";
    cin >> e.cedula;
    limpiarBuffer();

    // Validación simple: la cédula debe tener 10 caracteres
    while (e.cedula.length() != 10) {
        cout << "  Cedula invalida. Ingrese nuevamente: ";
        cin >> e.cedula;
        limpiarBuffer();
    }

    cout << "  Ingrese apellidos: ";
    getline(cin, e.apellidos);

    cout << "  Ingrese nombres: ";
    getline(cin, e.nombres);

    cout << "  Ingrese nota final (0 a 10): ";
    cin >> e.notaFinal;
    limpiarBuffer();

    // Validación de nota entre 0 y 10
    while (e.notaFinal < 0 || e.notaFinal > 10) {
        cout << "  Nota invalida. Ingrese entre 0 y 10: ";
        cin >> e.notaFinal;
        limpiarBuffer();
    }

    cout << "  Ingrese carrera: ";
    getline(cin, e.carrera);

    cout << "  Ingrese nivel (ej: Tercer Semestre): ";
    getline(cin, e.nivel);

    return e;
}

// FUNCIÓN PRINCIPAL
int main() {
    ArbolBST arbol;  // creo el árbol vacío

    // datos de ejemplo 
    Estudiante e1 = {"1804500001", "Amaguana Villacres",    "Shirley Dayana", 8.5f, "Sistemas",    "Tercer Semestre"};
    Estudiante e2 = {"1804500003", "Garcia Torres",  "Maria Jose",    6.0f, "Industrial",  "Quinto Semestre"};

    arbol.insertarEstudiante(e1);
    arbol.insertarEstudiante(e2);

    cout << "\nSe cargaron 2 estudiantes de ejemplo al inicio." << endl;

    int opcion;
    do {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1: {
                Estudiante nuevo = pedirDatosEstudiante();
                arbol.insertarEstudiante(nuevo);
                break;
            }
            case 2: {
                string cedula;
                cout << "\n  Ingrese cedula a buscar: ";
                cin >> cedula;
                limpiarBuffer();
                arbol.buscarEstudiante(cedula);
                break;
            }
            case 3: {
                string cedula;
                cout << "\n  Ingrese cedula a eliminar: ";
                cin >> cedula;
                limpiarBuffer();
                arbol.eliminarEstudiante(cedula);
                break;
            }
            case 4:  arbol.recorridoInorden();     break;
            case 5:  arbol.recorridoPreorden();    break;
            case 6:  arbol.recorridoPostorden();   break;
            case 7:  arbol.recorridoPorNiveles();  break;
            case 8:  arbol.contarNodos();          break;
            case 9:  arbol.calcularAltura();       break;
            case 10: arbol.buscarNotaMayor();      break;
            case 11: arbol.buscarNotaMenor();      break;
            case 12: arbol.mostrarAprobados();     break;
            case 13: arbol.mostrarReprobados();    break;
            case 14:
                cout << "\n  Hasta luego\n" << endl;
                break;
            default:
                cout << "\n Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 14);

    return 0;
}