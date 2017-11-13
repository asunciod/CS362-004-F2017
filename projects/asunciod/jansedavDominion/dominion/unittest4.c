//Unit test to check is the game is over

#include "dominion.h"
#include <stdio.h>

//Function that tells me if the game is over or not
void Pass_Fail(int check)
{
if(check == 1)
printf("\n The game HAS ended!\n\n");
else
printf("\n The game has NOT ended!\n");
}


void Game_Over()
{
printf("\n\nUNIT TEST 4 GAMEOVER---------------------\n\n");
struct gameState game;
//random seed
int seed = 100;
//All the cards in the deck that I need for initialization of the game
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game
initializeGame(2, cards, seed, &game);

//Checking to see if the game will properly end when there are no more province cards left
printf("Checking to see if the game will end when the supply count of province is at 0:\n");
game.supplyCount[province] = 0;
int rand = isGameOver(&game);
Pass_Fail(rand);


//Checking to see if the game will properly end when 3 supply piles of cards have ran out.
printf("Checking to see if the game will end when the supply count of 3 supply piles are at 0:\n");
game.supplyCount[province] = 10;
game.supplyCount[5] = 0;
game.supplyCount[6] = 0;
game.supplyCount[7] = 0;
rand = isGameOver(&game);
Pass_Fail(rand);

//Checking to see if the game will not end when neither of the two above conditions are met.
printf("Checking to see if the game will not end when neither the province count is at 0 and there are not 3 supply with 0 count: \n");
game.supplyCount[5] = 5;
game.supplyCount[6] = 5;
game.supplyCount[7] = 5;
rand = isGameOver(&game);
Pass_Fail(rand);



printf("\n\nUNIT TEST 4 GAMEOVER DONE-----------------\n\n");
}

int main()
{
Game_Over();
return 0;
}
