//Wyatt Hooper
//CS 355
//Assignment 3
//09/01/2023
//Create a GAMECHARACTER class along with methods that make it more versatile

#ifndef GAMECHARACTERADVANCED_H
#define GAMECHARACTERADVANCED_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class GameCharacter {
private:
     string name;
     int maxHealth;
     int healthPoints;
     int attackPoints;
     int defensePoints;
     bool isAlive;

public:
GameCharacter(string characterName, int mH, int attP, int defP);

string getName() const;

int getMaxHealth() const;

int getHealthPoints() const;

int getAttackPoints() const;

int getDefensePoints() const;

bool getIsAlive() const;

void takeDamage(int damage);

void attack(GameCharacter& target);

GameCharacter operator+ (const GameCharacter& char1) const;

bool operator< (const GameCharacter& character);

bool operator> (const GameCharacter& character);

friend ostream& operator<< (ostream& os, const GameCharacter& character);

void saveToFile(const string& filename) const;

void loadFromFile(const string& filename);

};

#endif
