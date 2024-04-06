/*
Actividad 2.5. Implementación de "Suffix Array" 

Integrantes: 
Jorge Emiliano Pomar Mendoza | A01709338
Eliuth Balderas Neri | A01703315 

Este programa tiene una complejidad computacional de O(n^3logn)
por el uso de sort y el uso de dos ciclos anidados que tan solo 
ordenar puede llegar a ser O(n^2logn) y las comparaciones de los
caracteres de las subcadenas es O(n) por lo que en total es O(n^3logn).

*/

#include <iostream>
#include <vector>
#include <algorithm> //uso esto para el sort
#include <string>

int ordenaSubStrings(std::string arreglo, std::vector<std::string> &substring) 
{
    for (int i = 0; i < arreglo.length(); i++) //Generar todas las subcadenas posibles
    {
        for (int j = i; j < arreglo.length(); j++) 
        {
            substring.push_back(arreglo.substr(i, j - i + 1)); //Agrega cada substring al vector, peor de los casos es O(n)
        }
    }

    sort(substring.begin(), substring.end()); //Complejidad O(nlogn) por el sort aplfaeticamente
    return 0;

}

int main()
{

    std::string arreglo;
    std::cout << "Ingrese la cadena de caracteres: ";
    std::cin >> arreglo;
    std::vector<std::string> substring;
    ordenaSubStrings(arreglo, substring);
    for (int i = 0; i < substring.size(); i++) //Imprime todas las subcadenas 
    {
        std::cout << "Substring: \n";
        std::cout << substring[i] << std::endl;
    }
    return 0;
}