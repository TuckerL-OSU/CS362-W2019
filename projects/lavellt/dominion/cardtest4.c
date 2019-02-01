// Tucker Lavell
// card test 4: treasure_map
#include "unittests.h"

int treasure_map_checkNumCardsPlayed();
int treasure_map_checkHand_worksOriginal();
int treasure_map_checkHand_provesOriginalBug();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += treasure_map_checkNumCardsPlayed();
	passed += treasure_map_checkHand_worksOriginal();
	passed += treasure_map_checkHand_provesOriginalBug();
	//passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d Treasure Map Card Tests Passed.\n", passed, numTests);
}

int treasure_map_checkNumCardsPlayed() {
	struct gameState* gS = newGame();

	// can't check which cards are trashed, but we can set the 
	// playedCardCount = 0, and if it stays at 0 when playing,
	// treasure_map, then we can assume the treasure maps were discarded
	int expected = 0;
	int actual = -1;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = treasure_map;
	gS->playedCardCount = 0;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->playedCardCount;
	}

	return assertTrue(actual, expected);
}

int treasure_map_checkHand_worksOriginal() {
	struct gameState* gS = newGame();

	// can't check which cards are trashed, but we can set the 
	// playedCardCount = 0, and if it stays at 0 when playing,
	// treasure_map, then we can assume the treasure maps were discarded
	int expected = 0;
	int actual = 0;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = treasure_map;
	gS->hand[gS->whoseTurn][3] = copper;
	gS->playedCardCount = 0;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		int i;
		for (i = 0; i < gS->handCount[gS->whoseTurn]; i++) {
			if (gS->hand[gS->whoseTurn][i] == treasure_map) {
				actual++;
			}
		}
	}

	return assertTrue(actual, expected);
}

// still want to see what happens with the bug
// I introduced on top of the existing bug
int treasure_map_checkHand_provesOriginalBug() {
	struct gameState* gS = newGame();

	// can't check which cards are trashed, but we can set the 
	// playedCardCount = 0, and if it stays at 0 when playing,
	// treasure_map, then we can assume the treasure maps were discarded
	int expected = 0;
	int actual = 0;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = treasure_map;
	gS->playedCardCount = 0;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		int i;
		for (i = 0; i < gS->handCount[gS->whoseTurn]; i++) {
			if (gS->hand[gS->whoseTurn][i] == treasure_map) {
				actual++;
			}
		}
	}

	return assertTrue(actual, expected);
}


//int treasure_map_checkDeckCount() {
//
//}
//
//int treasure_map_checkCardsGained() {
//
//}
//
//int treasure_map_not2TM() {
//
//}