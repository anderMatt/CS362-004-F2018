/*************************
Matthew Anderson
10/21/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for Smithy
 *
 */

// Initializes state to validate card effect.
void init_state(struct gameState *state) {
    int player = 0;

    state->whoseTurn = player;
    state->numPlayers = 3;
    state->deckCount[player] = 5;
    state->discardCount[player] = 0;
    state->handCount[player] = 1;

    int hand[][3] = {
            {5, 5, 5},
            {5, 5, 5},
            {5, 5, 5}
    };

    memcpy(state->hand, hand, sizeof(hand));
}


void report_result(int expected, int actual, char *errMessage) {
    if (expected == actual) {
        puts("\tPassed.");
    } else {
        printf("\tFailed. %s\n", errMessage);
    }
}

int main(int argn, char **argv) {
    struct gameState state;
    init_state(&state);

    int player = 0;
    int actual,
        expected;


    puts("**********\nUnit Tests for 'Smithy'\n**********\n");
    puts("Draws three cards from the deck.");

    // Smithy correctly draws 3 cards from the deck.
    cardEffect(smithy, 0, 0, 0, &state, 0, NULL);
    expected = 2;
    actual = state.deckCount[player];

    char errMsg[100];
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Expected deck to contain %i cards. Actually contains %i cards.", expected, actual);
    report_result(expected, actual, errMsg);

    // Hand count should be 3 - stated at one, draw three cards, then discard the Smithy.
    expected = 3;
    actual = state.handCount[player];
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Expected hand to contains %i cards. Actually contains %i cards.", expected, actual);
    report_result(expected, actual, errMsg);


    return 0;
}