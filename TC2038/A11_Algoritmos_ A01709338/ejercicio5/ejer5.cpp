/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 5 
Se desea calcular los primeros 15 números de la siguiente sumatoria:
Suma = 1 + 1/2² + 1/3³ + 1/4² + 1/5⁵ + 1/6² + ...

compilar: g++ ejer5.cpp -o ejer5
ejecutar: ./ejer5
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

double calculaSumatoria () {
    // declaro la variable n y la variable que va a almacenar la suma de la serie en fraccion
    int n = 15;
    double sumaFraccion = 0.0;

    for (int i = 1; i <= n; i++) {  // ciclo for que recorre los numeros de 1 a n 
        sumaFraccion += (1.0 / (i % 2 == 0 ? pow(i, 2) : pow(i, i))); // se calcula el valor reciproco de i, al cuadrado si i es par, si no se calcula el valor reciproco de i a la potencia de i utilizando el modulo y pow para las potencias
    }

    return sumaFraccion;

}

int main() {
    double sumaFraccion = calculaSumatoria();
    std::cout << "Sumatoria de la serie: \n" << sumaFraccion << std::endl; // regresa la suma de la serie
    return 0;
}