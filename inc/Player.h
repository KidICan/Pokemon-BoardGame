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
	std::string name;
	int YorN;
	int opt;
	

public:
	
	Player();
	//here we simply set the values for each value for the player
	void GetName();
	
	void PlayerName();

	int DieRoll();

	int GetOption();
	
	void SetOption();

	void SetGender();

	int GetGender();

	void OptionSelect();

	bool TryCatch();

	void BattleSequence(bool, int);
    
    int Battle(Pokemon, Pokemon, Move);

};


#endif
