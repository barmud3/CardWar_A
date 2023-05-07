#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"

class Player
{
    private:
    std::string name;
    std::vector<Card> deck;
    public:
    Player(std::string name);
    int stacksize();
    int cardesTaken();
};



#endif