/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 4
Se muestren todos los números, la suma y el promedio de la siguiente serie
3, 6, 9, 12,... 99.

compilar: g++ ejer4.cpp -o ejer4
ejecutar: ./ejer4
*/

#include <iostream>
#include <vector>

std::vector<int> imprimeSerie(int inicio, int fin)
{
    std::vector<int> serie; // se declara un vector que guardara la serie de numeros
    // se hace un ciclo for que recorre los numeros del inicio al final y se imprimen
    for (int i = inicio; i <= fin; i++)
    {
        std::cout << i << " " << std::endl;
        serie.push_back(i); // se guardan los numeros en el vector
    }
    return serie; // se regresa el vector con la serie de numeros
}

int calculaSuma(int inicio, int fin)
{
    // primero se declaran la variable de suma inicializada en 0
    int suma = 0;

    // se hace un ciclo for que recorre los numeros del inicio al final y se suman
    for (int i = inicio; i <= fin; i++)
    {
        suma += i;
    }

    return suma;
}

float calculaPromedio(int inicio, int fin)
{
    // se llama a la funcion que calcula la suma
    int suma = calculaSuma(inicio, fin);
    int contador = 0;

    // se hace un ciclo for que recorre los numeros del inicio al final y se cuentan
    for (int i = inicio; i <= fin; i++)
    {
        contador++;
    }

    // se calcula el promedio dividiendo la suma entre el contador
    // se hace un cast a float para que el resultado sea un float y no haya problema
    float promedio = static_cast<float>(suma) / contador;
    return promedio;
}

int main()
{
    int inicio = 3; // se declara el inicio de la serie como 3
    int fin = 99;   // se declara el fin de la serie como 99

    int suma = calculaSuma(inicio, fin);
    float promedio = calculaPromedio(inicio, fin);

    std::cout << "Todos los numeros: \n";
    std::vector<int> serie = imprimeSerie(inicio, fin);
    // regresa la serie de numeros
    std::cout << "Suma de los numeros de la serie: \n" // regresa la suma de los numeros de la serie
              << suma << std::endl;

    std::cout << "Promedio de los numeros de la serie: \n"
              << promedio << std::endl; // regresa el promedio de los numeros de la serie
}