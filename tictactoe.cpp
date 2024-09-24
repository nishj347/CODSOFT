#include <bits/stdc++.h>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;
string s1, s2,s3;

void drawBoard() {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    return 0; 
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    if (currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

void game() {
    cout << "enter first player's name: ";
    cin >> s1;
    cout << "enter second player's name: ";
    cin >> s2;

    cout << s1 << ", choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();
    int playerWon = 0;

    for (int i = 0; i < 9; i++) {
        if (currentPlayer == 1) {
            cout << "it's " << s1 << "'s turn. enter your slot: ";
        } else {
            cout << "it's " << s2 << "'s turn. enter your slot: ";
        }

        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "invalid slot! try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "slot occupied! try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        playerWon = checkWinner();
        if (playerWon == 1) {
            cout << s1 << " wins!" << endl;
            break;
        } else if (playerWon == 2) {
            cout << s2 << " wins!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        cout << "it's a tie!" << endl;
    }
}

int main() {
    game();
    return 0;
}
