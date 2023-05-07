
#include "player.hpp"
#include "game.hpp"

using namespace std;

Player::Player(std::string name): 
name(name) , deck({}){
};

int Player::stacksize()
{
    return 0;
}
int Player::cardesTaken()
{
    return 0;
}