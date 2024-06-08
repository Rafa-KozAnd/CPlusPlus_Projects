#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void printCard(const vector<vector<int>>& card) {
    for (const auto& row : card) {
        for (int num : row) {
            if (num == -1) {
                cout << " X ";
            } else {
                cout << num << " ";
            }
        }
        cout << endl;
    }
}

bool checkBingo(const vector<vector<int>>& card) {
    for (const auto& row : card) {
        bool rowBingo = true;
        for (int num : row) {
            if (num != -1) {
                rowBingo = false;
                break;
            }
        }
        if (rowBingo) return true;
    }
    for (int col = 0; col < card[0].size(); ++col) {
        bool colBingo = true;
        for (const auto& row : card) {
            if (row[col] != -1) {
                colBingo = false;
                break;
            }
        }
        if (colBingo) return true;
    }
    return false;
}

int main() {
    srand(time(0));
    vector<vector<int>> card(5, vector<int>(5));
    vector<int> numbers(25);
    iota(numbers.begin(), numbers.end(), 1);
    random_shuffle(numbers.begin(), numbers.end());

    int idx = 0;
    for (auto& row : card) {
        for (int& num : row) {
            num = numbers[idx++];
        }
    }

    while (true) {
        printCard(card);
        int drawnNumber;
        cout << "Digite o número sorteado (1-25): ";
        cin >> drawnNumber;

        bool marked = false;
        for (auto& row : card) {
            for (int& num : row) {
                if (num == drawnNumber) {
                    num = -1;
                    marked = true;
                }
            }
        }

        if (marked && checkBingo(card)) {
            cout << "Bingo! Você venceu!" << endl;
            break;
        }
    }

    return 0;
}
