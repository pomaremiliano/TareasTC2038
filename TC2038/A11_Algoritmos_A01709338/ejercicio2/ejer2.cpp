/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 2 
Resulta que ha llegado una nueva máquina embotelladora de refrescos, el contenedor principal de la
máquina tiene forma cilíndrica. Se sabe que cada envase de refresco debe contener M mililitros. Se
desea saber cuántos refrescos puede llenar la máquina de una sola vez, sin recargar el contenedor.
Solo se tienen los datos del radio de la base y la altura medidos en metros. 

compilar: g++ ejer2.cpp -o ejer2
ejecutar: ./ejer2
*/

#include <iostream>
#include <cmath>
#include "math.h"
#define M_PI 3.14159265358979323846 // Lo tuve que definir porque no me dejaba usar M_PI por si solo

int calculaVolumen(double radio, double altura){
    double volumen = (M_PI * (pow(radio, 2)) * altura) * 1000000; // formula de volumen de un cilindro, se multiplica por 1000000 para convertir de m3 a ml
    return volumen; // regresa el volumen
}

int main() {
    double radio, altura;
    std::cout << "Ingresa el radio: "; // pide el radio
    std::cin >> radio;
    std::cout << "Ingresa la altura: "; // pide la altura
    std::cin >> altura;

    double volumen = calculaVolumen(radio, altura);
    int capacidad;
    std::cout << "Ingresa la capacidad del envase: "; // pide la capacidad del envase 
    std::cin >> capacidad;

    int cantidadRefrescos = capacidad / volumen;
    std::cout << "Capacidad de llenado de la maquina: \n" << volumen << " ml c/u"<< "\nY una cantidad de: "<< cantidadRefrescos << " botellas de refresco" << std::endl; // regresa el volumen y el numero de botellas de refresco que se pueden llenar

    return 0;
}