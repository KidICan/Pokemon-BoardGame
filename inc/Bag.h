#ifndef BAG_H
#define BAG_H
#include <Pokemon.h>
#include <Item.h>
#include <map>
#include <vector>

class Bag
{
private:

map <string,int > Items;

vector <Pokemon> PlayerMon;

int money;

public:


		
	Bag();

	void AddItm(string, int);

	int InsideBag();

	void AddCatched(Pokemon);

	int ViewCatchedMon();

	Pokemon& MonSelect();
	
	int GetMoney();
	
	void SetMoney(int);

	int NoOneLeft();

};
#endif