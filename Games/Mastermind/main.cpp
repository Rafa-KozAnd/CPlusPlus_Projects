#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<char> generateCode(int length) {
    vector<char> code;
    const string colors = "RGBY";
    for (int i = 0; i < length; ++i) {
        code.push_back(colors[rand() % colors.size()]);
    }
    return code;
}

void evaluateGuess(const vector<char>& code, const vector<char>& guess, int& correct, int& misplaced) {
    correct = 0;
    misplaced = 0;
    vector<bool> codeUsed(code.size(), false);
    vector<bool> guessUsed(guess.size(), false);

    for (int i = 0; i < code.size(); ++i) {
        if (code[i] == guess[i]) {
            correct++;
            codeUsed[i] = true;
            guessUsed[i] = true;
        }
    }

    for (int i = 0; i < code.size(); ++i) {
        if (!codeUsed[i]) {
            for (int j = 0; j < guess.size(); ++j) {
                if (!guessUsed[j] && code[i] == guess[j]) {
                    misplaced++;
                    guessUsed[j] = true;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    int length = 4;
    vector<char> code = generateCode(length);
    int attempts = 10;
    int correct, misplaced;

    while (attempts > 0) {
        string guessInput;
        cout << "Digite sua tentativa (RGBY): ";
        cin >> guessInput;
        vector<char> guess(guessInput.begin(), guessInput.end());

        evaluateGuess(code, guess, correct, misplaced);

        if (correct == length) {
            cout << "Parabéns! Você adivinhou o código!" << endl;
            break;
        } else {
            cout << "Cores corretas na posição correta: " << correct << endl;
            cout << "Cores corretas na posição incorreta: " << misplaced << endl;
            attempts--;
        }
    }

    if (attempts == 0) {
        cout << "Você perdeu! O código era: ";
        for (char c : code) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
