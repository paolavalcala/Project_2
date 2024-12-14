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

// Constructor
Hand::Hand() {}

// Destructor
Hand::~Hand() {
    for (size_t i = 0; i < cards.size(); ++i) {
        delete cards[i];
    }
    cards.clear();
}

// Add a card to the hand
void Hand::addCard(Card* card) {
    cards.push_back(new Card(*card));
}

// Display the cards in the hand
void Hand::display() const {
    for (size_t i = 0; i < cards.size(); ++i) {
        cout << *cards[i] << endl;
    }
}

// Check if the hand has a card with the given value
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
    for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->value() == value) {
            Card* removedCard = *it;
            cards.erase(it);
            return removedCard;
        }
    }
    return nullptr;
}

// Check if the hand is empty
bool Hand::isEmpty() const {
    return cards.empty();
}

// Find matching pairs
vector<pair<Card*, Card*> > Hand::findMatches() const {
    vector<pair<Card*, Card*> > matches;
    for (size_t i = 0; i < cards.size(); ++i) {
        for (size_t j = i + 1; j < cards.size(); ++j) {
            if (cards[i]->value() == cards[j]->value()) {
                matches.push_back(make_pair(cards[i], cards[j]));
            }
        }
    }
    return matches;
}

// Get the count of cards in the hand
int Hand::getCardCount() const {
    return static_cast<int>(cards.size());
}