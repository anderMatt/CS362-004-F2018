/**************************************************
 * Matthew Anderson
 * 10/31/18
 * CS 362 Assignment 4
 * 
 * Random test generator for the 'Village' card.
**************************************************/

#include <stdio.h>

#include "dominion.h"
#include "testhelpers.h"
#include "rngs.h"

int main(int argn, char **argv) {
    SelectStream(2);
    PutSeed(3);

    struct gameState state;
    game_state_initialize_random(&state);

    puts("*** Village random tests ***");

    // Check card is drawn.
    int player = state.whoseTurn;
    int cardToDraw = state.deck[player][0];
    int startingActions = state.numActions;

    // Add village to hand.
    int pos = state.handCount[player] - 2;
    state.hand[player][pos] = village;

    playVillage(&state, pos);

    // Correct card was drawn, from correct player's deck.
    puts("\tCard is drawn from current player's deck.");

    int cardDrawn = state.hand[player][state.handCount[player]-1];
    report_result(cardToDraw, cardDrawn, "\t\t*FAILED* Expected to draw card %i. Actually drew card: %i\n");

    puts("\tPlayer gains one action.");

    int numActions = state.numActions;
    report_result(startingActions+1, numActions, "\t\t*FAILED* Expected to have %i actions. Actually have %i actions\n");

    // Play a random number of villages in a turn.





    


    return 0;

    // +1 card
    // +2 actions
}