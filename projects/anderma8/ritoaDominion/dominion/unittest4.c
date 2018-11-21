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
 * Unit tests for buyCard
 *
 * This function contains logic to allow the turn
 * player to purchase a card from a supply line.
 *
 */


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

    int success = buyCard(supplyIndex, &state);

    if (success != 0) {
        puts("\t Failed: Unable to buy card.");
    } else {
        expected = 2;  // 2 coins (silver) - 0 (cost of card) = 2
        actual = state.coins;
        char errMsg[50];
        sprintf(errMsg, "Expected coins remaining: %i, but actual was: %i", expected, actual);
        report_result(expected, actual, errMsg);

    }

    puts("Buying card correctly decreases available buys.");
    expected = 0;
    actual = state.numBuys;
    char errMsg[50];
    sprintf(errMsg, "Expected buys remaining: %i, but actual was: %i", expected, actual);
    report_result(expected, actual, errMsg);

    return 0;
}