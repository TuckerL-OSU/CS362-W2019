// Tucker Lavell
// card test 2: smithy
#include "unittests.h"

//ct2: unittests.o dominion.o cardtest2.c
//	gcc - o ct2 cardtest2.c - g  unittests.o dominion.o rngs.o $(CFLAGS)

int smithy_drawCards();
int smithy_discardCard();

int main() {
	int passed = 0;
	int numTests = 2;

	passed += smithy_drawCards();
	passed += smithy_discardCard();

	printf("%d/%d Smithy Card Tests Passed.\n", passed, numTests);
}

int smithy_drawCards() {
	struct gameState* actualGS = newGame();
	struct gameState* expectedGS = newGame();
	

}

int smithy_discardCard() {

}