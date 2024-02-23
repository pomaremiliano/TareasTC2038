/*
Tarea 1
Nombre: Jorge Emiliano Pomar Mendoza
Ejercicio 1 
Se desea tener un programa que permita saber en cuantos días es posible surtir un pedido
de N camisas. Con la intención de mejorar la planeación de los tiempos de entrega y de los
insumos necesarios para producirlas ya que últimamente se han registrado retrasos en los
tiempos de entrega.

compilar: g++ ejer1.cpp -o ejer1
ejecutar: ./ejer1
*/

#include <iostream>

int calculaDias(int numProductos) { // funcion que recibe el numero de camisetas que se necesitan producir y regresa el numero de dias que se necesitan para producirlas

    int diaProduccion = rand()%100; // cantidad de productos que se producen por dia (numero aleatorio entre 0 y 50)

    if (numProductos <= diaProduccion) {  // si el numero de camisetas es menor o igual a la cantidad de camisetas que se producen por dia regresa 1 porque si se pueden producir en un dia
        return 1;
    } else { // si el numero de camisetas es mayor a la cantidad de camisetas que se producen por dia se hace la division y si el residuo no es exacto, se utiliza modulo para saber si se necesita un dia mas para producir el resto de camisetas
        int dias = numProductos / diaProduccion;
        if (numProductos % diaProduccion != 0) {
            dias++;
        }
        return dias;
    }
}

int main() {
    int numProductos;
    std::cout << "Ingresa el numero de camisetas: "; // ingresa el numero de camisetas que se necesitan producir
    std::cin >> numProductos;

    int dias = calculaDias(numProductos);
    std::cout << "Tiempo de Surtido: \n" << dias << "dias" << std::endl; // regresa el numero de dias que se necesitan para producir las camisetas

    return 0;
}


