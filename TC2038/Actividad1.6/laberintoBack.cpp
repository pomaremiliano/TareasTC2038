/*
Actividad 1.6

Integrantes: 
Jorge Emiliano Pomar Mendoza
Eliuth Balderas Neri 

Este programa encuentra el camino a seguir en un laberinto de dimensiones MxN.
Se utiliza la técnica de backtracking y el criterio de avance es derecha -> abajo -> izquierda -> arriba.

*/

#include <iostream>
#include <vector>

int M, N; // Dimensiones del laberinto

std::vector<std::vector<bool>> laberinto; // vector que contiene el laberinto

bool adentro(int x, int y) // Función que verifica si una posición está dentro del laberinto
{
    return (x >= 0 && x < M && y >= 0 && y < N);
}

void marcarVisitada(int x, int y) // Función que marca una posición como visitada para no volver a pasar por ella

{
    laberinto[x][y] = false;
}

void desmarcarVisitada(int x, int y) // Función que desmarca una posición como visitada para poder volver a revisarla
{
    laberinto[x][y] = true;
}

bool encuentraCamino(int x, int y, std::vector<std::pair<int, int>> &camino) // Función que encuentra el camino a seguir en el laberinto de manera recursiva
{
    camino.push_back(std::make_pair(x, y)); // Agrega la posición actual al camino
    if (x == M - 1 && y == N - 1)
    {
        return true;
    }

    marcarVisitada(x, y);

    int x1[] = {0, 1, 0, -1}; // Arreglos que contienen los movimientos validos en x y y
    int y1[] = {1, 0, -1, 0};

    for (int k = 0; k < 4; k++) // Revisa los movimientos validos
    {
        int nuevoX = x + x1[k];
        int nuevoY = y + y1[k];

        if (adentro(nuevoX, nuevoY) && laberinto[nuevoX][nuevoY])
        {
            if (encuentraCamino(nuevoX, nuevoY, camino))
            {
                return true;
            }
        }
    }

    desmarcarVisitada(x, y); 
    camino.pop_back(); // Si no hay camino, se elimina la posición actual del camino

    return false; // Si no hay camino, regresa false
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

void imprimeCamino(const std::vector<std::pair<int, int>> &camino) // Función que imprime el laberinto con el camino marcado
{
    std::vector<std::vector<bool>> caminoMarcado(M, std::vector<bool>(N, false)); // Vector que contiene el laberinto con el camino marcado

    for (const auto &pos : camino) // Marca las posiciones del camino
    {
        caminoMarcado[pos.first][pos.second] = true; 
    }

    std::cout << "Laberinto con el camino marcado:" << std::endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << caminoMarcado[i][j] << " ";
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

    std::cout << "Laberinto original:" << std::endl;
    imprimeLaberinto();

    std::vector<std::pair<int, int>> camino; 
    encuentraCamino(0, 0, camino);

    if (camino.empty()) // Si no hay camino, imprime un mensaje
    {
        std::cout << "No hay camino" << std::endl;
        return 0;
    }

    imprimeCamino(camino);

    return 0;
}
