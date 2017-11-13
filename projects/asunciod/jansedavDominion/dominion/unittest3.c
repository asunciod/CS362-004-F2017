//Unit Test for End Turn function

#include "dominion.h"
#include <stdio.h>

//Function to test if the end turn function in dominion.c works properly
void End_Turn()
{
struct gameState game;
int seed = 100;
//Get all the cards in the deck that are possible
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

//Initialize the game
initializeGame(2, cards, seed, &game);

printf("\n\n UNIT TEST 3 ENDTURN-----------------------------------------------------\n\n");
int i;

		//Run each test a couple times to make sure the results are correct
		for(i = 0; i < 2; i++)
		{
			//Check to see which player you are on and if it is correct and end their turn
			int who = whoseTurn(&game);
			int	who2 = who+1;
			printf("Checking to see if it is Player 1's turn and ending the turn:\n");
			printf(" The current player that is up for their turn is: %d\n\n", who2);
		//Check to see if the player is correctly player 1.
			if(who2 != 1)
			{
			printf(" FAILED\n");
			}
			else
			printf(" SUCCESS\n");
			endTurn(&game);
			//Make sure the new player is the correct player after the last turn was ended and then end their turn
			who = whoseTurn(&game);
			printf("Checking to see if it is Player 2's turn and ending the turn:\n");
			who2 = who+1;
			printf(" The current player that is up for their turn is: %d\n\n", who2);
		//Check to see if the player is now player 2
			if(who2 != 2)
			{
			printf(" FAILED\n");
			}
			else
			printf(" SUCCESS\n");
			endTurn(&game);

		}	
printf("UNIT TEST 3 ENDTURN DONE---------------------------------------------------------\n");
}

int main()
{
End_Turn();
return 0;
}

