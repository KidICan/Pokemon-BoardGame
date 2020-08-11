
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <Pokemon.h>
#include <Player.h>
#include <Bag.h>




int main()
{
	
	extern Player player1;
	extern Bag bag;
	extern std::vector<Pokemon> Mon;


	

	std::cout<<"Welcome to the World of Pokiman. (Press Enter to continue)"<< endl;
	std::cin.ignore();
	std::cout<< "I am profressor Benjamin Dover. I am a world known pokemaster." <<endl;
	std::cin.ignore();
	std::cout<< "I could go on and on about how awesome I am, but I want to know more about you."<< endl;
	std::cin.ignore();
	std::cout<< "First thigs first! What is your name?"<<endl;
		player1.GetName();
	std::cout<<endl;
	std::cout<< "Just making sure, your name is ";
		player1.PlayerName();
	std::cout<<" ?"<<endl;
	std::cout<< " If it's not, press 0, if it is, press 1"<<endl;
		player1.SetResponse();
	std::cout<<endl;
	
		while(player1.GetResponse()== 0)
		{
			
			std::cout<<"Sorry, my bad, what's your name?"<<endl;
			player1.GetName();
			std::cout<<endl;
			
			std::cout<<"Is ";
			player1.PlayerName();
			std::cout<<" correct ? 0 for no, 1 for yes"<<endl;
			player1.SetResponse(); 
			std::cout<<endl;
			
		}

	std::cout <<"Awesome!" <<endl;
	std::cout<< "Your name is ";
		player1.PlayerName();
	std::cout<<endl;
	std::cout<< "Now tell me, are you a boy or a girl? "<< endl;
	std::cout<<"If you are a boy press 1, if you are a girl, press 0."<<endl;
	
		player1.SetGender();
	
	std::cout<< "Just making sure, you are a ";
		if (player1.GetGender() == 1)
		{
			std::cout<< "boy";
		}
		else
			std::cout << "girl";
	std::cout<<" ?"<<endl;
	std::cout<< " If it's not true, press 0, if it is, press 1"<<endl;
		player1.SetResponse();
	std::cout<<endl;
		while(player1.GetResponse()== 0)
		{
			std::cout<< "Sorry about that. Let's try that again "<<endl;
			std::cout<<" If you are a boy press 1, if your a girl press 0."<< endl;
				player1.SetGender();
				if (player1.GetGender() == 1)
			{
				std::cout<< "boy";
			}
				else
					std::cout << "girl";
			std::cout<<"? Is that right? 0 for no, 1 for yes."<<endl;
			player1.SetResponse();
			std::cout<<endl;
		}
	

	std::cout<<"Great! Nice to meet you ";
	player1.PlayerName();
	std::cout<<" !"<<endl;
	std::cout<<"For you to be able to become the very best, you are goign to need a partner."<<endl;
	std::cout<<"Your options are the following; "<<endl;
	

	while(bag.ViewCatchedMon()==0)
	{
		std::cout<<"Option 1 is "<<Mon[0].GetName()<<endl;
		std::cout<<"Option 2 is "<<Mon[1].GetName()<<endl;
		std::cout<<"Which pokiman will will be there through your journey? "<<endl;	
	
		player1.SetOption();
		std::cout<<endl;	
		if(player1.GetOption()==1)
		{
			std::cout<<"You have chosen "<<Mon[0].GetName()<<endl;
			std::cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				player1.SetResponse();
				std::cout<<endl;
					if(player1.GetResponse()==1)
					{
						std::cout<<Mon[0].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						bag.AddCatched(Mon[0]);
					}
								
					if(player1.GetResponse()==0)
					{
						std::cout<<"Ok, not "<<Mon[0].GetName()<<endl;
						
					}
				
		}

		if(player1.GetOption()==2)
		{
			std::cout<<"You have chosen "<<Mon[1].GetName()<<endl;
			std::cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				player1.SetResponse();
				std::cout<<endl;
					if(player1.GetResponse()==1)
					{
						std::cout<<Mon[1].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						bag.AddCatched(Mon[1]);
					}
								
					if(player1.GetResponse()==0)
					{
						std::cout<<"Ok, not " << Mon[1].GetName()<<endl;
					}
		}
	}
	std::cout<<"Awesome! Now that you have your Pokiman, you are now able to go and andventure and become the very best!."<<endl;
	std::cin.ignore();
	std::cout<<"Time to introduce you to the Option Select menu"<<endl;
	std::cout<<endl;
	std::cout<<"What are we doing next?"<<endl;
	std::cout<<"Press 1 to go to the Shop."<<endl;
	std::cout<<"Press 2 to go to  YourBag."<<endl;
	std::cout<<"Press 3 to go to Try&Catch."<<endl;
	std::cout<<"Press 4 to go to TrainerBattle."<<endl;
	std::cout<<"These are goign to be the your options through out your journey."<<endl;
	std::cout<<endl;
	std::cout<<"(Press enter to continue)";	
	std::cin.ignore();
	std::cout<<endl;
	
	
	std::cout<<"Before anything you should go to the shop and buy some Pokiballs and potions. You wont be able to go through out your journey with out them."<<endl;
		player1.OptionSelect();		
}

