/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - unittest3.c
* testing function: whoseTurn()
*
* testWhoseTurn: unittest3.c dominion.o rngs.o
*      gcc -o testWhoseTurn -g  unittest3.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int seed = 1000;
	int numPlayer = 2;
	int turn_checks = 5;
	int games_to_play = 4;
	int p, q;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	printf("TESTING whoseTurn():\n");

	for (q = 0; q < games_to_play; q++) {

		//initialize games up to 4 times
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G); // initialize a new game

		#if (NOISY_TEST == 1)
			printf("\nSTARTING GAME NUMBER %d........\n", q + 1);
		#endif

		//loop to check current and next players
		for (p = 0; p < turn_checks; p++)
		{

			//get current player
			int current_player = whoseTurn(&G);

			//get who is supposed to be the next player
			int next_player = whoseTurn(&G) == 1 ? 0 : whoseTurn(&G) + 1;

			//TEST 1 - check current player before turn ends
			#if (NOISY_TEST == 1)
				printf("\nCURRENT TURN CHECK........\n");
			#endif

			#if (NOISY_TEST == 1)
				printf("current player = %d, expected = %d\n", current_player, p % 2);
			#endif

			//current player turn should always be 0, then 1
			assert(current_player == p % 2);

			//TEST 2 - check next player before turn ends
			#if (NOISY_TEST == 1)
				printf("\EXPECTED NEXT TURN CHECK........\n");
			#endif

			#if (NOISY_TEST == 1)
				printf("next player = %d, expected = %d\n", next_player, (p + 1) % 2);
			#endif

			//next player turn should always be 1, then 0
			assert(next_player == (p + 1) % 2);

			//END TURN -- end current player's turn
			#if (NOISY_TEST == 1)
				printf("\nEND CURRENT PLAYER TURN.\n\n");
			#endif
			endTurn(&G);

			//TEST 3 - check current player after turn ends
			#if (NOISY_TEST == 1)
				printf("AFTER TURN END, CHECK CURRENT PLAYER....\n");
			#endif

			//get current player
			current_player = whoseTurn(&G);

			#if (NOISY_TEST == 1)
				printf("current player = %d, expected = %d\n", current_player, (p + 1) % 2);
			#endif

			//current player turn should always be 0, then 1
			assert(current_player == next_player);

		}

	}

	printf("\nAll tests passed!\n");

	return 0;
}
