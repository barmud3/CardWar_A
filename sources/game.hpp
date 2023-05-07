#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
#include "player.hpp"
using namespace std;

class Game{
    
    private:
    Player& p1;
    Player& p2;
    public:
    Game(Player& player1 , Player& players2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};

#endif