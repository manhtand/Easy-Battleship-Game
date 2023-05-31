#include "part.hpp"

Part::Part(int row, int col) : m_row(row), m_col(col), m_status(0)
{}

int Part::getCol() const
{
    return m_col;
}

int Part::getRow() const
{
    return m_row;
}

bool Part::isDamaged() const
{
    if (m_status == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Part::setDamaged()
{
    m_status = 1;
}


