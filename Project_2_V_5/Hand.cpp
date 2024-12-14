/* 
 * File:   Hand.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 11:44 PM
 */

#include "Hand.h"
#include <iostream>
#include <utility>
using namespace std;

// Constructor: Initializes an empty hand
Hand::Hand() {}

// Destructor: Frees memory for cards in the hand
Hand::~Hand() {
    for (size_t i = 0; i < cards.size(); ++i) {
        delete cards[i];
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
    for (size_t i = 0; i < cards.size(); ++i) {
        cout << "Face: " << cards[i]->face()
             << " of Suit: " << cards[i]->suit()
             << " Value: " << static_cast<int>(cards[i]->value()) << endl;
    }
}


std::vector<std::pair<Card*, Card*> > Hand::findMatches() const {
    std::vector<std::pair<Card*, Card*> > matches;
    for (size_t i = 0; i < cards.size(); i++) {
        for (size_t j = i + 1; j < cards.size(); j++) {
            if (cards[i]->face() == cards[j]->face()) {
                matches.push_back(std::make_pair(cards[i], cards[j]));
            }
        }
    }
    return matches;
}