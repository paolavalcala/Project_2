/* 
 * File:   Player.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include "Player.h"

Player::Player(string pName) : name(pName), id(0) {}

Player::Player() : name("Anonymous"), id(0) {}

string Player::getName() const {
    return name;
}      
