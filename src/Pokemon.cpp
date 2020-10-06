#include "Pokemon.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Move::Move(){
    name = "";
    power = 0;
    roll = 0;
}

Move::Move(string n, int p, int r){
    name = n;
    power = p;
    roll = r;
}

string Move::getName(){
    return name;
}

int Move::getPower(){
    return power;
}

int Move::getRoll(){
    return roll;
}
	
Pokemon::Pokemon(){
	name="po";
    Mhp=0;
    Hp=Mhp;
    attack1Pow=0;
    attack1Name="a";
	attack2Pow=0;
	attack2Name="b";
	exp=0;
	level=1;
}

Pokemon::Pokemon(string n, int l, int max, int a, Move m1, Move m2){
    name = n;
    lvl = l;
    mhp = max;
    hp = mhp;
    atk = a;
    move1 = m1;
    move2 = m2;
    exp = 0;
}

Pokemon::Pokemon(Pokemon x){
    name = x.name;
    lvl = x.lvl;
    mhp = x.mhp;
    hp = mhp;
    atk = x.atk;
    move1 = x.move1;
    move2 = x.move2;
    exp = 0;
}

std::string Pokemon::GetName()
{
   return name;
 }

 
void Pokemon::SetName(std::string name)
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

Move Pokemon::getMove(int n){
    if (n == 1){
        return move1;
    }
    else{
        return move2;
    }
}

void Pokemon::modifyEXP(int oppLvl){
    int temp = exp + 30 * (oppLvl/lvl);
    if (temp > 100){
        exp = 100 - temp;
        LevelUp();
    }
    else{
        exp = temp;}
}

int Pokemon::GetExp()
{
	return exp;
}

int Pokemon::GetLvl()
{
	return level;	
}

void Pokemon::LevelUp()
{
	level+=1;
}
