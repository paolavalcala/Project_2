/* 
 * File:   main.cpp
 * Author: Paola Alcala
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 6
 */

// System Libraries
#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

// Function prototypes for better modularity
void displayScores(const Player& player1, const Hand& matchesDeck1, const Player& player2, const Hand& matchesDeck2);
void checkInitialMatches(Player& player, Hand& hand, Hand& matchesDeck);

int main(int argc, char** argv) {
    Player player1, player2;
    Hand hand1, hand2, matchesDeck1, matchesDeck2;

    // Prompt for game mode
    int choice;
    cout << "Choose game mode:\n1. Two Players\n2. Play against the Computer\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string player1Name, player2Name;
        cout << "Enter Player 1's name: ";
        getline(cin, player1Name);
        cout << "Enter Player 2's name: ";
        getline(cin, player2Name);
        player1 = Player(player1Name);
        player2 = Player(player2Name);
    } else if (choice == 2) {
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);
        player1 = Player(playerName);
        player2 = Player("Computer");
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 0;
    }

    Deck deck(52);
    deck.shuffle();
    Dealer dealer;

    // Initial deal
    cout << "\nDealing cards to players...\n";
    for (int i = 0; i < 5; i++) {
        hand1.addCard(dealer.dealCard());
        hand2.addCard(dealer.dealCard());
    }

    // Display initial hands
    cout << "\nInitial Hands:\n";
    cout << player1.getName() << "'s Hand:\n";
    hand1.display();
    cout << "\n" << player2.getName() << "'s Hand:\n";
    hand2.display();

    // Check for initial matches
    cout << "\nChecking for initial matches...\n";
    checkInitialMatches(player1, hand1, matchesDeck1);
    checkInitialMatches(player2, hand2, matchesDeck2);

    // Game loop for player turns
    bool gameActive = true;
    bool player1Turn = true;

    while (gameActive) {
        Player& currentPlayer = player1Turn ? player1 : player2;
        Hand& currentHand = player1Turn ? hand1 : hand2;
        Hand& opponentHand = player1Turn ? hand2 : hand1;
        Hand& currentMatchesDeck = player1Turn ? matchesDeck1 : matchesDeck2;

        cout << "\n" << currentPlayer.getName() << "'s turn. Your hand:\n";
        currentHand.display();

        int requestedValue;
        cout << "Ask for a card value (1-10): ";
        cin >> requestedValue;

        if (opponentHand.hasCard(requestedValue)) {
            cout << "Opponent has the card! Transferring...\n";
            Card* transferredCard = opponentHand.removeCard(requestedValue);
            currentHand.addCard(transferredCard);

            // Check for matches
            auto newMatches = currentHand.findMatches();
            for (size_t i = 0; i < newMatches.size(); ++i) {
                currentMatchesDeck.addCard(newMatches[i].first);
                currentMatchesDeck.addCard(newMatches[i].second);
                currentHand.removeCard(newMatches[i].first->value());
                currentHand.removeCard(newMatches[i].second->value());
            }

            cout << "\nMatches found this turn:\n";
            currentMatchesDeck.display();

            cout << "\nUpdated Scores:\n";
            displayScores(player1, matchesDeck1, player2, matchesDeck2);

            continue;
        } else {
            cout << "Go Fish!\n";
            Card* newCard = dealer.dealCard();
            if (newCard) {
                currentHand.addCard(newCard);
                cout << currentPlayer.getName() << " drew: "
                     << newCard->face() << " of " << newCard->suit() << "\n";
            } else {
                cout << "Deck is empty! No card drawn.\n";
            }
        }

        cout << "\nUpdated Scores:\n";
        displayScores(player1, matchesDeck1, player2, matchesDeck2);

        // Check end-game conditions
        if (hand1.isEmpty() || hand2.isEmpty() || dealer.isDeckEmpty()) {
            gameActive = false;
            cout << "\nGame over! Final Scores:\n";
            displayScores(player1, matchesDeck1, player2, matchesDeck2);
            break;
        }

        player1Turn = !player1Turn;
    }

    return 0;
}

// Display scores for both players
void displayScores(const Player& player1, const Hand& matchesDeck1, const Player& player2, const Hand& matchesDeck2) {
    cout << player1.getName() << "'s Matches Deck: " << matchesDeck1.getCardCount() / 2 << " sets\n";
    cout << player2.getName() << "'s Matches Deck: " << matchesDeck2.getCardCount() / 2 << " sets\n";
}

// Check for initial matches and update hands and match decks
void checkInitialMatches(Player& player, Hand& hand, Hand& matchesDeck) {
    auto initialMatches = hand.findMatches();
    for (size_t i = 0; i < initialMatches.size(); ++i) {
        matchesDeck.addCard(initialMatches[i].first);
        matchesDeck.addCard(initialMatches[i].second);
        hand.removeCard(initialMatches[i].first->value());
        hand.removeCard(initialMatches[i].second->value());
    }
    cout << player.getName() << "'s Matches Deck:\n";
    matchesDeck.display();
}






/*
 For Version 6 I will be implementing a feature where players ask each other for cards.
 * 1.After submitting card request and the card matches the card should be removed from both players deck
 
 2.uapdate and output both players decks
 
 3.If no matches tell player to go fish.
 
 4.After player go fishes and retrieves a card from the center pile the players deck should 
 be outputed with the updated cards.
 
 5. Should announce wether each player has the card that is being requested 
  */





/// cloc /Users/paolaalcala/cis_17/CSC_CIS_17a/Project/Project2/Project_2_V_4