#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateMaze(int rows, int cols, int playerX, int playerY, int exitX, int exitY, int difficulty) {
    srand(time(0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                cout << "#";
            } else if (i == playerX && j == playerY) {
                cout << "P";
            } else if (i == exitX && j == exitY) {
                cout << "E";
            } else {
                if (difficulty == 1 && rand() % 10 < 3) {
                    cout << "#";
                } else if (difficulty == 2 && rand() % 10 < 7) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
        }
        cout << endl;
    }
}

void movePlayer(int& playerX, int& playerY, char move, int rows, int cols) {
    if (move == 'W' || move == 'w') {
        if (playerX > 1) playerX--;
    } else if (move == 'S' || move == 's') {
        if (playerX < rows - 2) playerX++;
    } else if (move == 'A' || move == 'a') {
        if (playerY > 1) playerY--;
    } else if (move == 'D' || move == 'd') {
        if (playerY < cols - 2) playerY++;
    }
}

int main() {
    int rows, cols;
    int playerX = 1, playerY = 1;
    int exitX, exitY;
    int difficulty;
    char move;

    cout << "Welcome to the Procedural Maze Explorer!" << endl;

    cout << "Enter the number of rows for the maze (min 5, max 20): ";
    cin >> rows;
    cout << "Enter the number of columns for the maze (min 5, max 20): ";
    cin >> cols;

    cout << "Choose difficulty level (1 = Easy, 2 = Hard): ";
    cin >> difficulty;

    srand(time(0));
    exitX = rand() % (rows - 2) + 1;
    exitY = rand() % (cols - 2) + 1;

    cout << "Game start!" << endl;

    while (true) {
        generateMaze(rows, cols, playerX, playerY, exitX, exitY, difficulty);

        cout << "Use WASD to move. (W = up, S = down, A = left, D = right)" << endl;
        cout << "Your current position: (" << playerX << ", " << playerY << ")" << endl;
        cout << "Enter your move: ";
        cin >> move;

        movePlayer(playerX, playerY, move, rows, cols);

        if (playerX == exitX && playerY == exitY) {
            cout << "Congratulations! You reached the exit!" << endl;
            break;
        }
    }

    return 0;
}
