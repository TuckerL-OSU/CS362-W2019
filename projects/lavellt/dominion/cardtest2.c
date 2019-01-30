// Tucker Lavell
// card test 2: smithy
#include "unittests.h"

//ct2: unittests.o dominion.o cardtest2.c
//	gcc - o ct2 cardtest2.c - g  unittests.o dominion.o rngs.o $(CFLAGS)



int main() {
	int passed = 0;
	int numTests = 5;

	passed += playCard_phaseTest();
	passed += playCard_actionsTest();
	passed += playCard_checkActionTest_adventurer();
	passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d Smithy Card Tests Passed.\n", passed, numTests);
}

int smithy_drawCards() {

}

int smithy_discardCard() {

}