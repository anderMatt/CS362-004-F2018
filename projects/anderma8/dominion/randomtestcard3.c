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
    game_state_initialize_random(&state);

    puts("*** Adventurer random tests ***");

    puts("\t 2 or more treasure are in the player's deck");
    int player = 0;

    // Need to make sure there are at least 2 treasure cards in deck - add manually
    // here to skew the random percentages.
    state.deck[0][player] = copper;
    state.deck[0][player] = gold;

    int startingHandSize = state.handCount[player];
    cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);
    int afterHandSize = state.handCount[player];
    int expectedHandSize = startingHandSize + 1;
    report_result(expectedHandSize, afterHandSize, "\t\tExpected hand to contain %i cards. Actually contains %i cards");


    return 0;
}