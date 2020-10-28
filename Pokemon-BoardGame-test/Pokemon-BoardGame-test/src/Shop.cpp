#include <Item.h>
#include <Shop.h>
#include <Player.h>
#include <Bag.h>
#include <iostream>

using namespace std;
extern Bag bag;
 Item pokeball("pokeball",50);
 Item potion("potion",50);
 Item hyper_potion("Hyper_Potion",100);
//This is the shop function, we are going to call this function will only be able to be called in the overwolrd funcion
void Shop(int money)
{
	

	int opt=0;
	int YorN;
	int itmAmount;
	
	
	std::cout<<"Welcome to the shop! What can we sell you? The options are the follwing: "<<endl;
	std::cout<<"1. Pokeball ($"<<pokeball.GetPrice()<<")"<<endl;
	std::cout<<"2. Potion ($"<<potion.GetPrice()<<")"<<endl;
	std::cout<<"3. SuperPotion ($"<<hyper_potion.GetPrice()<<")"<<endl;
	std::cout<<"If you are done here simply press 0."<<endl;
	std::cout<<"Just a reminder you have "<< bag.GetMoney()<< " dollars"<<endl;

	std::cin>>opt;
	std::cout<<endl;	
	

	//If the player has 0 dollars then he will be sent back to the option select untill he presses 0
	if(bag.GetMoney()<=0)
	{
		std::cout<<"You are out of money! Go fight more trianers, or sell your pokiman."<<endl; 
		Shop(bag.GetMoney());
	}
	//We will keep asking for an input untill the player does not want to do anything else
	while(opt!=0)
	{
		if(opt == 1 )
		{
			cout<<"You have chosen a Pokibal. This item will let you catch one pokiman per ball"<<endl;
			cout<<"How many pokeballs do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(bag.GetMoney()<(pokeball.GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(bag.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " Pokeball!"<<endl;
					bag.SetMoney(bag.GetMoney()-(pokeball.GetPrice()*itmAmount));
				cout<<"You now have "<<bag.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm("pokeball",itmAmount);
					Shop(bag.GetMoney());
					opt=0;
				}
		}

		
	

		if(opt == 2 )
		{
			cout<<"You have chosen a Potion. This item will let heal one of your Pokiman by 1/4 its health"<<endl;
			cout<<"How many Potions do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(bag.GetMoney()<(potion.GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(bag.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " Potions!"<<endl;
					bag.SetMoney(bag.GetMoney()-(potion.GetPrice()*itmAmount));
				cout<<"You now have "<<bag.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm("potion",itmAmount);					
					Shop(bag.GetMoney());
					opt=0;
				}
		}
	
		if(opt == 3 )
		{
			cout<<"You have chosen a SuperPotion . This item will let you heal 1/2 your health"<<endl;
			cout<<"How many SuperPotions do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(bag.GetMoney()<(hyper_potion.GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(bag.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " SuperPotions!"<<endl;
					bag.SetMoney(bag.GetMoney()-(hyper_potion.GetPrice()*itmAmount));
				cout<<"You now have "<<bag.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm("hyper_potion",itmAmount);							
					Shop(bag.GetMoney());
					opt=0;
				}
		}

		
	


		
	}


}
