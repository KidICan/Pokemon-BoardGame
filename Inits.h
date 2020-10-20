#ifndef INITS_H
#define INITS_H

#include <Pokemon.h>
#include <string>
#include <map>
using namespace std;


typedef class Inits{
public:
    map<string, Move> dMove;
    map<string, Pokemon> dMon;
    
    Inits();
    
    map<string, Move> initMoves();
    map<string, Pokemon> initMon();
};
#endif
