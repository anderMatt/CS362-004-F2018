/*************************
Matthew Anderson
10/21/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "testhelpers.h"

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


void report_result(int expected, int actual, char *errMessage) {
    if (expected == actual) {
        puts("\t\tPassed.");
    } else {
        printf("\t\tFailed. %s\n", errMessage);
    }
}

int main(int argn, char **argv) {
    struct gameState state;
    init_state(&state);

    int player = 0;
    int actual,
        expected;


    puts("**********\nUnit Tests for 'Treasure Map'\n**********\n");

    puts("Hand contains no other Treasure Maps.");

    int hand[] = {
            treasure_map, baron, smithy
    };

    setHand(&state, player, hand, 3);

    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);

    expected = 0;
    actual = deck_count_card(&state, player, gold);
    char errMsg[100];
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);


    puts("Hand contains one other Treasure Map.");

    puts("\t4 Gold added to deck.");

    init_state(&state);
    int treasureMapHand[] = {treasure_map, baron, treasure_map};
    setHand(&state, player, treasureMapHand, 3);
    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);

    expected = 4;
    actual = deck_count_card(&state, player, gold);
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);

    puts("\tTreasure Map cards are trashed.");
    expected = 0;
    actual = hand_contains(&state, player, 0);
    snprintf(errMsg, 100, "Expected hand to contain no Treasure Maps. Actually contains: %i", actual);
    report_result(expected, actual, errMsg);

    puts("Hand contains more than one other Treasure Map.");

    puts("\t 4 Gold added to deck.");

    init_state(&state);
    int multiTreasureMapHand[] = {treasure_map, treasure_map, treasure_map};
    setHand(&state, player, multiTreasureMapHand, 3);
    cardEffect(treasure_map, 0, 0, 0, &state, 0, NULL);
    expected = 4;
    actual = deck_count_card(&state, player, gold);
    snprintf(errMsg, 100, "Expected deck to contain %i Gold. Actually contains: %i Gold", expected, actual);
    report_result(expected, actual, errMsg);

    puts("\t Two Treasure Maps trashed from hand.");
    expected = 1;
    actual = hand_count_card(&state, player, treasure_map);
    snprintf(errMsg, 100, "Expected hand to contain one Treasure Map. Actually contains: %i", actual);
    report_result(expected, actual, errMsg);


    return 0;
}