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
    game_state_initialize_random_full(&state);

    puts("*** Adventurer random tests ***");

    puts("\t 2 or more treasure are in the player's deck");
    int player = 0;

    // Need to make sure there are at least 2 treasure cards in deck - add manually
    // here to skew the random percentages.
    state.deck[player][0] = copper;
    state.deck[player][7] = gold;

    int startingHandSize = state.handCount[player];
    int startingDeckSize = state.deckCount[player];
    int startingDiscardSize = state.discardCount[player];
    int startingHandSize2 = state.handCount[player+1];
    int startingDeckSize2 = state.deckCount[player+1];
    int startingDiscardSize2 = state.discardCount[player+1];

    cardEffect(adventurer, 0, 0, 0, &state, 0, NULL);
    int afterHandSize = state.handCount[player];
    int expectedHandSize = startingHandSize + 2;  // Draw two net cards.
    report_result(expectedHandSize, afterHandSize, "\t\tExpected hand to contain %i cards. Actually contains %i cards.\n");

    puts("\t Cards drawn from turn player's deck.");
    // Make sure cards were drawn from the turn player's deck.
    int afterDeckSize = state.deckCount[player];
    int expectedDeckSize = startingDeckSize - 7;  // Based on indices we added treasures to the deck.
    report_result(expectedDeckSize, afterDeckSize, "\t\tExpected deck to contain %i cards. Actually contains %i cards.\n");

    puts("\t Non-treasures added to turn player's discard pile.");
    // Make sure non-treasure cards were properly discarded.
    int afterDiscardSize = state.discardCount[player];
    int expectedDiscardSize = startingDiscardSize + 7;
    report_result(expectedDiscardSize, afterDiscardSize, "\t\tExpected discard pile to contain %i cards. Actually contains %i cards.\n");


    // Make sure there weren't any unintended side effects for the non-turn player.
    puts("\t No unintended side effects for non-turn player state.");
    // Make sure non turn-player's hand, deck, and discard piles remain unchanged.
    puts("\t Non turn-player's deck remains unchanged.");
    int afterDeckSize2 = state.deckCount[player+1];
    report_result(startingDeckSize2, afterDeckSize2, "\t\tExpected non-turn player's deck to contain %i cards. Actually contains %i cards.\n");

    puts("\t Non turn-player's hand remains unchanged.");
    int afterHandSize2 = state.handCount[player+1];
    report_result(startingHandSize2, afterHandSize2, "\t\tExpected non-turn player's hand to contain %i cards. Actually contains %i cards.\n");

    puts("\t Non turn-player's discard pile unchanged.");
    int afterDiscardSize2 = state.discardCount[player+1];
    report_result(startingDiscardSize2, afterDiscardSize2, "\t\tExpected non-turn player's discard pile to contain %i cards. Actually contains %i cards.\n");


    return 0;
}