/* 
 * File:   Deck.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Constructor: Creates a deck with specified number of cards
Deck::Deck(int numCards) : numCards(numCards), numDelt(0) {
    srand(time(0)); // Set random seed

    // Ensure the deck has a valid number of cards
    if (numCards <= 0) {
        this->numCards = 52;
    }

    // Allocate memory for the deck
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

// Shuffle the deck
void Deck::shuffle() {
    for (int i = 0; i < numCards; i++) {
        int randIdx = rand() % numCards;
        swap(cards[i], cards[randIdx]);
    }
}

// Display the deck
void Deck::display() const {
    for (int i = 0; i < numCards; i++) {
        cout << "Card: " << cards[i]->face() << " of " << cards[i]->suit() << endl;
    }
}

// Access a specific card
Card* Deck::getCard(int index) const {
    if (index >= 0 && index < numCards) {
        return cards[index];
    }
    return nullptr; // Return nullptr if index is invalid
}

// Get the number of remaining cards in the deck
int Deck::getCardCount() const {
    return numCards - numDelt; // Remaining cards = total - dealt
}

