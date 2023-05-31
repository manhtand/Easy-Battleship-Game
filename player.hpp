#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Player
{
public:
    
    Player();
    
    Player(const string& playerName);
    
    int getGamesWon() const;
    
    int getGamesLost() const;
    
    int getGamesPlayed() const;
    
    void addGameWon();
    
    void addGameLost();
    
    string getName();
    
    
private:
    
    int m_gamesWon;
    
    int m_gamesLost;
    
    string m_playerName;
};

#endif /* player_hpp */
