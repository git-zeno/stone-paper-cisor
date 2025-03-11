#include <bits/stdc++.h>
using namespace std;

char getSystemMove() {
    int move = rand() % 3;
    if (move == 0) return 's';
    if (move == 1) return 'p';
    return 'c';
}

bool isValidMove(char move) {
    return move == 's' || move == 'p' || move == 'c';
}

void determineWinner(char playerMove, char systemMove) {
    cout << "System's move: " << systemMove << "\n";
    
    if (playerMove == systemMove) {
        cout << "Result: Draw!\n";
    } else if ((playerMove == 's' && systemMove == 'c') ||
               (playerMove == 'p' && systemMove == 's') ||
               (playerMove == 'c' && systemMove == 'p')) {
        cout << "Result: You Win!\n";
    } else {
        cout << "Result: You Lose!\n";
    }
}

void playGame() {
    while (true) {
        char playerMove;
        cout << "\nEnter your move:\n"
             << "Stone -> 's', Paper -> 'p', Scissors -> 'c'\n"
             << "Your move: ";
        cin >> playerMove;
        
        if (!isValidMove(playerMove)) {
            cout << "Invalid input! Please enter 's', 'p', or 'c'.\n";
            continue;
        }

        char systemMove = getSystemMove();
        determineWinner(playerMove, systemMove);
        
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            cout << "Thanks for playing!\n";
            break;
        }
    }
}

int main() {
    cout << "Welcome to Rock-Paper-Scissors!\n";
    playGame();
    return 0;
}
