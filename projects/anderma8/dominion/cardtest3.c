/*************************
Matthew Anderson
10/21/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for Great Hall
 *
 */

// Initializes state to validate card effect.
void init_state(struct gameState *state) {
    int player = 0;

    state->playedCardCount = 0;
    state->numActions = 0;
    state->whoseTurn = player;
    state->numPlayers = 3;
    state->deckCount[player] = 6;
    state->discardCount[player] = 0;
    state->handCount[player] = 1;
    int deck[] = {copper, adventurer, smithy, salvager, gold, outpost, duchy, treasure_map};

    memcpy(state->deck[player], deck, sizeof(deck));

    int hand[][3] = {
            {province, village, embargo},
            {province, village, embargo},
            {province, village, embargo}
    };

    memcpy(state->hand, hand, sizeof(hand));
}

int hand_contains(struct gameState *state, int player, int card) {
    for(int i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) {
            return 1;  // Contains card.
        }
    }

    return 0;  // Does not contain card.
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

    // We'll explicitly keep track of these cards to validate the card effect.


    puts("**********\nUnit Tests for 'Great Hall'\n**********\n");


    cardEffect(great_hall, 0, 0, 0, &state, 0, NULL);
    expected = 1;
    actual = (state.numActions == 1);

    puts("One action gained.");
    char errMsg[100];
    snprintf(errMsg, 100, "Expected to gain one action. Actually gained: %i actions", (state.numActions));  // Started with 0 actions.
    report_result(expected, actual, errMsg);

    puts("One card drawn.");
    memset(errMsg, '\0', 100);
    int handSize = sizeof(state.handCount[player]) / sizeof(int);
    snprintf(errMsg, 100, "Expected hand count: %i, Actual hand count: %i", 1, state.handCount[player]);
    actual = (handSize == 1);
    report_result(expected, actual, errMsg);

    return 0;
}