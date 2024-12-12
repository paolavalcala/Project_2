/* 
 * File:   Deck.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include <iostream>
#include "Deck.h"

using namespace std;

// Constructor: Creates a deck with specified number of cards
Deck::Deck(int numCards) : numCards(numCards) {
    cards = new Card*[numCards];
    for (int i = 0; i < numCards; i++) {
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

