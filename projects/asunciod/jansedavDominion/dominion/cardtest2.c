//Card test for the Smithy function

#include "dominion.h"
#include <stdio.h>

//Function to output if the test I did passed or failed
void Pass_Fail(int check)
{
	if(check == 0)
	{
		printf("Test PASSED succesfuly!\n");
	}
	else
		printf("TEST FAILED");
}

//unit test function for the smithy card
void Smith()
{
//Random seed
int seed = 500;
struct gameState game;
//Cards needed for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game
initializeGame(2, cards, seed, &game);

	printf("\n\nCARD TEST 2 SMITHY-----------------------------------------------\n\n");
	//Check how many cards are in the hand and then run the smithy function
	printf("\nChecking to see how many cards are in the hand initially\n");
	printf("Number of cards in players hand: %d\n", game.handCount[1]);
	int	temp1 = game.handCount[1];
	printf("\nChecking to see if the smithy card will run succesfully:\n");
	int rand = smithy_func(1, &game, 0);
	//Check if it passed or failed
	Pass_Fail(rand);
	//Check to see if the new number of cards is correct
	printf("\nChecking to see if the amount of cards has increased by 2 (Should only increase by 2 because of the smithy card being discarded)\n");
	printf("Number of cards in players hand: %d\n", game.handCount[1]);
		//If the amount of cards is too high print a failed run.
		if(game.handCount[1] > temp1+2)
		{
		Pass_Fail(1);
		}
	printf("\n\nCARD TEST 2 SMITHY END-------------------------------------------\n\n");
}

int main()
{
Smith();
return 0;
}
