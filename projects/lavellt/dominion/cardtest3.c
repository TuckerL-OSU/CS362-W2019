// Tucker Lavell
// card test 3: feast
#include "unittests.h"

//ct3: unittests.o dominion.o cardtest3.c
//	gcc - o ct3 cardtest3.c - g  unittests.o dominion.o rngs.o $(CFLAGS)



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

int feast_checkTrash() {

}

int feast_gainCard() {

}

int feast_cardCost() {

}