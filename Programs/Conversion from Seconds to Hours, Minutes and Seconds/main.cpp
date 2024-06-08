#include <iostream>

int main() {
    int totalSegundos, horas, minutos, segundos;
    std::cout << "Digite o total de segundos: ";
    std::cin >> totalSegundos;
    horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    minutos = totalSegundos / 60;
    segundos = totalSegundos % 60;
    std::cout << horas << " horas, " << minutos << " minutos, " << segundos << " segundos" << std::endl;
    return 0;
}
