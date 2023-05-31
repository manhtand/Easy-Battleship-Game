#include "ship.hpp"
#include <iostream>
#include <stdexcept>

Ship::Ship()
{}

Ship::Ship(int row, int col, int lengthOfShip, Direction direction)
{
    for (int i = 0; i < lengthOfShip; i++)
    {
        switch (direction)
        {
            case Direction::north:
            {
                m_parts.push_back(Part(row - i, col));
                break;
            }
            case Direction::east:
            {
                m_parts.push_back(Part(row, col + i));
                break;
            }
            case Direction::south:
            {
                m_parts.push_back(Part(row + i, col));
                break;
            }
            case Direction::west:
            {
                m_parts.push_back(Part(row, col - i));
                break;
            }
        }
    }
}

Part& Ship::getPartin(int row, int col)
{
    for (int i = 0; i < m_parts.size(); i++)
    {
        if ((row == m_parts[i].getRow()) && (col == m_parts[i].getCol()))
        {
            return m_parts[i];
        }
    }
    return m_parts[0];
}
    
bool Ship::hasPartin(int row, int col)
{
    for (Part p : m_parts)
    {
        if ((row == p.getRow()) && (col == p.getCol()))
        {
            return true;
        }
    }
    return false;
}

bool Ship::isDamaged()
{
    for (int i = 0; i < m_parts.size(); i++)
    {
        Part p = m_parts[i];
        if (p.isDamaged())
        {
            return true;
        }
    }
    return false;
}

bool Ship::isSunk()
{
    for (Part p : m_parts)
    {
        if (!p.isDamaged())
        {
            return false;
        }
    }
    return true;
}


