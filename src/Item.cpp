#include <Item.h>
#include <iostream>

Item::Item(){
    type = ItemType::Heal;
    name = "";
    price = 0;
    val = 0;
}

Item::Item(ItemType i, string x, int p, int v){
    type = i;
    name = x;
    price = p;
    val = v;
}

ItemType Item::getType(){
    return type;
}

string Item::getName(){
    return name;
}

int Item::getPrice(){
    return price;
}

int Item::getVal(){
    return price;
}
