#include <iostream>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    std::cout << "Digite o número de termos: ";
    std::cin >> n;
    std::cout << "Sequência Fibonacci: ";
    for (int i = 1; i <= n; ++i) {
        std::cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    std::cout << std::endl;
    return 0;
}
