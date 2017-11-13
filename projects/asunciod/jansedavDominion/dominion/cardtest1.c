// Card test for adventurer

#include "dominion.h"
#include <stdio.h>
//Function to tell me if the test passed or failed
void Pass_Fail(int check)
{
	if (check != 0 )
	{
	printf("\n TEST FAILED!\n");
	}	
	else 
	printf("\n TEST WAS SUCCESFUL!\n");

}
//unit test function for the adventurer card
void adventur()
{
//random seed
int seed = 500;
struct gameState game;
//Cards needed for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

//Initialize the game
initializeGame(2, cards, seed, &game);
int temphand[500];
printf("\n\nCARD TEST 1 ADVENTURER--------------------------------------------------------------\n\n");

//Temps to hold hanc count and treasure count
int temp1;
int temp2;
int treasure = 0;

//Show the current hand count so you can see if it increases by 1
printf("\nChecking current hand count to see if it will increase by 1 and the treasure count by 1 once the adventure card is played:\n");
//Check the current amount of hand count and treasure count and set them to temps for comparison later.
temp1 = game.handCount[1];
temp2 = treasure;
printf("\n Current hand count %d\n", game.handCount[1]);
printf(" Current treasure count %d\n", treasure);
//Start by checking to see if the adventurer card ran all the way through.
printf("\nChecking to see if the adventurer card runs succesfully:\n");
int rand = adventurer_func(&treasure, &game, 1, 0, temphand, 0);
//Check if the run was succesful
Pass_Fail(rand);
//Check to see what the new hand count and treasure count are.
printf("\nChecking to see if current hand count has increased by 1 as well as treasure:\n");
printf("\n Current hand count %d\n", game.handCount[1]);
printf(" Current treasure count %d\n", treasure);

//Use the previous values set in temps to compare with the new value and check if they are correct, if they arent print an error.
if(treasure > temp2+1)
{
	printf(" FAIL TREASURE COUNT IS TOO HIGH!\n");
}
if(game.handCount[1] > temp1+1)
{
	printf("FAIL HAND COUNT IS TOO HIGH!\n");
}

printf("\n\nCARD TEST 1 ADVENTURER---------------------------------------------------------------\n");
}

int main()
{
adventur();
return 0;
}
