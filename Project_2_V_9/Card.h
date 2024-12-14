/* 
 * File:   Player.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

// Card class definition
class Card {
private:
    unsigned char crdNum; // Card number (0-51)

protected:
    // Protected methods to allow derived classes access
    virtual string getCardDetails() const;

public:
    Card(unsigned char n = 0);            // Constructor
    Card(const Card& other);             // Copy constructor
    virtual ~Card() {}                   // Virtual destructor for polymorphism

    unsigned char suit() const;          // Get suit
    unsigned char face() const;          // Get face
    unsigned char value() const;         // Get value

    // Overloaded operators
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    Card& operator=(const Card& other);

    // Friend functions
    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif /* CARD_H */