/*************************
Matthew Anderson
11/21/2018
CS 362 - Assignment 5
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "testhelpers.h"

/*
 * Unit tests for Adventurer
 *
 */

// Initializes state to validate card effect.
void init_state(struct gameState *state) {
    int player = 0;

    state->whoseTurn = player;
    state->numPlayers = 3;
    state->deckCount[player] = 8;
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


int main(int argn, char **argv) {
    struct gameState state;
    init_state(&state);

    int player = 0;

    // We'll explicitly keep track of these cards to validate the card effect.


    puts("**********\nUnit Tests for 'Adventurer'\n**********\n");


    cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);

    // First two treasures were added to hand.
    puts("Drawn Copper added to hand.");

    char errMsg[100];
    memset(errMsg, '\0', 100);
    int containsTreasure = hand_contains(&state, player, copper);
    snprintf(errMsg, 100, "Expected hand to contain Copper, but it does not");
    report_result(1, containsTreasure, errMsg);

    puts("Drawn Gold added to hand.");

    containsTreasure = hand_contains(&state, player, gold);
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Expected hand to contain Gold, but it does not");
    report_result(1, containsTreasure, errMsg);

    puts("All drawn cards removed from deck.");
    int expected = 3;
    int actual = state.deckCount[player];
    snprintf(errMsg, 100, "Expected deck to contain %i cards. Actually cards %i cards", expected, actual);
    report_result(expected, actual, errMsg);



    // Make sure the non-treasure cards were discarded.

    puts("Non-treasure cards drawn are discarded.");

    puts("\tSalvager discarded.");
    int containsNonTreasure = hand_contains(&state, player, salvager);
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Non-treasure card not discarded: Salvager");
    report_result(0, containsNonTreasure, errMsg);

    puts("\tAdventurer discarded.");

    containsNonTreasure = hand_contains(&state, player, adventurer);
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Non-treasure card not discarded: Adventurer");
    report_result(0, containsNonTreasure, errMsg);

    puts("\tSmithy discarded.");

    containsNonTreasure = hand_contains(&state, player, smithy);
    memset(errMsg, '\0', 100);
    snprintf(errMsg, 100, "Non-treasure card not discarded: Smithy");
    report_result(0, containsNonTreasure, errMsg);

    // None of the non-treasures remain in the hand.
    // Identified bug - if < 2 treasures (official rules - end after shuffle, if still < 2 treasures.)

    return 0;
}