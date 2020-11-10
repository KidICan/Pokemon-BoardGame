#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <Pokemon.h>
using namespace std;


//This is the player class

class Player
{
private:
	int gender;
	string name;
	int opt;
	
public:
	
	Player();
	//here we simply set the values for each value for the player
    
    string getName();

    void setName(string);

	int DieRoll();

	int GetOption();
	
	void SetOption();

	void SetGender();

	int GetGender();

	void OptionSelect();

	bool TryCatch();
    
    bool isNumeric(string s);
    
    int returnInt(string);

	void BattleSequence(bool, int);
    
    bool isValidInputRange(string, int, int);
    
    //int Battle(Pokemon, Pokemon, Move);

};


#endif
