
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <Pokemon.h>
#include <Player.h>
#include <Bag.h>
#include <Inits.h>
#include <map>
using namespace std;

Player player1;
Inits repo;
Bag bag;
vector<Pokemon> Mon;

int main()
{
    vector<Pokemon> starters = {repo.dMon["Bulbasaur"], repo.dMon["Charmander"], repo.dMon["Squirtle"]};
    string temp;
    cout << "Welcome to the World of Pokiman. (Press Enter to continue)"<< endl;
    cin.ignore();
    cout << "My name is Professor Mike Hawk. I'm a former League Champion." << endl;
    cin.ignore();
    cout << "And though I could go on and on about how awesome I am, I want to know more about you." << endl;
    cin.ignore();
    cout << "First things first! What is your name?" << endl;
    player1.GetName();
    
    bool first = false;
    string opt = "";
    while (player1.isNumeric(opt))
    {
        cout << "Just making sure, your name is " << temp << "?" << endl;
        if (!first){cout << "Please select from the numbers." << endl;}
        cout << "1. Yes, that's my name." << endl;
        cout << "2. No, that's not my name." << endl;
        cin >> opt;
    }
    
    while(player1.GetOption() == 2)
    {
        cout<<"Sorry, my bad, what's your name?"<<endl;
        player1.GetName();
        cout<<endl;
        
        cout<<"Is ";
        player1.PlayerName();
        cout<<" correct ? 0 for no, 1 for yes"<<endl;
        player1.SetOption();
        cout<<endl;
    }
    
    cout << "-------------------------------------------------------------------\n" << endl;
    
    cout << "Awesome!" <<endl;
    cout << "Your name is ";
    player1.PlayerName();
    cout << endl;
    cout << "Now tell me, are you a boy or a girl? " << endl;
    cout << "If you are a boy press 1, if you are a girl, press 0." << endl;
    
    player1.SetGender();
    
    cout<< "Just making sure, you are a ";
    if (player1.GetGender() == 1)
    {
        cout<< "boy";
    }
    else
        cout << "girl";
    cout << "?" << endl;
    cout << " If it's not true, press 0, if it is, press 1"<<endl;
    player1.SetOption();
    cout<<endl;
    while(player1.GetOption()== 0)
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
        player1.SetOption();
        cout<<endl;
    }
    
    cout << "-------------------------------------------------------------------\n" << endl;
    
    cout<<"Great! Nice to meet you ";
    player1.PlayerName();
    cout<<" !" <<endl;
    cout<<"\nFor you to be able to become the very best, you are going to need a partner." << endl;
    cout<<"Please select from one of the three pokemon available." << endl;
    
    while(bag.ViewCatchedMon()==0)
    {
        cout << "1. " << starters[0].GetName() << endl;
        cout << "2. " << starters[1].GetName() << endl;
        cout << "3. " << starters[2].GetName() << endl;
        cout<<"Which pokiman will be there through your journey? "<<endl;
        
        player1.SetOption();
        cout << endl;
        
        cout<<"You have chosen " << starters[player1.GetOption() - 1].GetName() << endl;;
        
        cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
        player1.SetOption();
        cout<<endl;
        if(player1.GetOption()==1)
        {
            cout << starters[player1.GetOption() - 1].GetName() << " is now your new Pokiman Companion!!" << endl;
            bag.AddCatched(starters[player1.GetOption() - 1]);
        }
    }
    
    cout<<"Awesome! Now that you have your Pokiman, you are now able to go and andventure and become the very best!."<<endl;
    cin.ignore();
    cout<<"Time to introduce you to the Option Select menu"<<endl;
    cout<<endl;
    cout<<"What are we doing next?" << endl;
    cout<<"Press 1 to go to the Shop." << endl;
    cout<<"Press 2 to go to YourBag." << endl;
    cout<< "Press 3 to go to Try & Catch." << endl;
    cout << "Press 4 to go to TrainerBattle." << endl;
    cout << "These are going to be the your options through out your journey."<<endl;
    cout << endl;
    cout<<"(Press enter to continue)";
    cin.ignore();
    cout<<endl;
    
    cout<<"Before anything you should go to the shop and buy some Pokiballs and potions. You wont be able to go through out your journey with out them." << endl;
    player1.OptionSelect();
}
