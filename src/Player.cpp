#include <Player.h>
#include <Shop.h>
#include <Bag.h>
#include <CPU.h>
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

int Player::DieRoll()
{
	srand(time(0));
	int dieRole=rand()%6;
	return dieRole;
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
	

	
	std::cout<<"What are we doing next?"<<endl;
	std::cout<<"Press 1 to go to the Shop."<<endl;
	std::cout<<"Press 2 to go to  YourBag."<<endl;
	std::cout<<"Press 3 to go to Try&Catch."<<endl;
	std::cout<<"Press 4 to go to TrainerBattle."<<endl;
	
	
		cin>>opt;
		std::cout<<endl;
	
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
	//Here we randomize the roll and the pokemon selection.
	srand(time(0));
	int PlayerRoll;
	int Rattack=rand()%2;
	int MonSel=rand()%2;
//Here we define a pokemons variable to access the players pokemon
	Pokemon battleMon;
	int ExpPott;
	int opt;
	//Here we start to find the wild pokiman in out Mon vector and select.
	std::cout<<"You have encounterd a wild "<< Mon[MonSel].GetName()<<" !"<<endl;
		//Now we get the hp that the oposing Mon.
		ExpPott=Mon[MonSel].GetHP();
		//Here the player chooses the pokemon inside his bag.
		battleMon=bag.MonSelect();
	std::cout<<"Lets go "<< battleMon.GetName()<<"!"<<endl;
	std::cout<<"The battle has begun!"<<endl;
	std::cout<<"What will "<< battleMon.GetName()<<" do?"<<endl;
	
	while(battleMon.GetHP()>=0 && Mon[MonSel].GetHP()>=0)
	{
		std::cout<<"What's the next move?"<<endl;	
		std::cout<<"1. "<<battleMon.GetAttack1Name()<<" "<< battleMon.GetAttack1Pow()<<endl;
		std::cout<<"2. "<<battleMon.GetAttack2Name()<<" "<<battleMon.GetAttack2Pow()<< endl; 
		std::cout<<"3. Catch"<<endl; 
		cin>>opt;
		PlayerRoll=DieRoll();

			if(opt==1 && (battleMon.GetAttack1Pow() <= PlayerRoll*10) )
			{
				//Once the we are able to be able to attack we choose the pokemon. 
				cout<<"You chose " << battleMon.GetAttack1Name()<<endl;
				cout<<"Time to roll the die."<<endl;
				cout<<"Press enter to roll the die"<<endl;
				cin.ignore();
				cin.ignore();
				std::cout<<"You rolled a "<<PlayerRoll<<endl;
				Mon[MonSel].SetHp(Mon[MonSel].GetHP()-battleMon.GetAttack1Pow());
				std::cout<<battleMon.GetName()<<" used "<< battleMon.GetAttack1Name()<<endl;
				std::cout<<"The oposing "<<Mon[MonSel].GetName()<<" has taken "<<battleMon.GetAttack1Pow()<<endl;
				std::cout<<"The oposing "<<Mon[MonSel].GetName()<<" has "<< Mon[MonSel].GetHP()<< " HP"<<endl;
				std::cout<<"``````````````````````````` ````````````````````````````"<<endl;
				std::cout<<endl;
					//This sequence is played once the oposing Mon is defeted
				if(Mon[MonSel].GetHP()<=0)
				{
					std::cout<<"You have defeated "<<Mon[MonSel].GetName()<<endl;
					std::cout<<battleMon.GetName()<< " exp increased by " <<battleMon.SetExp(battleMon.GetExp(), ExpPott, Mon[MonSel].GetLvl())<<endl;
					battleMon.SetExp(battleMon.GetExp(), ExpPott, Mon[MonSel].GetLvl());
					std::cout<<"(Press Enter to continue)"<< endl;
					cin.ignore();
					return ;
				}

				
				//Gere its the CPUs turn to attack
				CPUAttack(Rattack,MonSel,battleMon);
				
			}
			else
			{
				cout<<"You chose " << battleMon.GetAttack1Name()<<endl;
				cout<<"Time to roll the die."<<endl;
				cout<<"Press enter to roll the die"<<endl;
				cin.ignore();
				cin.ignore();
				std::cout<<"Your Roll was a "<< PlayerRoll<<endl;
				std::cout<<"You Missed!"<<endl;
				CPUAttack(Rattack, MonSel, battleMon);
			}
	}

			
}

//This fucntion will only be calle when the randomizer >=2
bool Player::TryCatch()
{
	int Roll= DieRoll();
	int YorN;
	Pokemon battleMon;
	
	
	std::cout<<"Lets try an catch some PokiMan!"<<endl;
	std::cout<<"Time to roll the Die"<<endl;
	std::cout<<"Press enter to roll the die"<<endl;
	cin.ignore();
	cin.ignore();
		if(Roll>=2)
		{
			std::cout<<"You rolled a "<< Roll<< " ! Let the battle begin."<<endl;
				Player::BattleSequence();
				std::cout<<endl;
		}
		
		if(Roll<2)
		{
			std::cout<<"You rolled a "<<Roll<< " ! Better luck next time."<<endl;
			std::cout<<endl;
			
		}
}


	
