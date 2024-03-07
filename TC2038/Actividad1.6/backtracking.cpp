#include <iostream>
#include <vector>

int M, N;

std::vector<std::vector<bool>> laberinto;

void imprimirLaberinto() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << laberinto[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool dentroDelLaberinto(int x, int y) {
  return (x >= 0 && x < M && y >= 0 && y < N);
}

void marcarVisitada(int x, int y) {
  laberinto[x][y] = false;
}

void desmarcarVisitada(int x, int y) {
  laberinto[x][y] = true;
}

bool encontrarCamino(int x, int y, std::vector<std::pair<int, int>> &camino) {
  camino.push_back(std::make_pair(x, y));
  if (x == M - 1 && y == N - 1) {
    for (const auto &p : camino) {
      return true;
    }
    return false;
  }

  marcarVisitada(x, y);

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (dentroDelLaberinto(x + i, y + j) && laberinto[x + i][y + j]) {
        if (encontrarCamino(x + i, y + j, camino)) {
          return true;
        }
      }
    }
  }

  desmarcarVisitada(x, y);
  camino.pop_back();

  return false;
}

int main() {
  std::cout << "Ingrese las dimensiones del laberinto M --->";
  std::cin >> M;
  std::cout << "Ingrese las dimensiones del laberinto N --->";
  std::cin >> N;

  std::cout << "Ingrese el laberinto (0 para camino bloqueado, 1 para camino libre):" << std::endl;
  for (int i = 0; i < M; i++) {
    std::vector<bool> fila;
    for (int j = 0; j < N; j++) {
      bool valor;
      std::cin >> valor;
      fila.push_back(valor);
    }
    laberinto.push_back(fila);
  }

  std::cout << "Laberinto original:" << std::endl;
  imprimirLaberinto();

  std::vector<std::pair<int, int>> camino;
  encontrarCamino(0, 0, camino);

  std::cout << "Laberinto con el camino marcado:" << std::endl;
  imprimirLaberinto();

  return 0;
}
