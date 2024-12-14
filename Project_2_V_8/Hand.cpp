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
    cards.push_back(new Card(*card)); // Create a copy using the copy constructor
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

// Find matches based on card values
std::vector<std::pair<Card*, Card*> > Hand::findMatches() const {
    std::vector<std::pair<Card*, Card*> > matches;
    for (size_t i = 0; i < cards.size(); i++) {
        for (size_t j = i + 1; j < cards.size(); j++) {
            if (cards[i]->value() == cards[j]->value()) {
                matches.push_back(std::make_pair(cards[i], cards[j]));
            }
        }
    }
    return matches;
}

// Check if the hand contains a card with the given value
bool Hand::hasCard(int value) const {
    for (size_t i = 0; i < cards.size(); ++i) {
        if (cards[i]->value() == value) {
            return true;
        }
    }
    return false;
}

// Remove a card by value
Card* Hand::removeCard(int value) {
    for (size_t i = 0; i < cards.size(); ++i) {
        if (cards[i]->value() == value) {
            Card* removed = cards[i];
            cards.erase(cards.begin() + i);
            return removed;
        }
    }
    return nullptr;
}

// Check if the hand is empty
bool Hand::isEmpty() const {
    return cards.empty();
}

// Get the count of cards in the hand
int Hand::getCardCount() const {
    return cards.size();
}
