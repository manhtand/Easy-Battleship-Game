#include "battleship.hpp"

#include <iostream>
#include <string>
#include <array>

using namespace std;

Battleship::Battleship(const string& player1Name, const string& player2Name)
{
    Player player1 (player1Name);
    Player player2 (player2Name);
    m_players[0] = player1;
    m_players[1] = player2;
}

void Battleship::play()
{
    GameBoard player1Board;
    GameBoard player2Board;
    m_boards[0] = player1Board;
    m_boards[1] = player2Board;

    srand(time(0));
    bool playerTurn = rand() % 2;
    
    while (!m_boards[0].allShipsSunk() && !m_boards[1].allShipsSunk())
    {
        turn(playerTurn);
    }
    m_players[!playerTurn].addGameWon();
    m_players[playerTurn].addGameLost();
    cout << m_players[!playerTurn].getName() << " has won!" << endl << endl;
    cout << "Do you want to play again? y/n" << endl << endl;
}

void Battleship::turn(bool &playerTurn)
{
    string input;
    cout << "Player " << m_players[playerTurn].getName() << endl;
    m_boards[playerTurn].printPlayerBoard();
    cout << endl << "Enter your Move xy (x for Row and y for Column): " << endl;
    cin >> input;
    int row = static_cast<int>(input[0] - 48);
    int col = static_cast<int>(input[1] - 48);
    bool wasHit = m_boards[!playerTurn].hit(row, col);
    m_boards[playerTurn].mark(row, col, wasHit);
    playerTurn = !playerTurn;
}

