// Tucker Lavell
// card test 4: treasure_map
#include "unittests.h"

int treasure_map_checkTrashCount();


int main() {
	int passed = 0;
	int numTests = 1;

	passed += treasure_map_checkTrashCount();
	//passed += playCard_actionsTest();
	//passed += playCard_checkActionTest_adventurer();
	//passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d Treasure Map Card Tests Passed.\n", passed, numTests);
}

int treasure_map_checkTrashCount() {
	struct gameState* gS = newGame();

	int expected = 2;
	int actual = 0;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = treasure_map;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0 && gS->playedCardCount != expected) {
		actual = gS->playedCardCount;
	}

	return assertTrue(actual, expected);
}

//int treasure_map_checkTrash() {
//
//}
//
//int treasure_map_checkDeckCount() {
//
//}
//
//int treasure_map_checkCardsGained() {
//
//}