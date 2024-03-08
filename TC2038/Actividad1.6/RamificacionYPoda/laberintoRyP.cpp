/*
Actividad 1.6

Integrantes: 
Jorge Emiliano Pomar Mendoza
Eliuth Balderas Neri 

Este programa encuentra el camino a seguir en un laberinto de dimensiones MxN.
Se utiliza la técnica de ramificación y poda y el criterio de avance es derecha -> abajo -> izquierda -> arriba.

compilar: g++ laberintoRyP.cpp -o laberintoRyP
ejecutar: ./laberintoRyP
*/

#include <iostream>
#include <vector>
#include <stack>

int M, N; // Dimensiones del laberinto

std::vector<std::vector<bool>> laberinto; // vector que contiene el laberinto
std::vector<std::vector<bool>> solucion; // vector que contiene la solución

bool adentro(int x, int y) // Función que verifica si una posición está dentro del laberinto
{
    return (x >= 0 && x < M && y >= 0 && y < N);
}

bool resolverLaberintoRamificacionPoda() {
    std::stack<std::pair<int, int>> pila;
    pila.push(std::make_pair(0, 0));
    solucion[0][0] = true;

    while (!pila.empty()) {
        std::pair<int, int> actual = pila.top();
        int x = actual.first;
        int y = actual.second;

        if (x == M - 1 && y == N - 1) {
            return true;
        }

        bool encontrado = false;

        // Explorar las opciones de movimiento (derecha, abajo, izquierda, arriba)
        for (int k = 0; k < 4; k++) {
            int nuevoX = x + (k == 0 ? 1 : (k == 2 ? -1 : 0));
            int nuevoY = y + (k == 1 ? 1 : (k == 3 ? -1 : 0));

            if (adentro(nuevoX, nuevoY) && laberinto[nuevoX][nuevoY] && !solucion[nuevoX][nuevoY]) {
                pila.push(std::make_pair(nuevoX, nuevoY));
                solucion[nuevoX][nuevoY] = true;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            pila.pop();
        }
    }

    return false;
}

void imprimeLaberinto() // Función que imprime el laberinto original
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << laberinto[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void imprimeCamino() // Función que imprime el laberinto con el camino marcado
{
    std::cout << "Laberinto con el camino encontrado:" << std::endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << solucion[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Ingrese las dimensiones del laberinto M --->";
    std::cin >> M;
    std::cout << "Ingrese las dimensiones del laberinto N --->";
    std::cin >> N;

    std::cout << "Ingrese el laberinto --->" << std::endl;

    for (int i = 0; i < M; i++) // Llena el laberinto con los valores ingresados
    {
        std::vector<bool> fila;
        for (int j = 0; j < N; j++)
        {
            bool valor;
            std::cin >> valor;
            fila.push_back(valor);
        }
        laberinto.push_back(fila);
    }

    solucion = std::vector<std::vector<bool>>(M, std::vector<bool>(N, false)); // Inicializar la solución con dimensiones MxN

    std::cout << "Laberinto original:" << std::endl;
    imprimeLaberinto();

    if (resolverLaberintoRamificacionPoda()) {
        imprimeCamino();
    } else {
        std::cout << "No hay camino" << std::endl;
    }

    return 0;
}