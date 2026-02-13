#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "--- Creación de vectores ---" << endl;
    vector<int> v1;

    // Vector definido
    vector<int> v2[5];

    // Vector con tamaño y valor de todo el vector
    vector<int> v3(5, 10);

    // Vector con valores iniciales
    vector<int> v4{1, 2, 3, 4, 5};

    // Copia a un vector
    vector<int> copia = v4;

    // Imprimir un vector
    cout << "Vector V4";
    for (int x : v4)
        cout << x << endl;

    // Acceder a los elementos de un vector
    cout << "--- Acceder a los elementos del vector ---" << endl;
    cout << "Acceder a la posición 2 del vector v4" << v4[2] << endl;
    cout << "Primer elemento del vector v4 " << v4.front() << endl;
    cout << "Ultimo elemento del vector v4 " << v4.back() << endl;

    // Modificar elementos de un vector
    cout << "Modificar elementos de un vector " << endl;
    v4[0] == 100;

    // Agregar valor al final
    v4.push_back(50);

    // Insertar un valor en una posición especifica.
    v4.insert(v4.begin() + 2, 99);

    cout << "Vector V4 " << endl;
    for (int x : v4)
        cout << x << endl;

    // Eliminar por rango
    v4.erase(v4.begin(), v4.begin() + 3);

    cout << "Vector V4 " << endl;
    for (int x : v4)
        cout << x << endl;

    cout << "--- Obtener información del vector ---" << endl;
    cout << "Tamaño del vector: " << v4.size() << endl;
    cout << "Capacidad del vector: " << v4.capacity() << endl;
    cout << "---------------------------------------" << endl;
    cout << "¿El vector está vacío?: " << (v4.empty() ? "Si" : "No") << endl;


    cout << "--- Control de memoria ---" << endl;
    v4.reserve(100);
    cout << "Capacidad del vector: " << v4.capacity() << endl;

    //Recorrer el vector
    for (int i = 0; i < v2->size(); i++)
    {
        cout << v4[i] << endl;
    }

    //Ordenar
    cout <<  "" << "--- Algoritmos ---" << endl;
    vector<int> datos = {9, 3, 4, 10, 8, 4};

    sort(datos.begin(), datos.end());

    cout << "Vector ordenado" << endl;
    for (int x : datos) cout << x << endl;
    cout << endl;
}