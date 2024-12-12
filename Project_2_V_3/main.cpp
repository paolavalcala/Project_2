
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 1
 */

//System Libraries
#include <iostream> // Input-Output Library
#include "Player.h"
#include "Deck.h"

using namespace std;

int main(int argc, char** argv) {
    // Prompt for game mode
    int choice;
    cout << "Choose game mode:\n";
    cout << "1. Two Players\n";
    cout << "2. Play against the Computer\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear input buffer for getline()

    if (choice == 1) {
        // Two players
        string player1Name, player2Name;
        cout << "Enter Player 1's name: ";
        getline(cin, player1Name);
        cout << "Enter Player 2's name: ";
        getline(cin, player2Name);

        Player player1(player1Name);
        Player player2(player2Name);

        cout << "\nWelcome " << player1.getName() << " and " << player2.getName() << "!\n";
    } else if (choice == 2) {
        // Player vs Computer
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);

        Player player(playerName);
        Player computer("Computer");

        cout << "\nWelcome " << player.getName() << "! You will be playing against " << computer.getName() << ".\n";
    } else {
        cout << "Invalid choice. Exiting program.\n";
        return 0;
    }

    // Create a deck
    Deck deck(52);
    cout << "\nDeck of Cards:\n";
    deck.display();
    
    // Shuffle the deck
    cout << "\nShuffling Deck...\n";
    deck.shuffle();

    cout << "\nShuffled Deck:\n";
    deck.display();

    return 0;
}




/*
 For Version 3 I will be manipulating the deck.
 Creating a shuffle function.
 Creating a function to distribute the cards into player's hands. 
  */