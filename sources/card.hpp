#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel{}
using namespace ariel;

enum values {Ace=1 ,Two ,Three ,Four ,Five ,Six ,Seven ,Eight ,Nine ,Ten ,Jack ,Queen ,King };
enum shape {Diamond=1 ,Heart ,Spade ,Club };

class Card{
    private:
    values val;
    shape sha;
    public:
    Card(values val , shape sha):val(val) , sha(sha){};
};



#endif