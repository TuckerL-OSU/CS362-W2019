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

all: playdom player 

unittests.o: unittests.h unittests.c dominion.o rngs.o
	gcc -c unittests.c -g  $(CFLAGS)

ut1: unittests.o dominion.o unittest1.c
	gcc -o ut1 unittest1.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ut2: unittests.o dominion.o unittest2.c
	gcc -o ut2 unittest2.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ut3: unittests.o dominion.o unittest3.c
	gcc -o ut3 unittest3.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ut4: unittests.o dominion.o unittest4.c
	gcc -o ut4 unittest4.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ct1: unittests.o dominion.o cardtest1.c
	gcc -o ct1 cardtest1.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ct2: unittests.o dominion.o cardtest2.c
	gcc -o ct2 cardtest2.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ct3: unittests.o dominion.o cardtest3.c
	gcc -o ct3 cardtest3.c -g unittests.o dominion.o rngs.o $(CFLAGS)

ct4: unittests.o dominion.o cardtest4.c
	gcc -o ct4 cardtest4.c -g unittests.o dominion.o rngs.o $(CFLAGS)

unittestresults: 

	echo "Results for Assignment 3: Tucker Lavell" > unittestresults.out
	make rngs.o
	make dominion.o
	make unittests.o

	echo "===========" >> unittestresults.out
	echo "unittest1.c: playCard()" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ut1
	./ut1 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out
	echo "unittest2.c: isGameOver()" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ut2
	./ut2 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out	
	echo "unittest3.c: updateCoins()" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ut3
	./ut3 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out	
	echo "unittest4.c: whoseTurn()" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ut4
	./ut4 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out

	echo "===========" >> unittestresults.out	
	echo "cardtest1.c: Adventurer" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ct1
	./ct1 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out	
	echo "cardtest2.c: Smithy" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ct2
	./ct2 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out
	echo "cardtest3.c: Feast" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ct3
	./ct3 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out
	
	echo "===========" >> unittestresults.out
	echo "cardtest4.c: Treasure Map" >> unittestresults.out
	echo "===========" >> unittestresults.out
	make ct4
	./ct4 >> unittestresults.out
	gcov -abcr dominion.c >> unittestresults.out

randtestadv: unittests.o dominion.o randomtestadventurer.c
	gcc -o randtestadv randomtestadventurer.c -g unittests.o dominion.o rngs.o $(CFLAGS)

randtest1: unittests.o dominion.o randomtestcard1.c
	gcc -o randtest1 randomtestcard1.c -g unittests.o dominion.o rngs.o $(CFLAGS)

randtest2: unittests.o dominion.o randomtestcard2.c
	gcc -o randtest2 randomtestcard2.c -g unittests.o dominion.o rngs.o $(CFLAGS)

randomtestresults: 

	make rngs.o
	make dominion.o
	make unittests.o

	echo "===========" &> randomtestcard1.out
	echo "randomtestcard1.c: Smithy" >> randomtestcard1.out
	echo "===========" >> randomtestcard1.out
	make randtest1
	./randtest1
	gcov -b -f dominion.c >> randomtestcard1.out
	
	
	echo "===========" &> randomtestcard2.out
	echo "randomtestcard2.c: Feast" >> randomtestcard2.out
	echo "===========" >> randomtestcard2.out
	rm -f *.gcov *.gcda *.gcno
	make randtest2
	./randtest2
	gcov -b -f dominion.c >> randomtestcard2.out
	rm -f *.gcov *.gcda *.gcno
	
	echo "===========" &> randomtestadventurer.out	
	echo "randomtestadventurer.c: Adventurer" >> randomtestadventurer.out
	echo "===========" >> randomtestadventurer.out
	rm -f *.gcov *.gcda *.gcno
	make randtestadv
	./randtestadv
	gcov -b -f dominion.c >> randomtestadventurer.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe ut1 ut2 ut3 ut4 ct1 ct2 ct3 ct4
