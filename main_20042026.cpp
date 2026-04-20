#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertar(Nodo*& inicio, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = inicio;
    inicio = nuevo;
}

int sumarLista(Nodo* inicio) {
    int suma = 0;
    Nodo* actual = inicio;
    
    while (actual != nullptr) {
        suma += actual->dato;
        actual = actual->siguiente;
    }
    
    return suma;
}



// --------------------------------------------------------- //

// Retornar el valor maximo y el valor minimo de la lista

int valorMaximoLista(Nodo* inicio) {
    if (inicio == nullptr) return -1;

    int max = inicio->dato;
    Nodo* actual = inicio->siguiente;

    while (actual != nullptr) {
        if (actual->dato > max) {
            max = actual->dato;
        }
        actual = actual->siguiente;
    }
    return max;
}

int valorMinimoLista(Nodo* inicio){
    if (inicio == nullptr) return -1;

    int min = inicio->dato;
    Nodo* actual = inicio->siguiente;

    while (actual != nullptr) {
        if (actual->dato < min) {
            min = actual->dato;
        }
        actual = actual->siguiente;
    }
    return min;
}

// --------------------------------------------------------- //

int main() {
    Nodo* lista = nullptr;

    insertar(lista, 70);
    insertar(lista, 20);
    insertar(lista, 71);
    insertar(lista, 516);

    cout << "La suma es: " << sumarLista(lista) << endl;
    cout << "Max: " << valorMaximoLista(lista) << endl;
    cout << "Min: " << valorMinimoLista(lista) << endl;

    return 0;
}