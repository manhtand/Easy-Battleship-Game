#ifndef part_hpp
#define part_hpp

#include <stdio.h>

class Part
{
public:
    
    Part(int row, int col);
    
    bool isDamaged() const;
    
    void setDamaged();
    
    int getRow() const;
    
    int getCol() const;
    
private:
    
    int m_row;
    
    int m_col;
    
    int m_status;
};

#endif /* part_hpp */
