/* 
 * File:   Player.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"

#include <string>
using namespace std;

class Player {
    protected:
        int id;
        string name;
        Hand *hand; // Pointer to a Hand object
        static int totalScore; // Static variable to track total score
    public:
        Player(string pName);  // Parameterized constructor
        Player();             // Default constructor
        ~Player();            // Destructor to manage memory
        string getName() const; // Getter for name
        
        static void addToTotalScore(int score); // Add to total score
        static int getTotalScore();            // Get the total score
};

#endif /* PLAYER_H */