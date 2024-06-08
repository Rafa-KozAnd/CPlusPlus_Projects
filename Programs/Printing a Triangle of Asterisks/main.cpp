#include <iostream>

int main() {
    int linhas;
    std::cout << "Digite o número de linhas: ";
    std::cin >> linhas;
    for (int i = 1; i <= linhas; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}
