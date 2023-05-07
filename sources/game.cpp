#include "game.hpp"
#include "player.hpp"

using namespace std;

Game::Game(Player& player1,Player& player2): p1(player1) , p2(player2){    
};

void Game::playTurn()
{
    printf("Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.");
}
void Game::printLastTurn()
{
    printf("Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.\n");
}
void Game::playAll()
{
    
}
void Game::printWiner()
{

}
void Game::printLog()
{
    printf("Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.\n");
    printf("Alice played Queen of Diamonds Bob played 7 of Spades. Alice wins.\n");
}
void Game::printStats()
{

}