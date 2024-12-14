/* 
 * File:   main.cpp
 * Author: Paola Alcala
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 7
 */

#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"
using namespace std;

// Function prototypes for score display and initial match check
void displayScores(const Player& player1, const Hand& matchesDeck1, const Player& player2, const Hand& matchesDeck2);
void checkInitialMatches(Player& player, Hand& hand, Hand& matchesDeck);

int main(int argc, char** argv) {
    Player* player1;
    Player* player2;
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
        player1 = new HumanPlayer(player1Name);
        player2 = new HumanPlayer(player2Name);
    } else if (choice == 2) {
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);
        player1 = new HumanPlayer(playerName);
        player2 = new ComputerPlayer();
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
    cout << player1->getName() << "'s Hand:\n";
    hand1.display();
    cout << "\n" << player2->getName() << "'s Hand:\n";
    hand2.display();

    // Check for initial matches
    cout << "\nChecking for initial matches...\n";
    checkInitialMatches(*player1, hand1, matchesDeck1);
    checkInitialMatches(*player2, hand2, matchesDeck2);

    // Game loop for player turns
    bool gameActive = true;
    bool player1Turn = true;

    while (gameActive) {
        Player& currentPlayer = player1Turn ? *player1 : *player2;
        Hand& currentHand = player1Turn ? hand1 : hand2;
        Hand& opponentHand = player1Turn ? hand2 : hand1;
        Hand& currentMatchesDeck = player1Turn ? matchesDeck1 : matchesDeck2;
        Player& opponent = player1Turn ? *player2 : *player1;

        cout << "\n" << currentPlayer.getName() << "'s turn.\nYour hand:\n";
        currentHand.display();

        int requestedValue;
        if (dynamic_cast<ComputerPlayer*>(&currentPlayer)) {
            requestedValue = rand() % 10 + 1; // AI selects a random value
            cout << currentPlayer.getName() << " asks for card value: " << requestedValue << "\n";
        } else {
            cout << "Ask for a card value (1-10): ";
            cin >> requestedValue;
        }

        if (opponentHand.hasCard(requestedValue)) {
            cout << opponent.getName() << " has the card! Transferring...\n";
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
            displayScores(*player1, matchesDeck1, *player2, matchesDeck2);
            continue;
        } else {
            cout << opponent.getName() << " does not have the card. Go Fish!\n";
            Card* newCard = dealer.dealCard();
            if (newCard) {
                currentHand.addCard(newCard);
                cout << currentPlayer.getName() << " drew a card: " << newCard->face() << " of " << newCard->suit() << "\n";
            } else {
                cout << "The deck is empty!\n";
            }
        }

        cout << "\nUpdated Scores:\n";
        displayScores(*player1, matchesDeck1, *player2, matchesDeck2);

        // Display each player's hand
        cout << "\n" << player1->getName() << "'s Hand:\n";
        hand1.display();
        cout << "\n" << player2->getName() << "'s Hand:\n";
        hand2.display();

        // Check end-game conditions
        if (hand1.isEmpty() || hand2.isEmpty() || dealer.isDeckEmpty()) {
            gameActive = false;
            cout << "\nGame over! Final Scores:\n";
            displayScores(*player1, matchesDeck1, *player2, matchesDeck2);
            break;
        }

        player1Turn = !player1Turn;
    }

    delete player1;
    delete player2;

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
 For version 7 I will be automating the computer player.
 * I will be doing this utilizing abstract classes and inheritance.
 * 
 * 
  */





/// cloc /Users/paolaalcala/cis_17/CSC_CIS_17a/Project/Project2/Project_2_V_4