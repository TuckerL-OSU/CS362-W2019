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

unittests.o: unittests.h unittests.c dominion.o rngs.o
	gcc -c unittests.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

ut1: unittests.o dominion.o unittest1.c
	gcc -o ut1 unittest1.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ut2: unittests.o dominion.o unittest2.c
	gcc -o ut2 unittest2.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ut3: unittests.o dominion.o unittest3.c
	gcc -o ut3 unittest3.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ut4: unittests.o dominion.o unittest4.c
	gcc -o ut4 unittest4.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ct1: unittests.o dominion.o cardtest1.c
	gcc -o ct1 cardtest1.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ct2: unittests.o dominion.o cardtest2.c
	gcc -o ct2 cardtest2.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ct3: unittests.o dominion.o cardtest3.c
	gcc -o ct3 cardtest3.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

ct4: unittests.o dominion.o cardtest4.c
	gcc -o ct4 cardtest4.c -g  unittests.o dominion.o rngs.o $(CFLAGS)

unittestresults: 
	./ut1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ut2 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ut3 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ut4 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ct1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ct2 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ct3 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	./ct4 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
