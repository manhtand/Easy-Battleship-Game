#ifndef ship_hpp
#define ship_hpp

#include <stdio.h>
#include <vector>
using namespace std;

#include "part.hpp"

enum class Direction
{
    north,
    east,
    south,
    west,
};

class Ship
{
public:
    
    Ship();
    
    Ship(int row, int col, int lengthOfShip, Direction direction);
    
    bool hasPartin(int row, int col);
    
    Part& getPartin(int row, int col);
    
    bool isDamaged();
    
    bool isSunk();
    
private:
    
    vector<Part> m_parts;
};

#endif /* ship_hpp */
