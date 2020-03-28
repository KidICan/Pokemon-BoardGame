#ifndef POKEMON_H
#define POKEMON_H
#include <string>

typedef class Pokemon{


public:
	
	std::string name;
	int Hp;
	int attack1Pow;
	std::string attack1Name;
	int attack2Pow;
	std::string attack2Name;
	
	Pokemon();

	Pokemon(std::string, int, std::string, int, std::string, int);

	
	
	//We can get and set the values for the creation of new pokemon here
	
	virtual std:: string GetName();
 
	virtual void  SetName(std::string);
	
	virtual int GetHP();
	
	virtual void SetHp(int );

	virtual int GetAttack1Pow();

	virtual std::string GetAttack1Name();

	virtual void SetAttack1Pow(int);
		
	virtual void SetAttack1Name(std::string);
		
	virtual int GetAttack2Pow();
			
	virtual std::string GetAttack2Name();
		
	virtual  void SetAttack2Pow(int);
		
	virtual void SetAttack2Name(std::string);
		
};

#endif