/*
Actividad 1.5b
Integrantes: 

Eliuth Balderas Neri
Jorge Emiliano Pomar Mendoza 

compilar: g++ algoritmos.cpp -o algoritmosAyD
ejecutar: ./algoritmosAyD 

*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> algDinamico(std::vector<int> &valores, int precio, int pago) //Algoritmo Dinamico

{
    int n = valores.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(pago + 1, 0)); //Matriz de (n+1) x (pago+1) con valores 0

    for (int i = 0; i <= n; i++) // aqui empieza a iterar para llenar la matriz
    {
        for (int j = 0; j <= pago; j++)
        {
            if (i == 0 || j == 0) //Si el precio es 0 o la cantidad de billetes y monedas es 0, entonces el resultado es 0
            {
                dp[i][j] = 0;
            }
            else if (valores[i - 1] <= j) //Si el valor de la moneda o billete es menor o igual al precio, entonces se toma el maximo entre el valor de la moneda o billete mas el valor de la matriz en la posicion (i,j-valor[i-1]) y el valor de la matriz en la posicion (i-1,j)
            {
                dp[i][j] = std::max(valores[i - 1] + dp[i][j - valores[i - 1]], dp[i - 1][j]); //Se toma el maximo entre el valor de la moneda o billete mas el valor de la matriz en la posicion (i,j-valor[i-1]) y el valor de la matriz en la posicion (i-1,j)
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; //Si el valor de la moneda o billete es mayor al precio, entonces se toma el valor de la matriz en la posicion (i-1,j)
            }
        }
    }

    std::vector<int> result(n, 0); //Se crea un vector de n elementos con puros 0
    int i = n, j = precio;
    while (i > 0 && j > 0) //Mientras i sea mayor a 0 y j sea mayor a 0
    {
        if (dp[i][j] != dp[i - 1][j]) //Si el valor de la matriz en la posicion (i,j) es diferente al valor de la matriz en la posicion (i-1,j), entonces se le suma 1 al valor del vector en la posicion (i-1)
        {
            result[i - 1]++; 
            j -= valores[i - 1]; //Se le resta el valor de la moneda o billete a j
        }
        else
        {
            i--; //Si no, se le resta 1 a i
        }
    }

    return result;
}

void algAvaro(std::vector<int> &valores, int precio, int pago) //Algoritmo Avaro
{
    std::vector<int> cambio;
    int cambioTotal = pago - precio;
    int i = valores.size() - 1; 
    while (cambioTotal > 0 && i >= 0) //Mientras el cambio total sea mayor a 0 y i sea mayor o igual a 0 
    {
        if (cambioTotal >= valores[i])
        {
            cambio.push_back(valores[i]); //Se agrega el valor de la moneda o billete al vector cambio
            cambioTotal -= valores[i];
        }
        else
        {
            i--; //Si no, se le resta 1 a i
        }
    }

    std::cout << "---Algoritmo Avaro--- \n";
    std::cout << "El cambio es: ";

    for (int i = 0; i < cambio.size(); i++)
    {
        std::cout << cambio[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    std::cout << "Ingrese la cantidad de denominaciones de billetes y monedas disponibles ---> " << std::endl;
    int n;
    std::cin >> n;

    std::cout << "Ingrese los valores de los billetes y monedas disponibles ---> " << std::endl;
    std::vector<int> valores(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> valores[i];
    }

    int precio = 0;
    int pago = 0;
    std::cout << "Ingrese el precio del producto ---> " << std::endl;
    std::cin >> precio;
    std::cout << "Ingrese la cantidad con la que va a pagar ---> " << std::endl;
    std::cin >> pago;

    std::vector<int> resultado = algDinamico(valores, precio, pago);
    std::cout << "---Algoritmo Dinamico--- \n";
    std::cout << "El resultado es: ";
    for (int i = 0; i < resultado.size(); i++)
    {
        std::cout << resultado[i] << " ";
    }
    std::cout << std::endl;

    algAvaro(valores, precio, pago);

    return 0;
}
