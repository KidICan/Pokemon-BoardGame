#ifndef INITS_H
#define INITS_H

#include <Pokemon.h>
#include <string>
#include <map>
#include <Item.h>
using namespace std;

typedef class Inits{
public:
    map<string, Move> dMove;
    map<string, Pokemon> dMon;
    map<string, Item> dItem;
    
    Inits();
    
    map<string, Move> initMoves();
    map<string, Pokemon> initMon();
    map<string, Item> initItems();
};
#endif
