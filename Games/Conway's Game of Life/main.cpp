#include <iostream>
#include <vector>
#include <unistd.h> // Para a função sleep
using namespace std;

const int SIZE = 10;

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << (board[i][j] ? "O" : ".");
        }
        cout << endl;
    }
}

int countNeighbors(const vector<vector<int>>& board, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                count += board[nx][ny];
            }
        }
    }
    return count;
}

void updateBoard(vector<vector<int>>& board) {
    vector<vector<int>> newBoard = board;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) newBoard[i][j] = 0;
            } else {
                if (neighbors == 3) newBoard[i][j] = 1;
            }
        }
    }
    board = newBoard;
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
    board[1][2] = board[2][3] = board[3][1] = board[3][2] = board[3][3] = 1;

    while (true) {
        printBoard(board);
        updateBoard(board);
        sleep(1); // Aguarde um segundo
        system("clear"); // Limpa a tela no Linux/Unix, use "cls" no Windows
    }
    return 0;
}
