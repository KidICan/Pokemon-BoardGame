
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <Pokemon.h>
#include <Player.h>
#include <Bag.h>
using namespace std;

int main()
{
	
	extern Player player1;
	extern Bag bag;
    extern vector<Pokemon> Mon;
    extern map<string, Move> moveDict;
    extern map<string, Pokemon> pokeDex;
    
    moveDict = initMoves();
    pokeDex = initMon();

	cout<<"Welcome to the World of Pokiman. (Press Enter to continue)"<< endl;
	cin.ignore();
	cout<< "I am profressor Benjamin Dover. I am a world known pokemaster." <<endl;
	cin.ignore();
	cout<< "I could go on and on about how awesome I am, but I want to know more about you."<< endl;
	cin.ignore();
	cout<< "First thigs first! What is your name?"<<endl;
		player1.GetName();
	cout<<endl;
	cout<< "Just making sure, your name is ";
		player1.PlayerName();
	cout<<" ?"<<endl;
	cout<< " If it's not, press 0, if it is, press 1"<<endl;
		player1.SetResponse();
	cout<<endl;
	
		while(player1.GetResponse()== 0)
		{
			
			cout<<"Sorry, my bad, what's your name?"<<endl;
			player1.GetName();
			cout<<endl;
			
			cout<<"Is ";
			player1.PlayerName();
			cout<<" correct ? 0 for no, 1 for yes"<<endl;
			player1.SetResponse(); 
			cout<<endl;
			
		}

	cout <<"Awesome!" <<endl;
	cout<< "Your name is ";
		player1.PlayerName();
	cout<<endl;
	cout<< "Now tell me, are you a boy or a girl? "<< endl;
	cout<<"If you are a boy press 1, if you are a girl, press 0."<<endl;
	
		player1.SetGender();
	
	cout<< "Just making sure, you are a ";
		if (player1.GetGender() == 1)
		{
			cout<< "boy";
		}
		else
			cout << "girl";
	cout<<" ?"<<endl;
	cout<< " If it's not true, press 0, if it is, press 1"<<endl;
		player1.SetResponse();
	cout<<endl;
		while(player1.GetResponse()== 0)
		{
			cout<< "Sorry about that. Let's try that again "<<endl;
			cout<<" If you are a boy press 1, if your a girl press 0."<< endl;
				player1.SetGender();
				if (player1.GetGender() == 1)
			{
				cout<< "boy";
			}
				else
					cout << "girl";
			cout<<"? Is that right? 0 for no, 1 for yes."<<endl;
			player1.SetResponse();
			cout<<endl;
		}
	

	cout<<"Great! Nice to meet you ";
	player1.PlayerName();
	cout<<" !"<<endl;
	cout<<"For you to be able to become the very best, you are goign to need a partner."<<endl;
	cout<<"Your options are the following; "<<endl;
	

	while(bag.ViewCatchedMon()==0)
	{
		cout<<"Option 1 is "<<Mon[0].GetName()<<endl;
		cout<<"Option 2 is "<<Mon[1].GetName()<<endl;
		cout<<"Which pokiman will will be there through your journey? "<<endl;
	
		player1.SetOption();
		cout<<endl;
		if(player1.GetOption()==1)
		{
			cout<<"You have chosen "<<Mon[0].GetName()<<endl;
			cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				player1.SetResponse();
				cout<<endl;
					if(player1.GetResponse()==1)
					{
						cout<<Mon[0].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						bag.AddCatched(Mon[0]);
					}
								
					if(player1.GetResponse()==0)
					{
						cout<<"Ok, not "<<Mon[0].GetName()<<endl;
						
					}
				
		}

		if(player1.GetOption()==2)
		{
			cout<<"You have chosen "<<Mon[1].GetName()<<endl;
			cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				player1.SetResponse();
				cout<<endl;
					if(player1.GetResponse()==1)
					{
						cout<<Mon[1].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						bag.AddCatched(Mon[1]);
					}
								
					if(player1.GetResponse()==0)
					{
						cout<<"Ok, not " << Mon[1].GetName()<<endl;
					}
		}
	}
	cout<<"Awesome! Now that you have your Pokiman, you are now able to go and andventure and become the very best!."<<endl;
	cin.ignore();
	cout<<"Time to introduce you to the Option Select menu"<<endl;
	cout<<endl;
	cout<<"What are we doing next?"<<endl;
	cout<<"Press 1 to go to the Shop."<<endl;
	cout<<"Press 2 to go to  YourBag."<<endl;
	cout<<"Press 3 to go to Try&Catch."<<endl;
	cout<<"Press 4 to go to TrainerBattle."<<endl;
	cout<<"These are goign to be the your options through out your journey."<<endl;
	cout<<endl;
	cout<<"(Press enter to continue)";
	cin.ignore();
	cout<<endl;
	
	
	cout<<"Before anything you should go to the shop and buy some Pokiballs and potions. You wont be able to go through out your journey with out them."<<endl;
		player1.OptionSelect();		
}

map<string, Move> initMoves(){
    map<string, Move> tMap;
    
    //all moves will currently have base 5 power value.
    tMap["Psyshock"] = new Move ("Psyshock", 5, 6);
    
    tMap["Mind Strike"] = new Move ("Mind Strike", 5, 4);
    
    tMap["Bash"] = new Move ("Bash", 5, 2);
    
    tMap["Electrocute"] = new Move ("Electrocute", 5, 5);
    
    return tMap;
}

map<string, Pokemon> initMon(){
    map<string, Pokemon> tMon;
    
    tMon["Mewtwo"] =  new Pokemon ("Mewtwo", 1, 75, 5, moveDict["Psyshock"], moveDict["Mind Strike"]);
    
    tMon["Mew"] = new Pokemon ("Mew", 1, 100, 5, moveDict["Electrocute"], moveDict["Bash"]);
    
    return tMon;
}
