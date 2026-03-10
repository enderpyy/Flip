/* ========================================================================= */
// 11-zogwidrouhua-2a
//
// PROJECT FLIP
//
// The runtime for Flip Project 2 Part A
/* ========================================================================= */

#include <iostream>
#include "deck.h"
#include "card.h"
using namespace std;

/*
int main()
{
    // Before Shuffle
    cout << "><><>< Fresh Deck ><><><\n";
    deck standard_deck;
    cout << standard_deck;

    // After Shuffle
    standard_deck.shuffle();
    cout << standard_deck;
    
    return 0;
} // end main

*/

// function to run the game
void playFlip()
{
    // make and shuffle main deck
    deck main_deck;
    cout << "Main Deck Created\n";
    cout << main_deck;
    cout << endl;

    // shuffle the main deck 3 times as required
    for (int i = 0; i < 3; i++) {
        main_deck.shuffle();
        cout << endl;
    }
    

    cout << "\nMain Deck Shuffled\n";
    cout << main_deck;

    deck hand_deck(false); // make empty hand deck
    
    // Player draws 24 cards from the top of the deck placing them face down on the 
    // table without looking at them
    for (int i = 0; i < 24; i++)
    {
        hand_deck.replace(main_deck.deal());
    }

    //check for success
    cout << "\nCurrent Hand Deck\n";
    cout << hand_deck;

    cout << "\nRemaining Main Deck\n";
    cout << main_deck;


    // newly added section to fulfill the interactive flip game shown in part a
    cout << "\nWelcome to Flip game Let's Start!\n";

    int score = 0;
    int numberOfFlips = 0;
    char userInput;

    // game loop
    while (true)
    {
        cout << "\nPlz Enter f to flip a card or e to end and exit the game: ";
        cin >> userInput;

        if (userInput == 'e' || userInput == 'E')
        {
            break;
        }

        if (userInput != 'f' && userInput != 'F')
        {
            cout << "Invalid choice. Please enter either f or e, try again\n";
            continue;
        }

        node<card>* flipped = hand_deck.deal(); // flip the top card of the hand deck

        if (flipped == nullptr) // check if hand deck is empty
        {
            cout << "There are no more cards left in hand deck.\n";
            break;
        }

        // reveal flipped card 
        cout << "Flipped card: " << flipped->nodeValue;

        // get card value and calculate score
        int val = flipped->nodeValue.getValue();
        string suit = flipped->nodeValue.getSuit();

        // calculate score according to card
        if (val == 1)
            score += 10;
        else if (val == 11 || val == 12 || val == 13)
            score += 5;
        else if (val == 8 || val == 9 || val == 10)
            score += 0;
        else if (val == 7)
            score = score / 2;
        else if (val >= 2 && val <= 6)
            score = 0;

        // bonus point for hearts
        if (suit == "Heart")
            score += 1;

        numberOfFlips++; 
        cout << "Current score: " << score << endl;

        delete flipped; // bonus section for b6 each card only flipped once
    }

    cout << "\nGame Over!\n";
    cout << "Total Flips: " << numberOfFlips << endl;
    cout << "Final Score: " << score << endl;
} 

int main()
{
    playFlip();
    return 0;
} 