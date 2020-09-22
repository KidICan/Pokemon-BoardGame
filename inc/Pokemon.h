#ifndef POKEMON_H
#define POKEMON_H
#include <string>

typedef class Move{

public:
    std::string name;
    int power;
    int roll;

    Move();
    Move(string, int, int);
    
    virtual std::string getName();
    
    virtual int getPower();
    
    virtual int getRoll();
};

typedef class Pokemon{

public:
	
	std::string name;
	int hp;
    int mhp;
    int atk;
    Move move1;
    Move move2;
	int exp;
	int lvl;
    
	Pokemon();

	Pokemon(std::string, int, int, int, Move, Move);
	
	//We can get and set the values for the creation of new pokemon here
	
	virtual std:: string GetName();
 
	virtual void  SetName(std::string);
	
	virtual int GetHP();

	virtual void SetHp(int );

	virtual void ModifyExp(int);

    virtual int GetExp();

	virtual int GetLvl();
    
    virtual void LevelUp();
};

#endif
