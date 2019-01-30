// Tucker Lavell
// card test 1: adventurer
#include "unittests.h"

//ct1: unittests.o dominion.o cardtest1.c
//	gcc - o ct1 cardtest1.c - g  unittests.o dominion.o rngs.o $(CFLAGS)




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

int adventurer_isDeckEmpty() {

}

int adventurer_isCopper() {

}

int adventurer_isSilver() {

}

int adventurer_isGold() {

}

int adventuer_isTreasure() {

}

int adventurer_notTreasure() {

}

int adventurer_noTreasure() {

}

int adventurer_discardCards() {

}

int adventurer_treasuresDrawn() {
	int expected = 2;
	int actual = 0; //

}