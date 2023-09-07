//Wyatt Hooper
//CS 355
//Assignment 3
//09/01/2023
//Create a GameCharacter class along with methods that make it more versatile

#include <iostream>
#include "GameCharacterAdvanced.h"
#include <string>

using namespace std;

int main() 
{
    GameCharacter char1("Wyatt", 100, 150, 10);
    GameCharacter char2("Doug", 90, 9, 5);
    GameCharacter char3("Aragorn", 80, 8, 11);

    char1.attack(char2);
    char2.attack(char3);

    if(char1 > char3) 
    {
        cout << "Player 1 is stronger." << endl << endl;
    }

    else if(char1 < char3)
    {
        cout << "Player 3 is weaker than player 1." << endl << endl;
    }
    
    else
    {
        cout << "Players 1 and 3 are the same strength." << endl << endl;
    }

    cout << char1 << endl;
    cout << char2 << endl;
    cout << char3 << endl;

    char1.saveToFile("character1.txt");
    char1.loadFromFile("character1.txt");

    char1.displayDateTimeOfLastSave();
    char1.displayTimeSinceLastSave();


    return 0;
}
