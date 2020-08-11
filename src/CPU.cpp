#include <CPU.h>
#include <Player.h>
#include <iostream>
#include <Bag.h>
#include <Pokemon.h>

extern std::vector<Pokemon> Mon;
extern Bag bag;
Player CPU;

void CPUAttack(int Rattack, int MonSel, Pokemon battleMon)
{
    //Here the Oposing Mon is attacking
			
				if(Rattack==1 && (Mon[MonSel].GetAttack1Pow() <= CPU.DieRoll()*10) )
				{
					battleMon.SetHp(battleMon.GetHP() - Mon[MonSel].GetAttack1Pow());
					std::cout<<"The oposing "<<Mon[MonSel].GetName()<<" attacked you with "<<Mon[MonSel].GetAttack1Name()<<endl;
					std::cout<<battleMon.GetName()<< " took "<< Mon[MonSel].GetAttack1Pow()<<" points of damage!"<<endl;
					std::cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
					std::cout<<endl;
					
						if(battleMon.GetHP()<=0)
						{
							std::cout<<battleMon.GetName()<<" Has been defeated!"<<endl;
								if(bag.NoOneLeft()==0)
								{
									std::cout<<"You have no Pokimanleft to battle"<<endl;
									std::cout<<"Lets try this again."<<endl;
								}
							std::cout<<"(Press Enter to continue)"<< endl;
							cin.ignore();
							return;
						}
					return;
				}else
				{
					cout<<"The oposing "<<Mon[MonSel].GetName()<<" attack missed!"<<endl;
					return;
				}				
					
				if(Rattack==2 && (Mon[MonSel].GetAttack2Pow() <= CPU.DieRoll()*10))
				{
					battleMon.SetHp(battleMon.GetHP()-Mon[MonSel].GetAttack2Pow());
					std::cout<<"The oposing "<<Mon[MonSel].GetName()<<" attacked you with "<<Mon[MonSel].GetAttack2Pow()<<endl;
					std::cout<<battleMon.GetName()<< " took "<< battleMon.GetAttack2Pow()<< "points of damage"<<endl;

					std::cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
					std::cout<<endl;

					if(battleMon.GetHP()<=0)
					{
							std::cout<<battleMon.GetName()<<" Has been defeated!"<<endl;
								if(bag.NoOneLeft()==0)
								{
									std::cout<<"You have no Pokimanleft to battle"<<endl;
									std::cout<<"Lets try this again."<<endl;
								}
							std::cout<<"(Press Enter to continue)"<< endl;
							cin.ignore();
							return;
					}
					return;
				}else
				{
					cout<<"The oposing "<<Mon[MonSel].GetName()<<" attack missed!"<<endl;
					return;
				}
				
}