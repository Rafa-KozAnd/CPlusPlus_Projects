#include <iostream>
#include <string>

int main() {
    std::string str, rev;
    std::cout << "Digite uma palavra: ";
    std::cin >> str;
    rev = std::string(str.rbegin(), str.rend());
    if (str == rev) {
        std::cout << str << " é um palíndromo." << std::endl;
    } else {
        std::cout << str << " não é um palíndromo." << std::endl;
    }
    return 0;
}
