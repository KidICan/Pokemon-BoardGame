#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

enum ItemType {Ball, Heal};
typedef class Item
{
private:
    ItemType type;
    string name;
    int price;
    int val; //generic val
    
public:
    
    Item();
    
    Item(ItemType, string, int, int);
    
    ItemType getType();
    
    string getName();
    
    int getPrice();
    
    int getVal();
};
#endif
