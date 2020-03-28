#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

typedef class Item
{
private:
	std::string name;
	int price;
	
public:

	Item(string,int);

	int GetPrice();

	std::string GetName();
	
	
};
#endif