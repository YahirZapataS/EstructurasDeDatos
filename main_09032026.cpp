#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    // Tamaño del subArreglo izquierdo
    int n1 = mid - left + 1;
    // Tamaño del subArreglo derecho
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + j + 1];
    }

    // i recorrer L, j recorrer R, k recorrer arr
    int i = 0, j = 0, k = left;
    // Comparar L con R
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Guardar valores restantes L
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return;
};

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + ((right - left) / 2);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    cout << "L: " << left << " R: " << right << " mid: " << mid << endl;
    merge(arr, left, mid, right);
};

int main()
{
    // Vector a ordenar
    vector<int> arr = {70, 30, 50, 10, 70, 30, 50, 10};

    // Tamaño del arreglo
    int n = arr.size(); // n = 4

    mergeSort(arr, 0, n - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}