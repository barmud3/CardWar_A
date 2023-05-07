#include "doctest.h"
#include <stdexcept>
#include <cstring>  
#include <vector>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("printStats before game start")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printStats());
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("name can't contain strange chars from asci table")
{
    for (size_t i = 0; i <= 64; i++)
    {
        CHECK_THROWS(Player("barmud" +to_string(static_cast<char>(i))));
    }
    
    for (size_t i = 91; i <= 96; i++)
    {
        CHECK_THROWS(Player("barmud" + to_string(static_cast<char>(i))));
    }

    for (size_t i = 123; i <= 127; i++)
    {
        CHECK_THROWS(Player("barmud" + to_string(static_cast<char>(i))));
    }
}


TEST_CASE("name equal therefore,add family name or change to nickname")
{
    Player p1("Alice");
    Player p2("Alice");
    CHECK_THROWS(Game(p1,p2));
}

TEST_CASE("players can't play against himself")
{
    Player p1("Alice");
    Player p2 = p1;
    CHECK_THROWS(Game(p1,p2));
}

TEST_CASE("Each player get exactly half the game deck at beginning.")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

TEST_CASE("Game know to work with null")
{
    Player* nullPlayer = nullptr;
    Player p2("Alice");
    CHECK_THROWS(Game(*nullPlayer, p2));
    CHECK_THROWS(Game(p2, *nullPlayer));
    CHECK_THROWS(Game(*nullPlayer, *nullPlayer));
}

TEST_CASE("somthing wrong with your deck")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    //at the start of the game:
    //*each player's counter of cards won is 0
    //*the game deck isn't empty in both of the players
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 0);
    CHECK(p1.stacksize() + p2.stacksize() == 52);

    
    //in the middle of the game:
     //cards that go to jackpot or player won them(go to cardsTaken)
    int cardsOutOfGame = 2;
    //*total counter of cards won is at least num of rounds * cardsOutOfGame) 
    //*the total cards that left are < num of rounds * cardsOutOfGame
    
    while (p1.stacksize() !=0 && p2.stacksize() !=0)
    {
        game.playTurn();
        CHECK(p1.cardesTaken() + p2.cardesTaken() >= cardsOutOfGame);
        CHECK(p1.stacksize() + p2.stacksize() <= 52-cardsOutOfGame);
        cardsOutOfGame+=2; //each round at least two cards go to jackpot
        CHECK(cardsOutOfGame <= 52); //after 52 cards , the game over.
    }

    //at the end of the game:
    //*num in the deck of each player is 0
    //*through the game , jackpot divide bettwen players.
    CHECK(p1.stacksize() + p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}

TEST_CASE("Game repeat itself")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    vector <std::string> game1Stats;
    vector <std::string> game2Stats;
    int lastP1Cards = 0;
    int lastP2Cards = 0;
    while (p1.stacksize()!=0 && p2.stacksize()!=0)
    {
        game1.playTurn();
        if (p1.cardesTaken() > lastP1Cards)
        {
            game1Stats.push_back("Alice");
            lastP1Cards = p1.cardesTaken();
        }
        else
        {
            game1Stats.push_back("Bob");
            lastP2Cards = p2.cardesTaken();
        }
    }

    Game game2(p1,p2);
    lastP1Cards = 0;
    lastP2Cards = 0;

    while (p1.stacksize()!=0 && p2.stacksize()!=0)
    {
        game1.playTurn();
        if (p1.cardesTaken() > lastP1Cards)
        {
            game2Stats.push_back("Alice");
            lastP1Cards = p1.cardesTaken();
        }
        else
        {
            game2Stats.push_back("Bob");
            lastP2Cards = p2.cardesTaken();
        }
    }

    int same = 0;
    int minRounds = min(game1Stats.size(),game2Stats.size());
    for (size_t i = 0; i < minRounds; i++)
    {
        if (game1Stats[i] == game2Stats[i])
        {
            same ++;
        }
    }
    //at least 10% diff
    CHECK(same < minRounds*0.9);
}

TEST_CASE("Players can't play at two games at the same time")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1,p2);
    CHECK_THROWS(Game(p1,p2));
}


TEST_CASE("Continue play but game arleady over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();

    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
}


