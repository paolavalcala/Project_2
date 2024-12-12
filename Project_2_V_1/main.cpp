
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 1
 */

//System Libraries
#include <iostream> //Input-Output Library 
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants - Math,Physics,Chemistry,Conversions

//Function Prototypes 

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all variables
    int numCards = 52; //number of cards
    Card **deck; //array of pointers to represent each card
    
    //Allocates the deck
    deck = new Card*[numCards];
    for (char i = 0; i < numCards; i++){
        deck[i] = new Card(i);
    }
    
    //Display the outputs
    for(char i = 0; i < numCards; i++){
        cout << "index: ";
        cout << static_cast<int>(i)  << " face:" << " " << deck[i]->face() << " of "
                << " suits: " << deck[i]->suit() << " " << " value: "
                << static_cast<int>(deck[i]->value()) << endl;
    }
    
    //reallocate Memory 
    for(char i = 0; i < numCards; i++){
        delete deck[i];
    }
    delete []deck;
    
    //Exit the program
    return 0;
}

/*
 For Version 1 I will be creating a header and cpp file for 
Card, Deck, and Player. 
 
 For this version I have decided to only focus on getting the card
 deck to print out properly. */