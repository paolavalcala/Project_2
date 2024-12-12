/* 
 * File:   Player.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include "Player.h"

Player::Player(string pName) : name(pName), id(0), hand(nullptr) {}

Player::Player() : name("Anonymous"), id(0), hand(nullptr) {}

// Define the destructor
Player::~Player() {
    if (hand != nullptr) {
        delete hand;
        hand = nullptr; // Avoid dangling pointers
    }
}

string Player::getName() const {
    return name;
} 
