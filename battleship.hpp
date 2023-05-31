#ifndef battleship_hpp
#define battleship_hpp

#include "gameboard.hpp"
#include "player.hpp"

#include <string>
#include <array>
using namespace std;

class Battleship
{
public:
    
    Battleship(const string& player1Name, const string& player2Name);
    
    void play();
    
private:
    
    array<Player, 2> m_players;
    
    array<GameBoard, 2> m_boards;
    
    void turn(bool& playerTurn);
};

#endif /* battleship_hpp */
