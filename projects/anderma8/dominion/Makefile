CFLAGS= -Wall -fpic -coverage -lm -std=c99
REPORT=unittestresults.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
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

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1.o: dominion.o rngs.o
	gcc -c unittest1.c -g $(CFLAGS)


unittest2.o: dominion.o rngs.o
	gcc -c unittest2.c -g $(CFLAGS)


unittest3.o: dominion.o rngs.o
	gcc -c unittest3.c -g $(CFLAGS)


unittest4.o: dominion.o rngs.o
	gcc -c unittest4.c -g $(CFLAGS)


cardtest1.o: cardtest1.c dominion.o rngs.o
	gcc -c cardtest1.c -g $(CFLAGS)


unittest1: unittest1.o dominion.o rngs.o
	gcc -o unittest1 $(CFLAGS) -g unittest1.o dominion.o rngs.o

unittest2: unittest2.o dominion.o rngs.o
	gcc -o unittest2 $(CFLAGS) -g unittest2.o dominion.o rngs.o

unittest3: unittest3.o dominion.o rngs.o
	gcc -o unittest3 $(CFLAGS) -g unittest3.o dominion.o rngs.o

unittest4: unittest4.o dominion.o rngs.o
	gcc -o unittest4 $(CFLAGS) -g unittest4.o dominion.o rngs.o

cardtest1: cardtest1.o dominion.o rngs.o
	gcc -o cardtest1 $(CFLAGS) -g cardtest1.o dominion.o rngs.o



unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1
	@echo "Running Dominion Unittests" > $(REPORT)
	@echo "***************" >> $(REPORT)

	@./unittest1 >> $(REPORT)

	@./unittest2 >> $(REPORT)
	@./unittest3 >> $(REPORT)

	@./unittest4 >> $(REPORT)

	@./cardtest1 >> $(REPORT)


	@gcov dominion.c >> $(REPORT)


	@echo "Completed Dominion unit tests."



all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardeffect1

