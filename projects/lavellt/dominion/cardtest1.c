// Tucker Lavell
// card test 1: adventurer
#include "unittests.h"

int adventurer_isDeckEmpty();

int main() {
	int passed = 0;
	int numTests = 1;

	passed += adventurer_isDeckEmpty();
	//passed += playCard_actionsTest();
	//passed += playCard_checkActionTest_adventurer();
	//passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d Adventurer Card Tests Passed.\n", passed, numTests);
}

int adventurer_isDeckEmpty() {
	struct gameState* actualGS = newGame();
	struct gameState* expectedGS = newGame();

	actualGS->whoseTurn = 0;
	printf("whoseTurn set\n");
	actualGS->deckCount[actualGS->whoseTurn] = 0;
	printf("deckCount set\n");
	//actualGS->discardCount = 3;
	int i;
	for (i = 0; i < 3; i++) {
		printf("adding copper to actual discard\n");
		actualGS->discard[actualGS->whoseTurn][i] = copper;
	}

	expectedGS->whoseTurn = 0;
	printf("whoseTurn set\n");
	expectedGS->deckCount[expectedGS->whoseTurn] = 3;
	printf("deckCount set\n");
	//expectedGS->discardCount = 0;
	for (i = 0; i < 3; i++) {
		printf("adding copper to expected deck\n");
		expectedGS->deck[expectedGS->whoseTurn][i] = copper;
	}

	printf("before cardEffect\n");
	cardEffect(adventurer, 0, 0, 0, actualGS, 0, 0);
	printf("after cardEffect\n");
	return assertObjectTrue(actualGS, expectedGS);
}

//int adventurer_isCopper() {
//
//}
//
//int adventurer_isSilver() {
//
//}
//
//int adventurer_isGold() {
//
//}
//
//int adventuer_isTreasure() {
//
//}
//
//int adventurer_notTreasure() {
//
//}
//
//int adventurer_noTreasure() {
//
//}
//
//int adventurer_discardCards() {
//
//}
//
//int adventurer_treasuresDrawn() {
//	int expected = 2;
//	int actual = 0; //
//
//}