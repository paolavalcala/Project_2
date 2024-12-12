/* 
 * File:   Hand.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 11:44 PM
 */

#include "Hand.h"
#include <iostream>
using namespace std;

// Constructor: Initializes an empty hand
Hand::Hand() {}

// Destructor: Frees memory for cards in the hand
Hand::~Hand() {
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();            // Clear the vector
}

// Add a card to the hand
void Hand::addCard(Card* card) {
    cards.push_back(new Card(*card)); // Store a copy of the card
}

// Display the cards in the hand
void Hand::display() const {
    cout << "Hand contains:\n";
    for (Card* card : cards) {
        cout << "Face: " << card->face()
             << " of Suit: " << card->suit()
             << " Value: " << static_cast<int>(card->value()) << endl;
    }
}
