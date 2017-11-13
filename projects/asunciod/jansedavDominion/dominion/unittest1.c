//Unit Test for the shuffle function of Dominion

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>

//Function that tells which players deck was shuffled and if the shuffling passed or failed.
int Pass_Fail(int pass, int i, int player)
{
	//If the function returns 0 it was succesful
	if(pass == 0)
	{
		printf(" Test %d for player %d PASSED\n", i, player);	
		return 0;
	}
	//If the function returns -1 it failed
	else if(pass == -1)
	{
		printf(" Test %d for player %d FAILED\n", i, player);
		return 1;
	}
return 0;	
}

//Function to test if the shuffle function in dominion actually works.
int Shuffle_Unit()
{
	//Seed I randomly chise
	int seed = 100;
	struct gameState game;

//list of cards I need to test the shuffle function.
	int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

	//Initialize the game
	initializeGame(2, cards, seed, &game);

	printf("\n\nUNIT TEST 1 SHUFFLE---------------------------------------------\n");

	int i;

	//Run the tests 5 times to see if they are working.
	for(i = 1; i <= 5; i++)
	{
		//Checking to see if the shuffle works for player 1
		printf("Shuffle for turn number %d\n",i);
		int Pass1 = shuffle(1, &game);
		Pass_Fail(Pass1, i, 1);
		//Ending player 1's turn
		endTurn(&game);
	
		//Checking to see if the shuffle works for player 2
		int Pass2 = shuffle(2, &game);
		Pass_Fail(Pass2, i, 2);
		//Ending player 2's turn
		endTurn(&game);

	}
	//Finished testing
	printf("\nUNIT TEST 1 SHUFFLE DONE---------------------------------------------\n");
return 0;
}

int main()
{
Shuffle_Unit();
return 0;
}
