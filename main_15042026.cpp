#include <iostream>
using namespace std;

struct Nodo
{
    int valor;
    Nodo *siguiente = nullptr;
};

class Lista
{
private:
    Nodo *inicio;

public:
    // constructor
    Lista()
    {
        inicio = NULL;
    }

    bool estaVacia()
    {
        return inicio == NULL;
    }

    void mostrarRecursivo(Nodo *nodo)
    {
        Nodo *aux = inicio;

        if (aux == NULL)
        {
            return;
        }
        cout << aux->valor << " ";
        aux = aux->siguiente;
        mostrarRecursivo(aux);
    }

    void mostrar()
    {
        Nodo *aux = inicio;

        while (aux != NULL)
        {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }

    void insertarInicio(int valor)
    {
        Nodo *nuevo = new Nodo();
        nuevo->valor = valor;
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }

    void insertarFinal(int valor)
    {
        Nodo *nuevo = new Nodo();
        nuevo->valor = valor;
        nuevo->siguiente = NULL;

        if (estaVacia())
        {
            inicio = nuevo;
            return;
        }

        Nodo *aux = inicio;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }

    void insertarAntesDe(int valor, int temp)
    {
        Nodo *nuevo = new Nodo();
        nuevo->valor = valor;

        Nodo *actual = inicio;
        Nodo *anterior = NULL;

        if (estaVacia())
        {
            cout << "Lista vacía." << endl;
            return;
        }

        while (actual != NULL && actual->valor != temp)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == NULL)
        {
            cout << "Valor no encontrado :(" << endl;
            return;
        }

        if (anterior == NULL)
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
        else
        {
            anterior->siguiente = nuevo;
            nuevo->siguiente = actual;
        }
    }

    void insertarDespuesDe(int valor, int temp)
    {
        Nodo *nuevo = new Nodo();
        nuevo->valor = valor;
        Nodo *actual = inicio;

        while (actual != NULL && actual->valor != temp)
        {
            actual = actual->siguiente;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;

        if (actual == NULL)
        {
            cout << "Valor no encontrado :(" << endl;
            return;
        }
    }

    void borrarInicio()
    {
        if (estaVacia())
        {
            cout << "Registro no existente." << endl;
            return;
        }
        Nodo *aux = inicio;
        inicio = inicio->siguiente;
        delete aux;
    }

    void borrarValor(int valor)
    {
        if (estaVacia())
        {
            cout << "Lista vacia :(" << endl;
            return;
        }

        Nodo *temp = new Nodo();
        Nodo *aux = new Nodo();
        aux->siguiente = temp->siguiente;
        delete temp;
    }

    void borrarUltimo()
    {
        if (estaVacia())
        {
            cout << "Lista vacia :(" << endl;
            return;
        }

        if (inicio == NULL)
            return;
        if (inicio->siguiente == NULL)
        {
            delete inicio;
            return;
        }

        Nodo *aux = inicio;

        while (aux->siguiente && aux->siguiente->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        delete aux->siguiente;
        aux->siguiente = NULL;
    }

    bool buscarNodo(int valor)
    {
        if (estaVacia())
        {
            cout << "Lista vacia :(" << endl;
        }

        Nodo *aux = inicio;
        while (aux != NULL && aux->valor != valor)
        {
            return true;
        }
        return false;
    }
};

void menu()
{
    cout << "=== LISTAS SIMPLEMENTE LIGADAS === " << endl;
    cout << "1. Insertar al inicio \n";
    cout << "2. Insertar al final \n";
    cout << "3. Insertar antes de \n";
    cout << "4. Insertar después de \n";
    cout << "5. Eliminar inicio \n";
    cout << "6. Eliminar valor \n ";
    cout << "7. Eliminar último \n";
    cout << "8. Buscar \n";
    cout << "9. Imprimir lista \n";
    cout << "10. Imprimir recursivo\n";
    cout << "0. Salir \n";
    cout << "Seleccione una opción... " << endl;
}

int main()
{
    int op, valor, temp;
    Lista lista;
    do
    {
        menu();
        cin >> op;

        if (op == 1)
        {
            cout << "Ingresa un valor... " << endl;
            cin >> valor;
            lista.insertarInicio(valor);
            // Ingresar a la lista.
        }
        else if (op == 2)
        {
            cout << "Ingresa un valor... " << endl;
            cin >> valor;
            lista.insertarFinal(valor);
            // Ingresar al final.
        }
        else if (op == 3)
        {
            lista.mostrar();
            cout << "Selecciona el valor donde quieres insertar antes de " << endl;
            cin >> temp;
            cout << "Ingresa el valor... " << endl;
            cin >> valor;
            lista.insertarAntesDe(valor, temp);
        }
        else if (op == 4)
        {
            lista.mostrar();
            cout << "Selecciona el valor donde quieres insertar despues de " << endl;
            cin >> temp;
            cout << "Ingresa el valor... " << endl;
            cin >> valor;
            lista.insertarDespuesDe(valor, temp);
        }
        else if (op == 5)
        {
            cout << "Borrar inicio" << endl;
            lista.borrarInicio();
        }
        else if (op == 6)
        {
            cout << "ingresa la posición del nodo: " << endl;
            cin >> valor;
            lista.borrarValor(valor);
            lista.mostrar();
        }
        else if (op == 7)
        {
            cout << "borrar último" << endl;
            lista.borrarUltimo();
        }
        else if (op == 8)
        {
            cout << "buscar nodo" << endl;
            cin >> valor;
            lista.buscarNodo(valor);

            if (lista.buscarNodo(valor) == false)
            {
                cout << "Valor no encontrado" << endl;
            }
            else
            {
                cout << "valor encontrado :)" << endl;
            }
        }
        else if (op == 9)
        {
            lista.mostrar();
        }
        else if (op == 10)
        {
            lista.mostrar();
        }
    } while (op != 0);

    return 0;
}