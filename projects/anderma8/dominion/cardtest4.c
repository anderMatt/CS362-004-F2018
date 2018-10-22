/*************************
Matthew Anderson
10/21/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for Treasure Map.
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
    int deck[] = {copper, adventurer, smithy, salvager, outpost, duchy, treasure_map};

    memcpy(state->deck[player], deck, sizeof(deck));

    int hand[][3] = {
            {treasure_map, village, embargo},
            {province, village, embargo},
            {province, village, embargo}
    };

    memcpy(state->hand, hand, sizeof(hand));

    for(int i = curse; i <= treasure_map; i++) {
        state->supplyCount[i] = 10;
    }
}

void setHand(struct gameState *state, int newHand[3]) {
    memcpy(state->hand[0], newHand, sizeof(int) * 3);
    state->handCount[0] = 3;
}

int hand_contains(struct gameState *state, int player, int card) {
    for(int i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) {
            return 1;  // Contains card.
        }
    }

    return 0;  // Does not contain card.
}

int deck_count_card(struct gameState *state, int player, int card) {
    int counter = 0;
    for (int i = 0; i < state->deckCount[player]; i++) {
        if (state->deck[player][i] == card) {
            counter++;
        }
    }

    return counter;
}

int deck_contains_count(struct gameState *state, int player, int card, int count) {
    int counter = 0;
    for (int i = 0; i < state->deckCount[player]; i++) {
        if (state->deck[player][i] == card) {
            counter++;
        }
    }

    return (counter == count);
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


    puts("**********\nUnit Tests for 'Treasure Map'\n**********\n");

    puts("Hand contains no other Treasure Maps.");
    int hand[] = {
            treasure_map, baron, smithy
    };

    setHand(&state, hand);

    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);

    expected = 0;
    actual = deck_count_card(&state, player, gold);
    char errMsg[100];
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);


    puts("Hand contains one other Treasure Map.");
    init_state(&state);
    int treasureMapHand[] = {treasure_map, baron, treasure_map};
    setHand(&state, treasureMapHand);
    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);

    expected = 4;
    actual = deck_count_card(&state, player, gold);
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);

    puts("Hand contains more than one other Treasure Map.");
    init_state(&state);
    int multiTreasureMapHand[] = {treasure_map, treasure_map, treasure_map};
    setHand(&state, multiTreasureMapHand);
    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);
    expected = 4;
    actual = deck_count_card(&state, player, gold);
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);


    return 0;
}