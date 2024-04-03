#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // Para manipular el formato de salida
#include <sstream> // Para convertir enteros a cadenas
#include <string>

std::string leerArchivo(const std::string& filename) { 
    std::ifstream archivo(filename);
    std::string content((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>()); //istreambuf_iterator<char> itera sobre el archivo y lo guarda en content
    return content;
}

std::vector<std::vector<char>> generaTabla(const std::string& content, int n) {
    int rows = content.size() / n + (content.size() % n != 0);
    std::vector<std::vector<char>> tabla(rows, std::vector<char>(n, n)); // Rellenar con el valor de 'n'
    
    // iterar sobre el contenido y llenar la tabla con el contenido del caso1.txt
    for (int i = 0; i < content.size(); i++) {
        tabla[i / n][i % n] = content[i];
    }
    return tabla;
}

std::vector<int> calculaArregloL(const std::vector<std::vector<char>>& table, int n) {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < table.size(); j++) {
            a[i] += table[j][i];
        }
        a[i] %= 256;
    }
    return a;
}

std::string imprimeArreglo(const std::vector<int>& a) {
    std::stringstream ss;
    for (int i = 0; i < a.size(); i += 4) {
        int val = 0;
        for (int j = 0; j < 4 && i + j < a.size(); j++) {
            val = (val << 8) + a[i + j];
        }
        ss << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << val; // Formato hexadecimal
    }
    return ss.str(); // Convertir el stringstream a string
}

void imprimeTabla(const std::vector<std::vector<char>>& table) {
    for (const auto& row : table) { // Iterar sobre cada fila de la tabla y mostrarla
        for (char c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filename = "caso1.txt";
    int n; // Multiplo de 4 entre 16 y 64
    std::cout << "Ingrese el valor de n: (Debe ser un múltiplo de 4 entre 16 y 64)\n";
    std::cin >> n; 
    
    std::string content = leerArchivo(filename);
    std::vector<std::vector<char>> table = generaTabla(content, n);
    std::vector<int> a = calculaArregloL(table, n);
    std::string output = imprimeArreglo(a);
    
    // Mostrar los resultados
    imprimeTabla(table);
    std::cout << "Arreglo tamaño n que contiene la suma de los caracteres de cada columna % 256: \n";
    for (int val : a) {
        std::cout << val << " ";
    }
    std::cout << "\nCadena de salida: \n" << output << std::endl;

    return 0;
}
