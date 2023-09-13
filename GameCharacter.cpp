//Wyatt Hooper
//cs 355
//Assignment_3
//09/01/2023
//Create a GameCharacter class along with methods to make it more functional

#include <iostream>
#include <string>
#include <ctime>
#include "GameCharacterAdvanced.h"

using namespace std;

//Function Name: GameCharacter(string, int, int, int)
//
//A constructor that initializes the attributes of the character.
//Return Value: NA
GameCharacter::GameCharacter(string charName, int mHealth, int aP, int dP)
{
    name = charName;
    maxHealth = mHealth;
    healthPoints = maxHealth;
    attackPoints = aP;
    defensePoints = dP;
    isAlive = true;
}

//Function Name: getName()
//
//Returns the value of the character's name
//Return Type: string
string GameCharacter::getName() const
{
    return name;
}

//Function Name: getMaxHealth()
//
//Returns the value of maxHealth
//Return Type:int
int GameCharacter::getMaxHealth() const
{
    return maxHealth;
}

//Function Name: getHealthPoints()
//
//Returns the value of healthPoints
//Return Type: int
int GameCharacter::getHealthPoints() const
{
    return healthPoints;
}

//Function Name: getAttackPoints()
//
//Returns the value of attackPoints
//Return Type: int
int GameCharacter::getAttackPoints() const
{
    return attackPoints;
}

//Function Name: getDefensePoints()
//
//Returns the value of defensePoints
//Return Type: int
int GameCharacter::getDefensePoints() const
{
    return defensePoints;
}

//Function Name: getIsAlive()
//
//Returns the value of isAlive
//Return Type: bool
bool GameCharacter::getIsAlive() const
{
    return isAlive;
}

//Function Name: takeDamage(int)
//
//A function that allows the characters health to be modified after being attacked
//Return Type: Void
void GameCharacter::takeDamage(int damage)
{
    //Variable for determining the amount of damage taken
    healthPoints -= damage;

    //healthPoints = healthPoints - damageTaken;
    if(healthPoints <= 0)
    {
	healthPoints = 0;
	isAlive = false;
    }
}

//Function Name: attack(GameCharacter&)
//
//A function that allows players to attack one another
//Return Type: void
void GameCharacter::attack(GameCharacter& target)
{   
    // Case 1: attack points are higher than defense points
    if (attackPoints > target.defensePoints)
    {
	// Calculate Damage 
	int damage = attackPoints - target.defensePoints;

	// make the target take damage based using the previously calculated number
	target.takeDamage(damage);
	cout << target.name << " is attacked! They take " << damage << " points of damage!" << endl;
	cout << target.name << " 's new HP is: " << target.healthPoints << endl << endl;
}

    else
    {
	cout << "Attack Level is too low!" << endl << endl;
    }
}

//Overloading the + operator
//
//Return Type: GameCharacter
//Parameters: a const GameCharacter& object
GameCharacter GameCharacter::operator+ (const GameCharacter& char1) const
{
   
    GameCharacter newCharacter ("New Character: ", 0,0,0);
    newCharacter.name = "Chester";
    newCharacter.maxHealth = char1.maxHealth + maxHealth;
    newCharacter.attackPoints = (char1.attackPoints + attackPoints) / 2;
    newCharacter.defensePoints = (char1.defensePoints + defensePoints) / 2;

    return newCharacter;
}

//Overloading the > operator
//
//Return Type: bool
//Parameters: A const GameCharacter& object
bool GameCharacter::operator> (const GameCharacter& char1)
{
    return maxHealth > char1.maxHealth;
}

//Overloading the < operator
//
//Return Type: bool
//Parameters: A const GameCharacter& object
bool GameCharacter::operator< (const GameCharacter& char1)
{
    return maxHealth < char1.maxHealth;
}

//Overloading the << operator
//
//Return Type: ostream
//Parameters: ostream& variable, const GameCharacter& object
ostream& operator<< (ostream& os, const GameCharacter& char1)
{
    os << "Name: " << char1.name << endl;
    os << "Max Health: " << char1.maxHealth << endl;
    os << "Health Points: " << char1.healthPoints << endl;
    os << "Attack Points: " << char1.attackPoints << endl;
    os << "Defense Points: " << char1.defensePoints << endl;
    os << "Is Alive?: " << char1.isAlive << endl << endl;

    return os;
}

//Function to save the character details to a file
//
//Return Type: void
//Parameters: const string&
void GameCharacter::saveToFile(const string& filename) const
{
    ofstream outFile(filename);
    if (outFile.fail())
    {
        cout << "File failed to open" << endl;
	exit(1);
    }

    outFile << name << endl;
    outFile << maxHealth << endl;
    outFile << healthPoints << endl;
    outFile << attackPoints << endl;
    outFile << defensePoints << endl;

}

//Function to load a character's details from a file
//
//Return Type: void
//Parameters: const string&
void GameCharacter::loadFromFile(const string& filename) 
{
    ifstream inFile(filename);
    if (inFile.fail())
    {
        cout << "Failed to load from the file." << endl;
	exit(1);
    }

    getline(inFile, name);
    inFile >> name;
    inFile >> maxHealth;
    inFile >> healthPoints;
    inFile >> attackPoints;
    inFile >> defensePoints;
    inFile >> isAlive;
}

void GameCharacter::displayDateTimeOfLastSave()
{
	time_t currTime = time(0);
	char* dt = ctime(&currTime);
	
    if (lastSave)
    {
       cout << "Last Saved On: " << dt << endl;
    }

    else
    {
	cout << "No Saved Data" << endl;
    }
}

void GameCharacter::displayTimeSinceLastSave()
{
	//time_t currTime = time(0);
	//char* dt = ctime(&currTime);

	time_t currTime = time(0);
	//tm *ltm = localtime(&currTime);
	//
	time_t timeDifference = difftime(currTime, lastSave);

	char* tD = ctime(&timeDifference);
	
	cout << "Amount of time since last save: " << tD << endl;

	//double timeDifference = difftime(currTime, lastSave);

	//cout << "Curr time" << currTime << endl;
	//cout << "time difference" << timeDifference << endl;
	//
	//cout << "Time Difference: " << timeDifference << endl;

	
	
	//cout << "Time Since Last Save: " << hours << " hours, " << minutes << " minutes, " << 	        seconds << " seconds" << endl;
}
