#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{}

Player::Player(const string& playerName) : m_gamesWon(0), m_gamesLost(0), m_playerName(playerName)
{}

void Player::addGameWon()
{
    m_gamesWon++;
}

void Player::addGameLost()
{
    m_gamesLost++;
}

int Player::getGamesWon() const
{
    return m_gamesWon;
}

int Player::getGamesLost() const
{
    return m_gamesLost;
}

int Player::getGamesPlayed() const
{
    return m_gamesWon + m_gamesLost;
}

string Player::getName()
{
    return m_playerName;
}
