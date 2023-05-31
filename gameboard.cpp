#include "gameboard.hpp"
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

GameBoard::GameBoard()
{
    fillEnemyBoard();
    randomPlaceShips();
}

bool GameBoard::allShipsSunk()
{
    for (Ship s : m_ships)
    {
        if (!s.isSunk())
        {
            return false;
        }
    }
    return true;
}

bool GameBoard::hit(int row, int col)
{
    if ((m_playerBoard[row][col] != 'S') && (m_playerBoard[row][col] != 'X') && (m_playerBoard[row][col] != '.'))
    {
        for (int i = 0; i < m_ships.size(); i++)
        {
            if (m_ships[i].hasPartin(row, col))
            {
                m_ships[i].getPartin(row, col).setDamaged();
            }
        }
        cout << "Hit ship!" << endl;
        return true;
    }
    else
    {
        cout << "Miss!" << endl << endl;
        return false;
    }
}

void GameBoard::mark(int row, int col, bool wasHit)
{
    if (wasHit)
    {
        m_enemyBoard[row][col] = 'X';
    }
    else
    {
        m_enemyBoard[row][col] = 'O';
    }
}

void GameBoard::fillPlayerBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (m_ships[k].hasPartin(i, j))
                {
                    if (m_ships[k].getPartin(i, j).isDamaged())
                    {
                        if (m_ships[k].isSunk())
                        {
                            m_playerBoard[i][j] = 'S';
                            break;
                        }
                        else
                        {
                            m_playerBoard[i][j] = 'X';
                            break;
                        }
                    }
                    else
                    {
                        m_playerBoard[i][j] = k + 48;
                        break;
                    }
                }
                else
                {
                    m_playerBoard[i][j] = '.';
                }
            }
        }
    }
}

void GameBoard::printPlayerBoard()
{
    fillPlayerBoard();
    cout << setw(15) << right << "Your Board" << setw(28) << right << "Enemy's Board" << endl;
    cout << setw(3) << right << "0" << setw(2) << right << "1" << setw(2) << right << "2" << setw(2) << right << "3" << setw(2) << right << "4" << setw(2) << right << "5" << setw(2) << right << "6" << setw(2) << right << "7" << setw(2) << right << "8" << setw(2) << right << "9" << setw(8) << right << "0" << setw(2) << right << "1" << setw(2) << right << "2" << setw(2) << right << "3" << setw(2) << right << "4" << setw(2) << right << "5" << setw(2) << right << "6" << setw(2) << right << "7" << setw(2) << right << "8" << setw(2) << right << "9" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 10; j++)
        {
            cout << m_playerBoard[i][j] << " ";
        }
        cout << "    " << i << " ";
        for (int k = 0; k < 10; k++)
        {
            cout << m_enemyBoard[i][k] << " ";
        }
        cout << endl;
    }
}

void GameBoard::fillEnemyBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            m_enemyBoard[i][j] = '.';
        }
    }
}

void GameBoard::printEnemyBoard()
{
    /* cout << "Enemy Board" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << m_enemyBoard[i][j] << " ";
        }
        cout << endl;
    } */
}

bool GameBoard::checkPosition(int direct, int length, int row, int col, Direction& dir)
{
    bool validPosition = true;
    int rotation = 0;
    
    while (true)
    {
        if ((direct + rotation) % 4 == 0)
        {
            dir = Direction::north;
        }
        else if ((direct + rotation) % 4 == 1)
        {
            dir = Direction::east;
        }
        else if ((direct + rotation) % 4 == 2)
        {
            dir = Direction::south;
        }
        else if ((direct + rotation) % 4 == 3)
        {
            dir = Direction::west;
        }
        switch (dir)
        {
            case Direction::north:
            {
                validPosition = checkNorth(row, col, length);
                break;
            }
            case Direction::east:
            {
                validPosition = checkEast(row, col, length);
                break;
            }
            case Direction::south:
            {
                validPosition = checkSouth(row, col, length);
                break;
            }
            case Direction::west:
            {
                validPosition = checkWest(row, col, length);
                break;
            }
        }
        if (validPosition)
        {
            break;
        }
        rotation++;
        if (rotation == 4)
        {
            break;
        }
    }
    return validPosition;
}

bool GameBoard::checkNorth(int row, int col, int length)
{
    bool validPosition = true;
    if ((row - length) < 0)
    {
        validPosition = false;
        return validPosition;
    }
    for (int k = 0; k < length; k++)
    {
        if (m_playerBoard[row - k][col] != '.')
        {
            validPosition = false;
        }
    }
    return validPosition;
}

bool GameBoard::checkEast(int row, int col, int length)
{
    bool validPosition = true;
    if ((col + length) > 9)
    {
        validPosition = false;
        return validPosition;
    }
    for (int k = 0; k < length; k++)
    {
        if (m_playerBoard[row][col + k] != '.')
        {
            validPosition = false;
        }
    }
    return validPosition;
}

bool GameBoard::checkSouth(int row, int col, int length)
{
    bool validPosition = true;
    if ((row + length) > 9)
    {
        validPosition = false;
        return validPosition;
    }
    for (int k = 0; k < length; k++)
    {
        if (m_playerBoard[row + k][col] != '.')
        {
            validPosition = false;
        }
    }
    return validPosition;
}

bool GameBoard::checkWest(int row, int col, int length)
{
    bool validPosition = true;
    if ((col - length) < 0)
    {
        validPosition = false;
        return validPosition;
    }
    for (int k = 0; k < length; k++)
    {
        if (m_playerBoard[row][col - k] != '.')
        {
            validPosition = false;
        }
    }
    return validPosition;
}

void GameBoard::randomPlaceShips()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> shipsPosition(0, 9);
    array<int, 4> ships {4, 3, 2, 1};
    int typeOfShips = 0;
    int numberOfShips = 0;
    fillPlayerBoard();
    
    while (ships[typeOfShips] != 0)
    {
        while (true)
        {
            int row = shipsPosition(mt);
            int col = shipsPosition(mt);
            int direct = shipsPosition(mt) % 4;
            Direction dir;
            
            if (checkPosition(direct, typeOfShips + 2, row, col, dir))
            {
                Ship newShip(row, col, typeOfShips + 2, dir);
                m_ships[numberOfShips] = newShip;
                placeShip(row, col, typeOfShips + 2, dir, numberOfShips);
                numberOfShips++;
                break;
            }
        }
        ships[typeOfShips]--;
        if (ships[typeOfShips] == 0)
        {
            if (typeOfShips == 3)
            {
                break;
            }
            typeOfShips = typeOfShips + 1;
        }
    }
}

void GameBoard::placeShip(int row, int col, int length, Direction dir, int index)
{
    switch (dir)
    {
        case Direction::north:
        {
            for (int k = 0; k < length; k++)
            {
                m_playerBoard[row - k][col] = index + 48;
            }
            break;
        }
        case Direction::east:
        {
            for (int k = 0; k < length; k++)
            {
                m_playerBoard[row][col + k] = index + 48;
            }
            break;
        }
        case Direction::south:
        {
            for (int k = 0; k < length; k++)
            {
                m_playerBoard[row + k][col] = index + 48;
            }
            break;
        }
        case Direction::west:
        {
            for (int k = 0; k < length; k++)
            {
                m_playerBoard[row][col - k] = index + 48;
            }
            break;
        }
    }
}
