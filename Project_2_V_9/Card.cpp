/* 
 * File:   Card.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:29 PM
 */

#include "Card.h"
#include <iostream>
using namespace std;

// Constructor
Card::Card(unsigned char n) : crdNum(n % 52) {}

// Copy constructor
Card::Card(const Card& other) : crdNum(other.crdNum) {}

// Get suit
unsigned char Card::suit() const {
    char suits[] = {'S', 'D', 'C', 'H'}; // Spades, Diamonds, Clubs, Hearts
    return suits[crdNum / 13];
}

// Get face
unsigned char Card::face() const {
    char faces[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    return faces[crdNum % 13];
}

// Get value
unsigned char Card::value() const {
    unsigned char val = crdNum % 13;
    return (val < 10) ? val + 1 : 10; // Face cards count as 10
}

// Overloaded equality operator
bool Card::operator==(const Card& other) const {
    return crdNum == other.crdNum;
}

// Overloaded inequality operator
bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

// Overloaded assignment operator
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        crdNum = other.crdNum;
    }
    return *this;
}

// Overloaded stream insertion operator
ostream& operator<<(ostream& os, const Card& card) {
    os << card.face() << " of " << card.suit();
    return os;
}

// Define the virtual method getCardDetails()
string Card::getCardDetails() const {
    return string(1, static_cast<char>(face())) + " of " + static_cast<char>(suit());
}