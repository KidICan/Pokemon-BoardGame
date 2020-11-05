#include<Bag.h>
#include<Pokemon.h>
#include<Item.h>
#include <Inits.h>
#include <iostream>
#include <unordered_map>

extern vector <Pokemon> Mon;
extern Inits repo;
extern Bag bag;

Bag::Bag(){
    map<string, Item>::iterator it;
    for (it = repo.dItem.begin(); it != repo.dItem.end(); it++)
    {
        Items[it->first] = 0;
    }
    PlayerMon;
    money = 500;
};

void Bag::AddItm(string x, int y)
{
    Items[x]+=y;
}

string Bag::InsideBag(BagState tri){
    int opt = 0;
    bool notLeft = true;
    map<string, int>::iterator it;
    if (tri == BagState::Main)
    {
        for (it = Items.begin(); it != Items.end(); it++){
            cout << it->first << " x" << it->second << endl;
        }
        cout << "Use item? (This will use an action)"<< endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        //do thing, opt == 1 yes, opt == 2 no
        cin >> opt;
        
        if (opt == 2)
        {
            notLeft = false;
        }
    }
    
    while(notLeft){
        int counter = 0;
        for (it = Items.begin(); it != Items.end(); it++){
            if (((tri == BagState::Main || tri == BagState::Trainer) && repo.dItem[it->first].getType() == ItemType::Heal) || (tri == BagState::Wild)){
                counter++;
                cout << counter << ". " << it ->first << endl;
            }
        }
        cout << "Which item would you like to use?" << endl;
        cin >> opt;
        counter = 0;
        string sel;
        for (it = Items.begin(); it != Items.end(); it++){
            if (((tri == BagState::Main || tri == BagState::Trainer) && repo.dItem[it->first].getType() == ItemType::Heal) || (tri == BagState::Wild)){
                counter++;
                if (counter == opt){
                    sel = it->first;
                }
            }
        }
        
        Item chosen = repo.dItem[sel];
        Pokemon* temp;
        if (chosen.getType() == ItemType::Heal){
            temp = &MonSelect();
            temp->healPokemon(chosen);
            if (tri == BagState::Trainer || tri == BagState::Wild)
            {
                notLeft = false;
            }
            else{
                cout << "Use another item?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> opt;
                
                if (opt == 2)
                {
                    notLeft = false;
                }
            }
        }
        else{
            return chosen.getName();
        }
    }
    return "";
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
