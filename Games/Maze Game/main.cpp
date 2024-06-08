#include <iostream>
#include <vector>
using namespace std;

void printMaze(const vector<vector<char>>& maze, int playerX, int playerY) {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[0].size(); ++j) {
            if (i == playerX && j == playerY) {
                cout << 'P';
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> maze = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', 'E', '#'}
    };

    int playerX = 1, playerY = 1;
    char move;

    while (true) {
        printMaze(maze, playerX, playerY);
        cout << "Digite sua movimentação (WASD): ";
        cin >> move;

        int newX = playerX, newY = playerY;
        if (move == 'w' && maze[playerX - 1][playerY] != '#') newX--;
        if (move == 's' && maze[playerX + 1][playerY] != '#') newX++;
        if (move == 'a' && maze[playerY - 1][playerX] != '#') newY--;
        if (move == 'd' && maze[playerY + 1][playerX] != '#') newY++;

        if (maze[newX][newY] == 'E') {
            cout << "Você venceu!" << endl;
            break;
        }

        playerX = newX;
        playerY = newY;
    }

    return 0;
}
