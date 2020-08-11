#include "Pokemon.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

	
	Pokemon Mew("Mew",100,"Befriend",25,"Tag",50,0,1);
	Pokemon Mewtwo("MewTwo",75,"Physchock",60,"MindStrike",40,0,1);
	std::vector<Pokemon> Mon{Mew,Mewtwo};
	
	

Pokemon::Pokemon(){
	name="po";
	Hp=0;
    attack1Pow=0;
    attack1Name="a";
	attack2Pow=0;
	attack2Name="b";
	exp=0;
	level=1;
}

Pokemon::Pokemon(std::string name_, int HP_, std::string attck1, int attack1Pow_, std::string attack2Name_, int attack2Pow_, int exp_, int level_){
    name=name_;
	Hp=HP_;
    attack1Pow=attack1Pow_;
    attack1Name=attck1;
	attack2Pow=attack1Pow_;
	attack2Name=attack2Name_;
	exp=exp_;
	level=level_;


};


std::string Pokemon::GetName()
{
   return name;
 }

 
void  Pokemon::SetName(std::string name)
{
	this->name=name;
}

void Pokemon::SetHp(int Hp)
{
	this->Hp=Hp;
}

int Pokemon::GetHP()
{
	return Hp;
}


int Pokemon::GetAttack1Pow()
{
	return attack1Pow;
}
std::string Pokemon::GetAttack1Name()
{
	return attack1Name;
}

void Pokemon::SetAttack1Pow(int attack1Pow)
{
	this->attack1Pow=attack1Pow;
}
void Pokemon::SetAttack1Name(std::string attack1Name)
{
	this->attack1Name=attack1Name;
}
int Pokemon::GetAttack2Pow()
{
	return attack2Pow;
}
		
std::string Pokemon::GetAttack2Name()
{
	return attack2Name;
}
void Pokemon::SetAttack2Pow(int attack2Pow)
{
	this->attack2Pow=attack2Pow;
}
void Pokemon::SetAttack2Name(std::string attack2Name)
{
	this->attack2Name=attack2Name;
}

int Pokemon::SetExp(int PlayerMonExp, int OponentMonHp, int OponentMonLvl)
{	
	PlayerMonExp += OponentMonHp* OponentMonLvl;

		if(PlayerMonExp >= this->Hp)
		{
			cout<<"Your pokemon grew a level! From "<< level <<" to level ";
			this->exp=0;
			SetLvl();
			cout<< level <<endl;
		}
	return PlayerMonExp;
}

int Pokemon::GetExp()
{
	return exp;
}

int Pokemon::GetLvl()
{
	return level;	
}

void Pokemon::SetLvl()
{
	this->level=+1;
}




	



