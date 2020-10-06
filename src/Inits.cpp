#include "Inits.h"
#include <Pokemon.h>
#include <string>
#include <map>
using namespace std;

Inits::Inits(){
    dMove = initMoves();
    dMon = initMon();
}


map<string, Move> Inits::initMoves(){
    map<string, Move> tMap;
    
    //all moves will currently have base 5 power value.
    tMap["Psyshock"] = Move ("Psyshock", 5, 6);
    
    tMap["Mind Strike"] = Move ("Mind Strike", 5, 4);
    
    tMap["Bash"] = Move ("Bash", 5, 2);
    
    tMap["Electrocute"] = Move ("Electrocute", 5, 5);
    
    return tMap;
}

map<string, Pokemon> Inits::initMon(){
    map<string, Pokemon> tMon;
    
    tMon["Mewtwo"] = Pokemon ("Mewtwo", 1, 75, 5, dMove["Psyshock"], dMove["Mind Strike"]);
    
    tMon["Mew"] = Pokemon ("Mew", 1, 100, 5, dMove["Electrocute"], dMove["Bash"]);
    
    return tMon;
}
