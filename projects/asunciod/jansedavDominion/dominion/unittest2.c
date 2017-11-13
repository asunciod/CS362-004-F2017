//Unit Test for Buy Card


#include "dominion.h"
#include <stdio.h>

//Function that tells me if a test was succesful or not.
void Pass_Fail(int check)
{
if(check == -1)
printf("\n This buy was not succesful\n\n");
else
printf("\n This buy was a success!\n\n");
}


int Buy_Card()
{
struct gameState game;
//Random seed
int seed = 100;
//The cards in the deck that I need for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game
initializeGame(2, cards, seed, &game);

printf("\n\nUNIT TEST 2 BUYCARD-------------------------------------------\n\n");

//Checking to see if you can make a buy with 0n buys left.
printf("Checking to see if buying with 0 buys left will fail:\n");

game.numBuys = 0;
game.coins = 100;
int rand = buyCard(1, &game);
Pass_Fail(rand);

//Checking to see if you can make a buy for a card that does not exist.
printf("Checking to see if buying a card that doesn't exist will fail: \n");

game.numBuys = 1;
rand = buyCard(100, &game);
Pass_Fail(rand);


//Checking to see if you can make a buy if you dont have enough money for a card.
printf("Checking to see if buying a card that you don't have enough money for will fail:\n");
game.numBuys = 1;
game.coins = 0;
rand = buyCard(5, &game);
Pass_Fail(rand);

//Checking to see if you have enough coins and buys if the buy will end up being succesful.
printf("Checking to see if you have enough coins and buys if the buy is succesful:\n");
game.numBuys = 1;
game.coins = 100;
rand = buyCard(5,  &game);
Pass_Fail(rand);

printf("UNIT TEST 2 BUYCARD DONE------------------------------------------\n");
return 0;
}

int main()
{

Buy_Card();

return 0;

}
