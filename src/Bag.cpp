#include<Bag.h>
#include<Pokemon.h>
#include<Item.h>
#include <Inits.h>
#include <iostream>
#include <unordered_map>

extern vector <Pokemon>Mon;
extern Bag bag;
extern Inits repo;

Bag::Bag(){
    map<string, Item>::iterator it;
    for (it = repo.dItem.begin(); it != repo.dItem.end(); it++)
	{
		Items[it->first]=0;
	}
    PlayerMon;
    money=500;
};


void Bag::AddItm(string x, int y)
    {
        Items[x]+=y;
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
        Mon.push_back(New);
}

int Bag::ViewCatchedMon(){

    if(Mon.size()==0)
    {
        return 0;
    }

    cout<<"The Mon that you have catched are: "<<endl;
        for(int i=0; i<Mon.size(); i++){
                cout<< "Lv. "<< Mon[i].GetLvl()<< " "<<Mon[i].GetName() << "  Hp. "<< Mon[i].GetHP()<<endl;
                cout<<"Exp. "<<Mon[i].GetExp()<<endl;
            }
        return Mon.size();
}

Pokemon& Bag:: MonSelect()
{
        int opt;

        if(Mon.size()==0)
        {
            cout<<"You don't have any Pokiman catched! Go out and catch some!"<<endl;

        }

        else
        {
            cout<<"Which Pokiman do you want to select?"<<endl;
                for(int i=0; i<Mon.size(); i++)
                {
                    int MonNum=1;
                    cout<<"for " << Mon[i].GetName()<<"Press "<< MonNum<<endl;
                    cout<<Mon[i].GetName()<<" has "<<Mon[i].GetHP()<<"HP"<<endl;
                    cout<<endl;
                    MonNum++;
                }
                cin>>opt;

                if(opt==1)
                {
                    return Mon[0];
                }

                if(opt==2)
                {
                    return Mon[1];
                }

                if(opt==3)
                {
                    return Mon[2];
                }

                if(opt==4)
                {
                    return Mon[3];
                }
        }
}


int Bag::NoOneLeft()
{
        if((Mon[0].GetHP()+Mon[1].GetHP()+Mon[2].GetHP()+Mon[3].GetHP())<=0)
        {
            return 0;
        }
}
