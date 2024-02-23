/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 3
Que solicite un número que indica cuántos números aleatorios (positivos y
negativos) se mostrarán.

compilar: g++ ejer3.cpp -o ejer3
ejecutar: ./ejer3
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int calculaAleatorios (int numeros) {
    srand(time(0)); // primero creo una semilla que genera numeros aleatorios
    for (int i = 0; i < numeros; i++) { 
        int aleatorio = rand() % 100;  // genero un numero aleatorio entre 0 y 100
        return aleatorio;
    }
}

int main() {
    int numeros;
    std::cout << "Ingresa el numero de numeros aleatorios: "; // usuario ingresa numero de numeros aleatorios
    std::cin >> numeros;

    int aleatorio = calculaAleatorios(numeros);
    std::cout << "Numeros generados: \n" << aleatorio << std::endl; // se imprimen los numeros aleatorios generados

    return 0;
}