#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "Digite três números: ";
    std::cin >> num1 >> num2 >> num3;
    if (num1 >= num2 && num1 >= num3)
        std::cout << "O maior número é: " << num1 << std::endl;
    else if (num2 >= num1 && num2 >= num3)
        std::cout << "O maior número é: " << num2 << std::endl;
    else
        std::cout << "O maior número é: " << num3 << std::endl;
    return 0;
}
