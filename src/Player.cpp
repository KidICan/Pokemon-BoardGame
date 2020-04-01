#include <Player.h>
#include <Shop.h>
#include <Bag.h>
#include <iostream>


extern Bag bag;
extern std::vector<Pokemon> Mon;


Player player1;

Player::Player(){
    name="Player";
    gender=0;
	YorN=0;
	opt=0;
}



void Player::GetName(){
	std::string n;
		std::cin>>n;
		this->name=n;
}

void Player:: PlayerName(){
	std::cout<<name;
}	

void Player::SetResponse(){
	int res;
	cin>>res;	
	this->YorN=res;
}

int Player::GetResponse(){
	return YorN;
}

void Player::SetOption(){
	int res;
	cin>>res;
	this->opt=res;
}
int Player::GetOption(){
	return opt;
}

void Player::SetGender(){
	int res;
	cin>>res;
	this->gender=res;
}

int Player::GetGender(){
	return gender;
}

void Player::OptionSelect()
{
	int opt;
	

	
	cout<<"What are we doing next?"<<endl;
	cout<<"Press 1 to go to the Shop."<<endl;
	cout<<"Press 2 to go to  YourBag."<<endl;
	cout<<"Press 3 to go to Try&Catch."<<endl;
	cout<<"Press 4 to go to TrainerBattle."<<endl;
	
	
		cin>>opt;
		cout<<endl;
	
		if(opt==1)
		{
			Shop(bag.GetMoney());
			OptionSelect();	
		}		
	
		if(opt==2)
		{
		bag.InsideBag();
		OptionSelect();
		}

		if(opt==3)
		{
		TryCatch();
		OptionSelect();
		}
		if(opt==4){
			BattleSequence();
		}
	
}


void Player::BattleSequence()
{
	
	srand((unsigned) time(0));
	int Rattack=(rand()%2);
	int MonSel=(rand()%2);
	int dieRole=(rand()%6);

	Pokemon battleMon;
	int opt;

	cout<<"You have encounterd a wild "<< Mon[MonSel].GetName()<<" !"<<endl;
		battleMon=bag.MonSelect();
	cout<<"Lets go "<< battleMon.GetName()<<"!"<<endl;
	cout<<"The battle has begun!"<<endl;
	cout<<"What will "<< battleMon.GetName()<<" do?"<<endl;
	
	while(battleMon.GetHP()>=0 && Mon[MonSel].GetHP()>=0)
	{
		
		std::cout<<"1. "<<battleMon.GetAttack1Name()<<endl;
		cout<<"2. "<<battleMon.GetAttack2Name()<<endl; 
		cout<<"3. Catch"<<endl; 
		cin>>opt;
			if(opt==1 && battleMon.GetAttack1Pow()>= dieRole)  
			{
				Mon[MonSel].SetHp(Mon[MonSel].GetHP()-battleMon.GetAttack1Pow());
				cout<<battleMon.GetName()<<" used "<< battleMon.GetAttack1Name()<<endl;
				cout<<"The oposing "<<Mon[MonSel].GetName()<<" has taken "<<battleMon.GetAttack1Pow()<<endl;
				cout<<"The oposing "<<Mon[MonSel].GetName()<<" has "<< Mon[MonSel].GetHP()<< " HP"<<endl;
				cout<<endl;
					if(Mon[MonSel].GetHP()<=0)
					{
						cout<<"You have defeated"<<Mon[MonSel].GetName()<<endl;
						cout<<"(Press Enter to continue)"<< endl;
						cin.ignore();
						return ;
					}
				if(Rattack==1)
				{
				battleMon.SetHp(battleMon.GetHP()-Mon[MonSel].GetAttack1Pow());
				cout<<Mon[MonSel].GetName()<<" used "<< Mon[MonSel].GetAttack1Name()<<endl;
				cout<<"The oposing "<<Mon[MonSel].GetName()<<" attacked you with "<<Mon[MonSel].GetAttack1Name()<<endl;
				cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
				cout<<endl;
					
					if(battleMon.GetHP()<=0)
					{
						cout<<battleMon.GetName()<<" Has been defeated!"<<endl;
							if(bag.NoOneLeft()==0)
							{
								cout<<"You have no Pokimanleft to battle"<<endl;
								cout<<"Lets try this again."<<endl;
								return;
					
							}
						cout<<"(Press Enter to continue)"<< endl;
						cin.ignore();
						return ;
					}				
				}

					
				if(Rattack==2)
				{
				battleMon.SetHp(battleMon.GetHP()-Mon[MonSel].GetAttack2Pow());
				cout<<Mon[MonSel].GetName()<<" used "<< Mon[MonSel].GetAttack2Name()<<endl;
				cout<<"The oposing "<<Mon[MonSel].GetName()<<" attacked you with "<<Mon[MonSel].GetAttack2Pow()<<endl;
				cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
				cout<<endl;
				}
			}
			else
			{
				cout<<"You Missed!"<<endl;
			}
	}

			
}

//This fucntion will only be calle when the randomizer >=2
bool Player::TryCatch()
{
	int Roll= rand()%6;
	int YorN;
	Pokemon battleMon;
	
	
	cout<<"Lets try an catch some PokiMan!"<<endl;
	cout<<"Time to roll the Die"<<endl;
		if(Roll>=2)
		{
			cout<<"You rolled a "<< Roll<< " ! Let the battle begin."<<endl;
				Player::BattleSequence();
				cout<<endl;
		}
		
		if(Roll<2)
		{
			cout<<"You rolled a "<<Roll<< " ! Better luck next time."<<endl;
			cout<<endl;
			
		}
}


	
