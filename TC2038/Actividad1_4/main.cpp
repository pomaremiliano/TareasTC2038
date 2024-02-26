/*
Actividad 1.4
Nombre: Jorge Emiliano Pomar Mendoza

compilar: g++ main.cpp -o actividad1_4MergeSort
ejecutar: ./actividad1_4MergeSort
*/

#include <iostream>

void calculaMerge(int arr1[], int izq, int med, int der) // Junta de izquierda a la mitad y de la mitad a la derecha
{
    int n1 = med - izq + 1;
    int n2 = der - med;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr1[izq + i]; // Sub arreglo izquierdo temporal 
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr1[med + 1 + j]; // Sub arreglo derecho temporal
    }

    int i = 0;
    int j = 0;
    int k = izq;

    while (i < n1 && j < n2) // Compara los elemento en L  con R y los ordena
    {
        if (L[i] >= R[j]) // Ordena los numeros de mayor a menor
        {
            arr1[k] = L[i];
            i++;
        }
        else
        {
            arr1[k] = R[j];
            j++;
        }
        k++;
    } // Cuando se encuentra el menor, se agrega al arreglo y se aumenta el contador

    while (j < n2) // Agrega los elementos restantes de R y L al arreglo
    {
        arr1[k] = R[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        arr1[k] = L[i];
        i++;
        k++;
    }
}
// Complejidad O(n)

void mergeSort(int arr1[], int izq, int der) // Algoritmo merge Sort recursivo
{
    if (izq < der) // Si el arreglo es mayor a 1, se divide en dos 
    {
        int med = izq + (der - izq) / 2; // Aqui se divide el arreglo en dos y se calcula la mitad

        mergeSort(arr1, izq, med);
        mergeSort(arr1, med + 1, der);

        calculaMerge(arr1, izq, med, der); // Se juntan los dos arreglos
    }
}
// Complejidad O(n log n)

int main()
{
    int n;
    std::cout << "Ingrese el n del arreglo: "; // Se pide el tamaño del arreglo
    std::cin >> n;

    int arr1[n];

    std::cout << "Ingrese los numeros uno por uno: "; // Se piden los numeros del arreglo
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr1[i];
    }

    mergeSort(arr1, 0, n - 1);

    std::cout << "El arreglo ordenado es: "; // Se imprime el arreglo ordenado
    for (int i = 0; i < n; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
