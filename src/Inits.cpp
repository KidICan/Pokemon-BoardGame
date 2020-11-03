#include "Inits.h"
#include <Pokemon.h>
#include <string>
#include <Item.h>
#include <map>
using namespace std;

Inits::Inits(){
    dMove = initMoves();
    dMon = initMon();
    dItem = initItems();
}

map<string, Move> Inits::initMoves(){
    map<string, Move> tMap;
    
    //all moves will currently have base 5 power value.
    tMap["Psyshock"] = Move ("Psyshock", 2, 2);
    
    tMap["Mind Strike"] = Move ("Mind Strike", 2, 2);
    
    tMap["Bash"] = Move ("Bash", 1, 2);
    
    tMap["Electrocute"] = Move ("Electrocute", 1, 2);
    
    return tMap;
}

map<string, Pokemon> Inits::initMon(){
    map<string, Pokemon> tMon;
    
    tMon["Mewtwo"] = Pokemon ("Mewtwo", 1, 5, 5, dMove["Psyshock"], dMove["Mind Strike"]);
    
    tMon["Mew"] = Pokemon ("Mew", 1, 5, 5, dMove["Electrocute"], dMove["Bash"]);
    
    tMon["Bulbasaur"] = Pokemon ("Bulbasaur", 1, 5, 5, dMove["Electrocute"], dMove["Bash"]);
    
    tMon["Charmander"] = Pokemon ("Charmander", 1, 5, 5, dMove["Electrocute"], dMove["Bash"]);
    
    tMon["Squirtle"] = Pokemon ("Squirtle", 1, 5, 5, dMove["Electrocute"], dMove["Bash"]);
    
    return tMon;
}

map<string, Item> Inits::initItems(){
    map<string, Item> tItem;
    
    Item temp = Item (ItemType::Heal, "Potion", 50, 20);
    
    tItem["Potion"] = Item (ItemType::Heal, "Potion", 50, 20);
    
    tItem["Pokeball"] = Item (ItemType::Ball, "Pokeball", 50, 10);
    
    tItem["Superball"] = Item (ItemType::Ball, "Superball", 100, 50);
    
    tItem["Hyper Potion"] = Item (ItemType::Heal, "Hyper Potion", 100, 60);
    
    return tItem;
}
