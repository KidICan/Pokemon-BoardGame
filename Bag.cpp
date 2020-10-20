#include<Bag.h>
#include<Pokemon.h>
#include<Item.h>
#include <iostream>
#include <unordered_map>

Bag bag;
extern vector <Pokemon> PlayerMon;
Bag::Bag(){

	Items["pokeball"]=0;
	Items["potion"]=0;
	Items["super_potion"]=0;
	Items["hyper_potion"]=0;
	PlayerMon;
	money=500;
};
	
		
void Bag::AddItm(string x, int y)
	{
		Items.at(x)+=y;
	}

int Bag::InsideBag(){	
		int opt;
		cout<<"Would you like to see your pokiman or see your items?"<<endl;
		cout<<"1. Pokiman"<<endl;
		cout<<"2. Items"<<endl;
		cout<<"Press 1 for Pokiman, 2 for items";
		cin>>opt;
		if(opt ==1)
		{
			ViewCatchedMon();
		}

		if(opt ==2)
		{
			cout<<"You have"<< endl<<Items.at("pokeball")<< " Pokibals"<<endl<< Items.at("potion")<<" Potions"<<endl<< Items.at("hyper_potion")<< " HyperPotions"<<endl;
			cout<<" Select the item you want to use."<<endl;
			cout<<"1 for Pokibal"<<endl;
			cout<<"2 for Potion"<<endl;
			cout<<"3 for HyperPotions"<<endl;
			cin>>opt;
			cout<<endl;
						
			if(opt== 1)
			{
				return Items.at("pokeball");		
			}

			if(opt== 2)
			{
				return Items.at("potion");		
			}

			if(opt== 3)
			{
				return Items.at("hyper_potion") ;		
			}
		}
}

int Bag::GetMoney(){
	return money;

}
	
void Bag::SetMoney(int x){
	this->money=x;

}

void Bag::AddCatched(Pokemon New)
{
		PlayerMon.push_back(New);
}

int Bag::ViewCatchedMon(){

	if(PlayerMon.size()==0)
	{
		return 0;
	}
	
	cout<<"The Mon that you have catched are: "<<endl;
		for(int i=0; i<PlayerMon.size(); i++){
				cout<< "Lv. "<< PlayerMon[i].GetLvl()<< " "<<PlayerMon[i].GetName() << "  Hp. "<< PlayerMon[i].GetHP()<<endl;
				cout<<"Exp. "<<PlayerMon[i].GetExp()<<endl;
			}	
		return PlayerMon.size();	
}

Pokemon Bag:: MonSelect()
{
		int opt;
		
		if(PlayerMon.size()==0)
		{
			cout<<"You don't have any Pokiman catched! Go out and catch some!"<<endl;
		
		}

		else
		{
			cout<<"Which Pokiman do you want to select?"<<endl;
				for(int i=0; i<PlayerMon.size(); i++)
				{
					int MonNum=1;
					cout<<"for " << PlayerMon[i].GetName()<<"Press "<< MonNum<<endl;
					cout<<PlayerMon[i].GetName()<<" has "<<PlayerMon[i].GetHP()<<"HP"<<endl;
					cout<<endl;
					MonNum++;
				}
				cin>>opt;		
				
				if(opt==1)
				{
					return PlayerMon[0];
				}
			
				if(opt==2)
				{
					return PlayerMon[1];
				}
		
				if(opt==3)
				{
					return PlayerMon[2];
				}

				if(opt==4)
				{
					return PlayerMon[3];
				}
		}
}


int Bag::NoOneLeft()
{
		if((PlayerMon[0].GetHP()+PlayerMon[1].GetHP()+PlayerMon[2].GetHP()+PlayerMon[3].GetHP())<=0)
		{
			return 0;
		}		
}

