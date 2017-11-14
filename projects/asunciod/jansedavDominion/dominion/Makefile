CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

card_helpers.o: card_helpers.h card_helpers.c
	gcc -c card_helpers.c -g  $(CFLAGS)
	
dominion.o: dominion.h dominion.c card_helpers.o rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

#UNIT TESTS	FOR NON-CARD FUNCTIONS
testGetCost: unittest1.c dominion.o rngs.o
	gcc -o testGetCost -g unittest1.c dominion.o rngs.o $(CFLAGS)	
	testGetCost
	gcov unittest1.c -b

testIsGameOver: unittest2.c dominion.o rngs.o
	gcc -o testIsGameOver -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	testIsGameOver
	gcov unittest2.c -b
	
testWhoseTurn: unittest3.c dominion.o rngs.o
	gcc -o testWhoseTurn -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	testWhoseTurn
	gcov unittest3.c -b
	
testHandCard: unittest4.c dominion.o rngs.o interface.o
	gcc -o testHandCard -g unittest4.c dominion.o rngs.o interface.o $(CFLAGS)
	testHandCard
	gcov unittest4.c -b
#END UNIT TESTS	FOR NON-CARD FUNCTIONS

#UNIT TESTS	FOR CARD FUNCTIONS
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	cardtest1
	gcov cardtest1.c -b

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	cardtest2
	gcov cardtest2.c -b
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	cardtest3
	gcov cardtest3.c -b
	
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
	cardtest4
	gcov cardtest4.c -b
#END UNIT TESTS	FOR CARD FUNCTIONS

#RANDOM TEST GENERATOR
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	
randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
#END RANDOM TEST GENERATOR

#RULE TO MAKE ALL TESTS AND OUTPUT TO unittestresult.out 
rununittests: cardtest4 cardtest3 cardtest2 cardtest1 testHandCard testWhoseTurn testIsGameOver testGetCost
	./cardtest4 &> unittestresult.out
	gcov cardtest4.c -b >> unittestresult.out
	cat cardtest4.c.gcov >> unittestresult.out
	
	./cardtest3 >> unittestresult.out
	gcov cardtest3.c -b >> unittestresult.out
	cat cardtest3.c.gcov >> unittestresult.out
	
	./cardtest2 >> unittestresult.out
	gcov cardtest2.c -b >> unittestresult.out
	cat cardtest2.c.gcov >> unittestresult.out
	
	./cardtest1 >> unittestresult.out
	gcov cardtest1.c -b >> unittestresult.out
	cat cardtest1.c.gcov >> unittestresult.out
	
	./testHandCard >> unittestresult.out
	gcov unittest4.c -b >> unittestresult.out
	cat unittest4.c.gcov >> unittestresult.out

	./testWhoseTurn >> unittestresult.out
	gcov unittest3.c -b >> unittestresult.out
	cat unittest3.c.gcov >> unittestresult.out
	
	./testIsGameOver >> unittestresult.out
	gcov unittest2.c -b >> unittestresult.out
	cat unittest2.c.gcov >> unittestresult.out 
	
	./testGetCost >> unittestresult.out
	gcov unittest1.c -b >> unittestresult.out
	cat unittest1.c.gcov >> unittestresult.out
	
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
#END TEST OUTPUT RULE

#RULE TO MAKE ALL RANDOM TESTS AND OUTPUT TO INDIVIDUAL FILES 
runrandomtests: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c -b >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c -b >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
#END TEST OUTPUT RULE

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

cleantests:
	rm -f cardtest1.exe cardtest2.exe cardtest3.exe cardtest4.exe testGetCost.exe testIsGameOver.exe testWhoseTurn.exe testHandCard.exe randomtestcard1.exe randomtestcard2.exe randomtestadventurer.exe
	
clean: cleantests
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe badTestDrawCard.exe 
