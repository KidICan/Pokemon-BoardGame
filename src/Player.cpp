#include <Player.h>
#include <Shop.h>
#include <Bag.h>
#include <Inits.h>
#include <iostream>


extern Bag bag;
extern std::vector<Pokemon> Mon;

Player player1;

Player::Player(){
    name="Player";
    gender=0;
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
        BattleSequence(false, 1);
    }
    
}

void Player::BattleSequence(bool mode, int numMon)
{
    //Here we randomize the roll and the pokemon selection.
    vector<Pokemon> enemies;
    for (int i = 0; i < numMon; i++){
        srand(time(0));
        int j = rand() % pokeDict.size();
        iterator t = pokeDict.begin();
        advance(t, j);
        enemies.push(new Pokemon (t->second));
    }
    
    srand(time(0));
    int PlayerRoll;
    //Here we define a pokemons variable to access the players pokemon
    Pokemon battleMon;
    Pokemon enemyMon = enemies[0];
    int opt = 0;
    //Here we start to find the wild pokiman in out Mon vector and select.
    
    if (!mode){
        std::cout<<"You have encountered a wild " << enemyMon.GetName() << "!" <<endl;
    }
    else{
        std::cout<<"You are challenged by Trainer R!" << endl;
    }
    
    //Here the player chooses the pokemon inside his bag.
    battleMon=bag.MonSelect();
    std::cout<<"Let's go " << battleMon.GetName() << "!" << endl;
    
    bool yourTurn = true;
    Move selected;
    int damage;
    
    while(battleMon.GetHP() > 0 && enemyMon.GetHP() > 0 && enemies.size >= 1)
    {
        if (yourTurn)
        {
            std::cout<< "What will " << battleMon.GetName() << " do?" << endl;
            std::cout<< "1. " << battleMon.getMove(1).getName() << " - " << battleMon.getMove(1).getRoll() <<endl;
            std::cout<< "2. " << battleMon.getMove(2).getName() << " - " << battleMon.getMove(2).getRoll() <<endl;
            if (!mode) {std::cout << "3. Catch" << endl;}
            cin >> opt;
            
            while (opt < 1 || (opt > 3 && !mode) || (opt > 2 && mode)){
                std::cout << "-------------------------------------------------------------------\n" << endl;
                
                std::cout<< "Please input one of the following." << endl;
                std::cout<< "1. " << battleMon.getMove(1).getName() << " - " << battleMon.getMove(1).getRoll() <<endl;
                std::cout<< "2. " << battleMon.getMove(2).getName() << " - " << battleMon.getMove(2).getRoll() <<endl;
                if (!mode) {std::cout << "3. Catch" << endl;}
                cin>>opt;
            }
            
            std::cout << "-------------------------------------------------------------------\n" << endl;
            
            //check if opt is 1-2 or 3-4 to include different behavior for Catch() and Bag()
            selected = battleMon.getMove(opt);
            cout << "You chose " << selected << " ." << endl;
            cout << "Time to roll the die." << endl;
            PlayerRoll = DieRoll();
            
            cout<<"Press enter to roll the die"<<endl;
            cin.ignore();
            cin.ignore();
            
            std::cout<<"You rolled a " << PlayerRoll << endl;
            
            if (PlayerRoll >= selected.getRoll()){
                std::cout << "Your " << battleMon.GetName() << " missed!" << endl;
            }
            else{
                damage = Battle(battleMon, enemyMon, selected);
                std::cout << "The opposing " << enemyMon.GetName() << " has taken " << damage << " damage!" << endl;
            }
        }
        else{
            PlayerRoll = (rand() % 2) + 1;
            selected = enemyMon.getMove(PlayerRoll);
            PlayerRoll = DieRoll();
            
            //enemy name
            std::cout<<"Enemy rolled a " << PlayerRoll << endl;
            
            if (PlayerRoll >= selected.getRoll()){
                std::cout << "The opposing " << battleMon.GetName() << " missed!" << endl;
            }
            else{
                damage = Battle(battleMon, enemyMon, selected);
                std::cout << "Your " << enemyMon.GetName() << " has taken " << damage << " damage!" << endl;
            }
        }
    }
    
    //leave if anyone dies
    
}

int Player::Battle(Pokemon attacking, Pokemon defending, Move sel){
    return 1;
}

//This fucntion will only be calle when the randomizer >=2
bool Player::TryCatch()
{
    int Roll= DieRoll();
    Pokemon battleMon;
    
    
    std::cout<<"Lets try an catch some PokiMan!"<<endl;
    std::cout<<"Time to roll the Die"<<endl;
    std::cout<<"Press enter to roll the die"<<endl;
    cin.ignore();
    cin.ignore();
    if(Roll>=2)
    {
        std::cout<<"You rolled a "<< Roll<< " ! Let the battle begin."<<endl;
        Player::BattleSequence(false, 1);
        std::cout<<endl;
    }
    
    if(Roll<2)
    {
        std::cout<<"You rolled a "<<Roll<< " ! Better luck next time."<<endl;
        std::cout<<endl;
        
    }
}



