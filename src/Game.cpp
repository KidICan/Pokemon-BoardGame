
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
    string opt;
    string opt2;
    cout << "Welcome to the World of Pokiman. (Press Enter to continue)"<< endl;
    cin.ignore();
    cout << "My name is Professor Mike Hawk. I'm a former League Champion." << endl;
    cin.ignore();
    cout << "And though I could go on and on about how awesome I am, I want to know more about you." << endl;
    cin.ignore();
    cout << "First things first! What is your name?" << endl;
    cin >> opt2;
    
    opt = "-1";
    cout << "Just making sure, your name is " << opt2 << "?" << endl;
    while (!player1.isValidInputRange(opt, 1, 2) || player1.returnInt(opt) == 2)
    {
        if (player1.returnInt(opt) == 2){
            cout << "Okay then, what's your name?" << endl;
            opt = "-1";
            cin >> opt2;
        }
        else{
            cout << "Just making sure, your name is " << opt2 << "?" << endl;
            cout << "1. Yes, that's my name." << endl;
            cout << "2. No, that's not my name." << endl;
            cin >> opt;
        }
        cout << "---------------------------------------------------" << endl;
    }
    
    player1.setName(opt2);
    
    cout << "------------------------------------------------------" << endl;
    
    cout << "Ah so your name is " << player1.getName() << endl;
    
    
    opt = "-1";
    
    while (!player1.isValidInputRange(opt, 1, 2) || player1.returnInt(opt) == 0)
    {
        if (player1.returnInt(opt) == 0){
            cout << "Okay then, which one?" << endl;
            opt = "-1";
            cout << "1. Boy" << endl;
            cout << "2. Girl" << endl;
        }
        else{
            out << "Now tell me, are you a boy or a girl?" << endl;
            cout << "1. Boy" << endl;
            cout << "2. Girl" << endl;
            cin >> opt;
            //this is wrong but it's a start
            
            cout << "Just making sure, you are a " << opt2 << "?" << endl;
            cout << "1. Yes, that's correct." << endl;
            cout << "0. No, that's wrong" << endl;
            cin >> opt;
        }
        cout << "---------------------------------------------------" << endl;
    }
    
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
    
    cout<<"Great! Nice to meet you " << player1.getName() << "!" <<endl;
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
        
        int selPoke = player1.GetOption() - 1;
        
        cout<<"You have chosen " << starters[selPoke].GetName() << endl;;
        
        cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
        player1.SetOption();
        cout<<endl;
        if(player1.GetOption()==1)
        {
            cout << starters[selPoke].GetName() << " is now your new Pokiman Companion!!" << endl;
            bag.AddCatched(starters[selPoke]);
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
