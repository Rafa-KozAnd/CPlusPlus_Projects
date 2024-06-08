#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 8;

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if ((i + j) % 2 == 1) {
                if (i < 3) board[i][j] = 'B'; // Peças pretas
                else if (i > 4) board[i][j] = 'W'; // Peças brancas
                else board[i][j] = ' ';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard(const vector<vector<char>>& board) {
    cout << "  A B C D E F G H" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(const vector<vector<char>>& board, int x1, int y1, int x2, int y2, char player) {
    if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || board[x2][y2] != ' ')
        return false;
    if (player == 'W' && (x2 - x1 != 1 || abs(y2 - y1) != 1))
        return false;
    if (player == 'B' && (x1 - x2 != 1 || abs(y2 - y1) != 1))
        return false;
    return true;
}

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE));
    initializeBoard(board);
    char player = 'W';
    while (true) {
        printBoard(board);
        cout << "Jogador " << player << ", insira seu movimento (ex: A3 B4): ";
        char col1, col2;
        int row1, row2;
        cin >> col1 >> row1 >> col2 >> row2;
        int x1 = row1 - 1, y1 = col1 - 'A';
        int x2 = row2 - 1, y2 = col2 - 'A';
        if (isValidMove(board, x1, y1, x2, y2, player)) {
            board[x2][y2] = player;
            board[x1][y1] = ' ';
            player = (player == 'W') ? 'B' : 'W';
        } else {
            cout << "Movimento inválido!" << endl;
        }
    }
    return 0;
}
