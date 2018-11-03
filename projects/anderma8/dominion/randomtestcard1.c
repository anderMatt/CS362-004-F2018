/**************************************************
 * Matthew Anderson
 * 10/31/18
 * CS 362 Assignment 4
 * 
 * Random test generator for the 'Village' card.
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
    report_result(startingActions+2, numActions, "\t\t*FAILED* Expected to have %i actions. Actually have %i actions\n");

    // Play a random number of villages in a turn.
    puts("\tMultiple Village effects accumulate.");
    struct gameState preState;
    memcpy(&state, &preState, sizeof(struct gameState));

    int startingActionCount = state.numActions;
    numActions = floor(Random() * MAX_HAND);  // Maximum number of villages that could theoretically be played.
    for(int i = 0; i < numActions; i++) {
        playVillage(&state, pos);
    }

    int afterActionCount = state.numActions;
    // Ensure there were no unintended sideffects
    assert(memcmp(&preState, &state, sizeof(struct gameState)) == 0);
    report_result(startingActionCount + numActions, afterActionCount, "\t\t*FAILED* Expected action count to be %i, but is actually %i\n");

    return 0;
}