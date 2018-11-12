/**************************************************
 * Matthew Anderson
 * 11/12/18
 * CS 362 Assignment 4
 * 
 * Random test generator for the 'Adventurer' card.
**************************************************/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "dominion.h"
#include "testhelpers.h"
#include "rngs.h"

int main(int argn, char **argv) {
    PutSeed(3);
    SelectStream(2);

    struct gameState state;
    game_state_initialize_random_full(&state);

    puts("*** Adventurer random tests ***");

    puts("\t 2 or more treasure are in the player's deck");
    int player = 0;

    // Need to make sure there are at least 2 treasure cards in deck - add manually
    // here to skew the random percentages.
    state.deck[player][0] = copper;
    state.deck[player][7] = gold;

    int startingHandSize = state.handCount[player];
    int startingDeckSize = state.deckCount[player];

    cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);
    int afterHandSize = state.handCount[player];
    int expectedHandSize = startingHandSize + 2;  // Draw two net cards.
    report_result(expectedHandSize, afterHandSize, "\t\tExpected hand to contain %i cards. Actually contains %i cards.\n");

    // Make sure cards were drawn from the turn player's deck.
    int afterDeckSize = state.deckCount[player];
    int expectedDeckSize = startingDeckSize - 10;  // Based on indices we added treasures to the deck.
    report_result(expectedDeckSize, afterDeckSize, "\t\tExpected deck to contain %i cards. Actually contains %i cards.\n");


    return 0;
}