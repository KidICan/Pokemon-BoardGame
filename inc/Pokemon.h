#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <Item.h>

typedef class Move{

public:
    std::string name;
    int power;
    int roll;

    Move();
    Move(std::string, int, int);
    
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
    
    Pokemon(const Pokemon&);
    
    virtual std:: string GetName();
 
    virtual void SetName(std::string);
    
    virtual int GetHP();
    
    virtual Move getMove(int);

    virtual void SetHp(int );
    
    virtual void modifyHP(int);

    virtual void ModifyEXP(int);

    virtual int GetExp();

    virtual int GetLvl();
    
    virtual void LevelUp();
    
    virtual void healPokemon(Item);
};

#endif
