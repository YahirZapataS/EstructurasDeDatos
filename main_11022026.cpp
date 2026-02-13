#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i * 10);
        cout << "Valor agregado: " << i * 10 << endl;
        cout << "Tamaño del vector: " << v.size() << endl;
        cout << "Capacidad del vector: " << v.capacity() << endl;
        cout << "---------------------------------------" << endl;
    }
    

    return 0;
}