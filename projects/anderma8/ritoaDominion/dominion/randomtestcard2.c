/**************************************************
 * Matthew Anderson
 * 11/21/18
 * CS 362 Assignment 5
 * 
 * Random test generator for the 'Great Hall' card.
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
    // Additional state variables great hall assumes are valid. We must ensure
    // these are set for ALL tests, because random initialization may not be sufficient.


    puts("*** Great Hall random tests ***");

    // Check card is drawn.
    int player = state.whoseTurn;
    printf("Before cardToDraw\n");
    int cardToDraw = state.deck[player][0];
    printf("Card to draw: %i\n\n", cardToDraw);
    int startingActions = state.numActions;

    // Add Great Hall to hand.
    int pos = state.handCount[player];
    state.hand[player][pos] = great_hall;
	state.playedCardCount = 5;


    cardEffect(great_hall, 0, 0, 0, &state, pos, NULL);
    // Correct card was drawn, from correct player's deck.
    puts("\t Great Hall draws a card from the player's deck.");

    int cardDrawn = state.hand[player][state.handCount[player]-1];
    report_result(cardToDraw, cardDrawn, "\t\t*FAILED* Expected to draw card %i. Actually drew card: %i\n");

    puts("\tGreat Hall grants player one action.");

    int numActions = state.numActions;
    report_result(startingActions+1, numActions, "\t\t*FAILED* Expected to have %i actions. Actually have %i actions\n");

    // Play a random number of Great Halls in a turn.
    puts("\tPlaying multiple Great Halls in a single turns accumlates the effect.");
    struct gameState preState;
    memcpy(&state, &preState, sizeof(struct gameState));

    int startingActionCount = state.numActions;
    numActions = floor(Random() * MAX_HAND);  // Maximum number of Great Halls that could theoretically be played.
    for(int i = 0; i < numActions; i++) {
        cardEffect(great_hall, 0, 0, 0, &state, pos, NULL);
        
    }

    int afterActionCount = state.numActions;
    // Ensure there were no unintended sideffects
    // assert(memcmp(&preState, &state, sizeof(struct gameState)) == 0);
    memcpy(&state, &preState, sizeof(struct gameState));
    game_state_is_equal(&preState, &state, "\t\tGame states are not equal");
    report_result(startingActionCount + numActions, afterActionCount, "\t\t*FAILED* Expected action count to be %i, but is actually %i\n");


    puts("\t Great Hall effect triggers correctly regardless of hand");
    int preHandSize,
        postHandSize,
        preActionCount,
        postActionCount;

    // Card effect works regardless of hand size or contents.
    // Hand is randomly generated from all possible hand sizes.
    int handSize = floor(Random() * MAX_HAND);
    game_state_set_hand_random(&state, player, handSize);
    preHandSize = state.handCount[player];
    preActionCount = state.numActions;
    cardEffect(great_hall, 0, 0, 0, &state, pos, NULL);
    postHandSize = state.handCount[player];
    postActionCount = state.numActions;
    if ((postHandSize +1 != preHandSize) || (postActionCount-1 != preActionCount)) {
        printf("\\ttFailed with hand size of %i\n", handSize);
    } else {
        printf("\t\tPassed.\n");
    }

    return 0;
}
