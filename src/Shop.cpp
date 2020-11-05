#include <Item.h>
#include <Shop.h>
#include <Player.h>
#include <Bag.h>
#include <iostream>
#include <Inits.h>
using namespace std;
extern Bag bag;
extern Inits repo;
//This is the shop function, we are going to call this function will only be able to be called in the overwolrd funcion
void Shop(int money)
{

	int opt = 0;
	int YorN;
	int itmAmount;

	std::cout << "Welcome to the shop! What can we sell you? The options are the follwing: " << endl;
	map<string, Item>::iterator it;
	int counter = 0;
	for (it = repo.dItem.begin(); it != repo.dItem.end(); it++)
	{
		counter++;
		cout << counter << ". " << it->first << " ($" << it->second.getPrice() << ")" << endl;
	}
	cout << "You have " << bag.GetMoney() << endl;
	cout << "If you are done here press 0" << endl;
	std::cin >> opt;
	std::cout << endl;

	if (opt != 0)
	{
		int counter = 0;
		string selectedItem;
		for (it = repo.dItem.begin(); it != repo.dItem.end(); it++)
		{
			counter++;
			if (counter == opt)
			{
				selectedItem = it->first;
			}
		}

		//If the player has 0 dollars then he will be sent back to the option select untill he presses 0
		if (bag.GetMoney() <= 0)
		{
			std::cout << "You are out of money! Go fight more trianers, or sell your pokiman." << endl;
		}
		else
		{

			//We will keep asking for an input untill the player does not want to do anything else

			cout << "How many" << selectedItem << "do you want to buy?" << endl;
			cin >> itmAmount;
			cout << endl;

			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if (bag.GetMoney() < (repo.dItem[selectedItem].getPrice() * itmAmount))
			{
				cout << "Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman." << endl;
			}
			else
			{
				cout << "Would you like to purchase " << itmAmount << " of this item? 1 for yes, 0 for no. " << endl;

				//Here we take the option to buy or not to buy
				cin >> YorN;
				cout << endl;
				if (YorN = 1)
				{
					cout << "You bough " << itmAmount << selectedItem << endl;
					bag.SetMoney(bag.GetMoney() - (repo.dItem[selectedItem].getPrice() * itmAmount));
					cout << "You now have " << bag.GetMoney() << " dollars." << endl
						 << endl;
					bag.AddItm(selectedItem, itmAmount);
				}
			}
		}
		Shop(bag.GetMoney());
	}
}