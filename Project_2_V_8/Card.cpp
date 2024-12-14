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
Card::Card(unsigned char n) {
    crdNum = n % 52;
}

// Copy constructor
Card::Card(const Card& other) {
    crdNum = other.crdNum;
}

// Get card suit
unsigned char Card::suit() const {
    char s[] = {'S', 'D', 'C', 'H'}; // Spade, Diamond, Clubs, Heart
    return s[crdNum / 13];
}

// Get card face
unsigned char Card::face() const {
    char f[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    return f[crdNum % 13];
}

// Get card value
unsigned char Card::value() const {
    unsigned char n = crdNum % 13;
    return n < 10 ? n + 1 : 10; // Aces are 1, face cards are 10
}

// Overloaded equality operator
bool Card::operator==(const Card& other) const {
    return crdNum == other.crdNum; // Compare the internal card number
}

// Overloaded inequality operator
bool Card::operator!=(const Card& other) const {
    return !(*this == other); // Use the equality operator
}

// Overloaded assignment operator
Card& Card::operator=(const Card& other) {
    if (this != &other) { // Prevent self-assignment
        crdNum = other.crdNum;
    }
    return *this;
}

// Overloaded stream insertion operator
ostream& operator<<(ostream& os, const Card& card) {
    os << card.face() << " of " << card.suit();
    return os;
}



