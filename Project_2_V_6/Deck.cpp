/* 
 * File:   Deck.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For std::swap
#include "Deck.h"

using namespace std;

// Constructor: Creates a deck with specified number of cards
Deck::Deck(int numCards) : numCards(numCards) {
    //set the random number seed
    srand(time(0));
    
    //Ensure the deck has a default number of cards
    if (numCards <= 0) {
        this->numCards = 52;
    }
    
    numShuffle = 7; // default number of shuffles
    numDelt = 0; //no cards dealt initially 
    
    //allocate memory for the deck
    cards = new Card*[this->numCards];
    for (int i = 0; i < this->numCards; i++) {
        cards[i] = new Card(i);
    }
}

// Destructor: Frees memory allocated for the deck
Deck::~Deck() {
    for (int i = 0; i < numCards; i++) {
        delete cards[i];
    }
    delete[] cards;
}


// Inline function to shuffle the deck
void Deck::shuffle() {
    for (int s = 0; s < numShuffle; s++) {
        for (int i = 0; i < numCards; i++) {
            int randIdx = rand() % numCards; // Pick a random index
            std::swap(cards[i], cards[randIdx]); // Swap cards
        }
    }
}


// Display the deck
void Deck::display() const {
    for (int i = 0; i < numCards; i++) {
        cout << "Index: " << i
             << " Face: " << cards[i]->face()
             << " of Suit: " << cards[i]->suit()
             << " Value: " << static_cast<int>(cards[i]->value()) << endl;
    }
}


// Access a specific card
Card* Deck::getCard(int index) const {
    if (index >= 0 && index < numCards) {
        return cards[index];
    }
    return nullptr; // Return nullptr if index is invalid
}


int Deck::getCardCount() const {
    return numCards - numDelt; // Remaining cards are total minus dealt
}
