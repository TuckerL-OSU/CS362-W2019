// Tucker Lavell
// card test 4: tribute
#include "unittests.h"

//ct4: unittests.o dominion.o cardtest4.c
//	gcc - o ct4 cardtest4.c - g  unittests.o dominion.o rngs.o $(CFLAGS)



int main() {
	int passed = 0;
	int numTests = 5;

	passed += playCard_phaseTest();
	passed += playCard_actionsTest();
	passed += playCard_checkActionTest_adventurer();
	passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d Adventurer Card Tests Passed.\n", passed, numTests);
}

int adventurer_() {

}