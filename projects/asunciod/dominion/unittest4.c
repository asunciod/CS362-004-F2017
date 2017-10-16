/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - unittest3.c
* testing function: handCard()
*
* testHandCard: unittest4.c dominion.o rngs.o
*      gcc -o testHandCard -g  unittest4.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int p;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	
	printf("TESTING handCard():\n\n");

	//initialize a game
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game

	for (p = 0; p < 5; p++)
	{
		int current_player = whoseTurn(&G);

		#if (NOISY_TEST == 1)
			printf("CURRENT PLAYER %d....\n\n", current_player);
		#endif

		// TEST 1 -- 
		// set hand values to non-valid integers
		// handCard returns a non-valid integer
		// cardNumToName returns default
		#if (NOISY_TEST == 1)
			printf("CHECKING IF CARD INTEGER IS OUT OF VALID BOUNDS [0...26]....\n");
		#endif

		G.handCount[current_player] = 5;                 // set the number of cards on hand
		memcpy(G.hand[current_player], "", sizeof(int) * 5);
		int current_card = handCard(2, &G);

		//true if card is out of bounds
		assert(current_card < 0 || current_card > 26);

		#if (NOISY_TEST == 1)
			printf("CHECKING IF NON-VALID INTEGER RETURNS \"?\" AS CARD NAME....\n");
		#endif

		char name[MAX_STRING_LENGTH];
		cardNumToName(current_card, name);

		//check if non-valid integer returns default name of a card, "?"
		assert(strcmp(name, "?") == 0);

		//END TEST 1

		// TEST 2 -- 
		// check all possible valid integer values in range [0...26]
		#if (NOISY_TEST == 1)
				printf("CHECKING ALL POSSIBLE VALID INTEGERS [0...26]....\n\n");
		#endif
		
		// set the number of cards on hand
		G.handCount[current_player] = 27;                 

		//fill in player's hand with valid card numbers
		for (i = 0; i < 27; i++) {
			G.hand[current_player][i] = i;
		}

		for (i = 0; i < 27; i++) {
			current_card = handCard(i, &G);
			cardNumToName(current_card, name);

			//check if valid integers returns a valid name that is not the default "?"
			assert(strcmp(name, "?") != 0);
		}
		//END TEST 2

		endTurn(&G);
	}

	printf("All tests passed!\n");

	return 0;
}
