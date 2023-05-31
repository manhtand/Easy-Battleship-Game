#ifndef gameboard_hpp
#define gameboard_hpp

#include <stdio.h>
#include "ship.hpp"
#include <array>
using namespace std;


class GameBoard
{
public:
    
    GameBoard();

    void printPlayerBoard();

    void printEnemyBoard();

    bool hit(int row, int col);

    void mark(int row, int col, bool wasHit);

    void randomPlaceShips();

    bool allShipsSunk();
    
    void placeShip(int row, int col, int length, Direction dir, int index);
    
    void fillPlayerBoard();
    
    void fillEnemyBoard();
    
    bool checkPosition(int direct, int length, int row, int col, Direction& dir);
    
    bool checkNorth(int row, int col, int length);
    
    bool checkEast(int row, int col, int length);
    
    bool checkSouth(int row, int col, int length);
    
    bool checkWest(int row, int col, int length);
    
private:
    
    array<Ship, 10> m_ships;
    
    array<array<char, 10>, 10> m_enemyBoard;
    
    array<array<char, 10>, 10> m_playerBoard;
};

#endif /* gameboard_hpp */
