# Welcome to the world of Pokiman! (BETA)
## This README includes a description of all the files that are present in this reposotory

This is a luck/round base PIVG (Pllayer Input Video Game). At the beginning of the game
the player is introduced to the game in a Pokemon style intro. The player must input thier name
confirm their gender, and finanly choose a starter pokiman.
Once the player has chosen thier starter pokiman, they are introcuded to the menu screen. 
This is the main way the player chooses to interact with the game. This screen has the follwowing options:
-The Shop
  Here the player can use the money that has already been given to him to buy items and store them in his bag
-YourBag
  Here the player can look at his inverntory and see all the items that he has bought
-Try&Catch
  Here the player will face a random Pokiman (with usual lower levels to that of the trainer) to battle for 
  experience or to catch the wild Pokiman
-TrainerBattle
  Here the player can battle trainers (with higher levels of that of the trainer) to battle for 
  money or experinece.
 
 After 15 rounds, the player will intiate a Gym Trainer battle (Boss battle). This boss battle is set to have a set of 3 pokemon with a set levels.
 This was put in place to make sure the player is working hard in leveling up and buying items for the player.
And this cycle continues with boss battles every 15 rounds. After every boss battle the pokiman that show up are stronger forshadowing the strength
of the next boss battle.


### The battle mechanics
Although similar to the battle mechanis in the classic pokemon game, Pokiman's battle mechanics are all luck based. 
There is no typeing in Pokiman, so some Pokiman do not have advantages over others.
Before the player has the chance to attack he must choose the move he wishes to attack with. Once the move is selected, the power of that move is then used as refrence.
The player then must roll. If the players roll is greater than, or equal to the moves power the move connects and does the respective damage. If the roll is less than 
the power of that move, the move misses.

#### **The objective of this game ** 
The objective of this game is for the player to last as many rounds as possible. Once the player has defeated gym battle #9
He has finished the game, and will have the option of entering Elite Mode. Where every encounter is bound to make the player struggle.
Although this a luck based game, there is stategy to ensure that you can pass each boss battle.

## The files needed to run this game

### __.vscode__
-This folder contains Visual Studio files that come with compiling my project in Visual studio

### **inc**
-This folder contains all the header files needed to run this program.

### **obj**
-This folder contains all the output files. 

### **src**
-This folder contains all the source files need to run this program.

### **makefile**
- This is the make file to compile this game. Once the game is compiled you can run the game by
typeing ./Game


