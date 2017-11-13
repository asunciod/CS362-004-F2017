/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - cardtest3.c
* testing card: gardens
*
* cardtest3: cardtest3.c dominion.o rngs.o
*      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "gardens"

int main() {
	
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n\n", TESTCARD);

	// ----------- TEST 1: check return value of garden card --------------
	printf("TEST 1: check if deck is shuffled when deckcount < 1\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[0][0] = gardens;

	//run card effect
	int garden_val = cardEffect(gardens, choice1, choice2, choice3, &testG, handpos, &bonus);
	
	printf("expected garden card return value = -1\n");
	
	if (garden_val == -1) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}

	
	printf("\n\n >>>>> Testing complete for %s <<<<<\n\n", TESTCARD);


	return 0;
}




