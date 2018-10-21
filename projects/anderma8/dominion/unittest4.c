/*************************
Matthew Anderson
10/16/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for buyCard
 *
 * This function contains logic to allow the turn
 * player to purchase a card from a supply line.
 *
 */

/********** Helpers **********/

void report_result(int expected, int actual, char *errMessage) {
    if (expected == actual) {
        puts("\tPassed.");
    } else {
        printf("\tFailed. %s\n", errMessage);
    }
}

void replenish_supply_count(struct gameState *state) {
    for (int i = 0; i < 25; i++) {
        state->supplyCount[i] = i+1;
    }
}

int main(int argn, char **argv) {
    struct gameState state;
    int expected,
        actual;

    int supplyIndex = 0;
    state.whoseTurn = 0;

    puts("**********\nUnit Tests for 'buyCard'\n**********\n");


    /***** Condition: Player has no buys remaining. *****/
    puts("Player has no remaining buys.");

    replenish_supply_count(&state);
    state.numActions = 0;

    expected = -1;
    actual = buyCard(supplyIndex, &state);
    report_result(expected, actual, "Expected buyCard to fail.");


    /***** Condition: Desired supply count is empty. *****/
    puts("Supply is empty");

    state.supplyCount[supplyIndex] = 0;
    expected = -1;
    actual = buyCard(supplyIndex, &state);
    report_result(expected, actual, "Expected failure: Supply line is empty.");


    /***** Condition: Player does not have sufficient money. *****/
    puts("Player does not have enough coins.");
    replenish_supply_count(&state);
    state.coins = 2;

    state.supplyCount[supplyIndex] = baron;
    expected = -1;
    actual = buyCard(supplyIndex, &state);
    report_result(expected, actual, "Expected failure: card costs 4, only 2 coins available.");


    /***** Condition: Buying a card successfully updates game state. *****/
    puts("Buying card correctly decreases available coins.");
    state.supplyCount[supplyIndex] = 2;
    state.numBuys = 1;

    // Buy card should succeed.
//    printf("BEFORE BUY: %i", state.coins);
    int success = buyCard(supplyIndex, &state);
//    printf("AFTER BUY: %i", state.coins);

    if (success != 0) {
        puts("\t Failed: Unable to buy card.");
    } else {
        expected = 2;  // 2 coins (silver) - 0 (cost of card) = 2
        actual = state.coins;
        char errMsg[50];
        sprintf(errMsg, "Expected coins remaining: %i, but actual was: %i", expected, actual);
        report_result(expected, actual, errMsg);

    }

    puts("Buying card correctly decreases availabe buys.");
    expected = 0;
    actual = state.numBuys;
    char errMsg[50];
    sprintf(errMsg, "Expected buys remaining: %i, but actual was: %i", expected, actual);
    report_result(expected, actual, errMsg);
}