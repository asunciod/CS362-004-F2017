/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 4 - randomtestcard1.c
* testing card: outpost
*
* randomtestcard1: randomtestcard1.c dominion.o rngs.o
*      gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "card_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define TESTCARD "outpost"

int main() {
	int seed = 1000;
	int randomHandPos;
	int i, j;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G, testG;
	int min = 2;
	int max = 4;
	int numPlayers;

	printf("----------------- Testing Card: %s ----------------\n\n", TESTCARD);

	for (i = 0; i < 10; i++) {

		//range of players between 2-4
		numPlayers = (min + (rand() % (int)(max - min + 1)));

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));


		for (j = 0; j < numPlayers; j++) {

			int cur = whoseTurn(&testG);
			randomHandPos = rand() % 5;	//randomly select hand position
			testG.hand[cur][randomHandPos] = outpost;

			outpostCard(&testG, randomHandPos, cur);

			//check outpostplayed flag
			printf("TEST: Checking outpostPlayed flag for current player\n");
			printf("outpost played flag expected = %d, actual = %d\n", 1, testG.outpostPlayed);
			if (testG.outpostPlayed == 0) {
				printf("TEST PASS: FAILED...\n\n");
			}

			//check discarded card
			printf("TEST: Checking played cards for current player\n");
			printf("expected card in playedCards = %d, actual = %d\n", 23, testG.playedCards[0]);
			if (testG.playedCards[0] == 23) {
				printf("TEST PASS: SUCCESS...\n\n");
			}
			else {
				printf("TEST PASS: FAILED...\n\n");
			}
			
			endTurn(&testG);
		}


	}

	printf("\n\n >>>>>Testing complete for %s <<<<<\n\n", TESTCARD);

	return 0;
}
