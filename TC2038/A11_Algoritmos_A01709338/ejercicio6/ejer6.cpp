/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 6 
Se desea calcular el factorial de un número dado por el usuario.

compilar: g++ ejer6.cpp -o ejer6
ejecutar: ./ejer6
*/


#include <iostream>

int calculaFactorial(int n)
{
    if (n == 0 || n == 1)  // si el numero es 0 o 1 regresa 1
    {
        return 1;
    }
    else
    {
        return n * calculaFactorial(n - 1); // de lo contrario regresa el numero multiplicado por el factorial del numero menos 1
    }
}

int main()
{
    int numero;

    std::cout << "Ingresa el numero: ";  // pide el numero
    std::cin >> numero;

    int result = calculaFactorial(numero);

    std::cout << "Factorial: " << result << std::endl;  // regresa el factorial del numero

    return 0;
}
