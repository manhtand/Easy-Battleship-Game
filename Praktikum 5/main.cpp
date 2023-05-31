#include <iostream>
#include "battleship.hpp"


using namespace std;


int main()
{
    string player1Name, player2Name;
    cout << "Enter Player1 Name: ";
    cin >> player1Name;
    cout << endl << "Enter Player2 Name: ";
    cin >> player2Name;
    cout << endl << "Game start!" << endl << endl;
    
    Battleship battle(player1Name, player2Name);
    
    battle.play();
    
    char playAgain = 'y';
    cin >> playAgain;
    while (playAgain == 'y')
    {
        battle.play();
    }
    return 0;
}
