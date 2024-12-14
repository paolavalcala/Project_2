/* 
 * File:   Deck.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Constructor
Deck::Deck(int numCards) : numCards(numCards), numDelt(0) {
    srand(time(0)); // Set random seed

    if (numCards <= 0) {
        this->numCards = 52;
    }

    for (int i = 0; i < this->numCards; ++i) {
        cards.push_back(new Card(i));
    }
}

// Destructor
Deck::~Deck() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();
}

// Shuffle the deck
void Deck::shuffle() {
    random_shuffle(cards.begin(), cards.end());
}

// Display the deck
void Deck::display() const {
    for (Card* card : cards) {
        cout << *card << endl;
    }
}

// Access a specific card
Card* Deck::getCard(int index) const {
    if (index >= 0 && index < cards.size()) {
        return cards[index];
    }
    return nullptr;
}