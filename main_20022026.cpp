#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Alumno
{
    int matricula;
    string nombre;
    double promedio;
};

int buscarPorMatricula(vector<Alumno> &grupo, int matricula)
{
    for (int i = 0; i < grupo.size(); i++)
    {
        if (grupo[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
}

bool agregarAlumno(vector<Alumno> &grupo, const Alumno &alumno)
{
    if (buscarPorMatricula(grupo, alumno.matricula) != -1)
    {
        return false;
    }
    grupo.push_back(alumno);
    return true;
}

void mostrarAlumnos(const vector<Alumno> &grupo)
{
    cout << "\n--- Lista de Alumnos ---" << endl;
    for (int i = 0; i < grupo.size(); i++)
    {
        cout << "Matricula: " << grupo[i].matricula
            << " | Nombre: " << grupo[i].nombre
            << " | Promedio: " << grupo[i].promedio << endl;
    }
}

void actualizarAlumno(vector<Alumno> &grupo, int matricula)
{
    int indice = buscarPorMatricula(grupo, matricula);
    if (indice != -1)
    {
        cout << "Nuevo nombre: ";
        cin.ignore();
        getline(cin, grupo[indice].nombre);
        cout << "Nuevo promedio: ";
        cin >> grupo[indice].promedio;
        cout << "Alumno actualizado con exito." << endl;
    }
    else
    {
        cout << "Error: No se encontro la matricula." << endl;
    }
}

void eliminarAlumno(vector<Alumno> &grupo, int matricula)
{
    int indice = buscarPorMatricula(grupo, matricula);
    if (indice != -1)
    {
        grupo.erase(grupo.begin() + indice);
        cout << "Alumno eliminado." << endl;
    }
    else
    {
        cout << "Error: No se encontro la matricula." << endl;
    }
}

void ordenarPorPromedio(vector<Alumno> &grupo, bool descendente)
{
    for (int i = 0; i < (int)grupo.size() - 1; i++)
    {
        for (int j = 0; j < (int)grupo.size() - i - 1; j++)
        {
            bool condicion = descendente ? (grupo[j].promedio < grupo[j + 1].promedio)
                                        : (grupo[j].promedio > grupo[j + 1].promedio);
            if (condicion)
            {
                Alumno temp = grupo[j];
                grupo[j] = grupo[j + 1];
                grupo[j + 1] = temp;
            }
        }
    }
    cout << "Lista ordenada." << endl;
}

double calcularPromedioGrupo(const vector<Alumno> &grupo)
{
    if (grupo.empty())
        return 0.0;
    double suma = 0;
    for (int i = 0; i < grupo.size(); i++)
    {
        suma += grupo[i].promedio;
    }
    return suma / grupo.size();
}

int main()
{
    vector<Alumno> grupo;
    int opcion;

    do
    {
        cout << "\n========================\n";
        cout << "Menu - vector<Alumno>";
        cout << "\n========================\n";
        cout << "1) Agregar alumno\n2) Mostrar alumnos\n3) Buscar alumno\n";
        cout << "4) Actualizar alumno\n5) Eliminar alumno\n6) Ordenar (Desc)\n";
        cout << "7) Ordenar (Asc)\n8) Promedio grupal\n0) Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        int mat;
        switch (opcion)
        {
        case 1:
        {
            Alumno tem_alumno;
            cout << "Matricula: ";
            cin >> tem_alumno.matricula;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, tem_alumno.nombre);
            cout << "Promedio: ";
            cin >> tem_alumno.promedio;
            if (!agregarAlumno(grupo, tem_alumno))
                cout << "Error: Ya existe.\n";
            break;
        }
        case 2:
            mostrarAlumnos(grupo);
            break;
        case 3:
            cout << "Matricula a buscar: ";
            cin >> mat;
            if (buscarPorMatricula(grupo, mat) != -1)
                cout << "Alumno encontrado.\n";
            else
                cout << "No encontrado.\n";
            break;
        case 4:
            cout << "Matricula a actualizar: ";
            cin >> mat;
            actualizarAlumno(grupo, mat);
            break;
        case 5:
            cout << "Matricula a eliminar: ";
            cin >> mat;
            eliminarAlumno(grupo, mat);
            break;
        case 6:
            ordenarPorPromedio(grupo, true);
            break;
        case 7:
            ordenarPorPromedio(grupo, false);
            break;
        case 8:
            cout << "Promedio del grupo: " << calcularPromedioGrupo(grupo) << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}