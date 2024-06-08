#include <iostream>
#include <string>

int main() {
    std::string str;
    int vowelCount = 0;
    std::cout << "Digite uma string: ";
    std::cin >> str;
    for (char c : str) {
        char lowerC = tolower(c);
        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
            vowelCount++;
        }
    }
    std::cout << "Número de vogais: " << vowelCount << std::endl;
    return 0;
}
