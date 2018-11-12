CFLAGS= -Wall -fpic -coverage -lm -std=c99

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


### ASSIGNMENT 4 ###

testhelpers.o: testhelpers.c testhelpers.h
	gcc -c testhelpers.c $(CFLAGS) -g

randomtestcard1.o: randomtestcard1.c testhelpers.o dominion.o rngs.o
	gcc -c randomtestcard1.c testhelpers.c -g $(CFLAGS)

randomtestcard1: randomtestcard1.o dominion.o rngs.o testhelpers.o
	gcc -o randomtestcard1 $(CFLAGS) -g randomtestcard1.o dominion.o rngs.o testhelpers.o

randomtestcard1.out: randomtestcard1
	@echo "Executing randomtestcard1..."
	@./randomtestcard1 > randomtestcard1.out
	@gcov dominion.c >> randomtestcard1.out
	@cat dominion.c.gcov >> randomtestcard1.out
	@echo "Test results written to 'randomtestcard1.out'"

randomtestcard2.o: randomtestcard2.c testhelpers.o dominion.o rngs.o
	gcc -c randomtestcard2.c testhelpers.c -g $(CFLAGS)

randomtestcard2: randomtestcard2.o dominion.o rngs.o testhelpers.o
	gcc -o randomtestcard2 $(CFLAGS) -g randomtestcard2.o dominion.o rngs.o testhelpers.o

randomtestcard2.out: randomtestcard2
	@echo "Executing randomtestcard2..."
	@./randomtestcard2 > randomtestcard2.out
	@gcov dominion.c >> randomtestcard2.out
	@cat dominion.c.gcov >> randomtestcard2.out
	@echo "Test results written to 'randomtestcard2.out'"

randomtestcard3.o: randomtestcard3.c testhelpers.o dominion.o rngs.o
	gcc -c randomtestcard3.c testhelpers.c -g $(CFLAGS)

randomtestcard3: randomtestcard3.o dominion.o rngs.o testhelpers.o
	gcc -o randomtestcard3 $(CFLAGS) -g randomtestcard3.o dominion.o rngs.o testhelpers.o

randomtestcard3.out: randomtestcard3
	@echo "Executing randomtestcard3..."
	@./randomtestcard3 > randomtestcard3.out
	@gcov dominion.c >> randomtestcard3.out
	@cat dominion.c.gcov >> randomtestcard3.out
	@echo "Test results written to 'randomtestcard3.out'"

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe *.out
