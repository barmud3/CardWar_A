#include <iostream>
using namespace std;
#include "sources/player.hpp"

int main(int argc, char const *argv[])
{
    Player p1("Alice");
    Player p2("Alice");
    std::string name = *((std::string*) &p1);
    cout << name;
    return 0;
}

