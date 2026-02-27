#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Alumno
{
    int matricula;
    string nombre;
    double promedio;
};

int buscarPorMatricula(vector<Alumno>& grupo, int matricula) {
    for (int i = 0; i < grupo.size(); i++)
    {
        if (grupo[i].matricula == matricula) {
            return i;
        }
    }

    return -1;
    
}

bool agregarAlumno(vector<Alumno>& grupo, const Alumno& alumno) {
    if(buscarPorMatricula(grupo, alumno.matricula) != -1){
        return false;
    }
    grupo.push_back(alumno);
    return true;
}

int main()
{
    int opcion;
    vector<Alumno> grupo;

    do
    {

        cout << "\n---------------------------";
        cout << "\nMenú - vector<Alumno>";
        cout << "\n---------------------------";
        cout << "\n1) Agregar alumno\n2) Mostrar alumnos\n3) Buscar alumno por matrícula" << "\n4) Actualizar alumno\n5) Eliminar alumno\n6) Ordenar por promedio(desc)\n7) Ordenar por promedio (asc)" << "\n8) Calcular promedio del grupo\n0) Salir\nSelecciona una opción: \n";
        cin >> opcion;

        Alumno tem_alumno;

        if (opcion == 1) {
            Alumno tem_alumno;
            cout << "Ingresar matricula: ";
            cin >> tem_alumno.matricula;
            cin.ignore();
            cout << "Ingresar nombre: ";
            getline(cin, tem_alumno.nombre);
            cout << "Ingresar promedio: ";
            cin >> tem_alumno.promedio;

            if (agregarAlumno(grupo, tem_alumno)) {
                cout << "Alumno agregado correctamente\n";
            } else {
                cout << "Error: matricula existente\n";
            }
        } else if (opcion == 2) {
        }
    } while (opcion != 0);
    return 0;
}