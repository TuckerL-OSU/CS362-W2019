// Tucker Lavell
// card test 4: treasure_map
#include "unittests.h"

int treasure_map_checkNumCardsPlayed();
int treasure_map_checkHand_worksOriginal();
int treasure_map_checkHand_provesOriginalBug();
int treasure_map_checkDeckCount();
int treasure_map_checkCardsGained();
int treasure_map_not2TM();

int main() {
	int passed = 0;
	int numTests = 6;

	passed += treasure_map_checkNumCardsPlayed();
	passed += treasure_map_checkHand_worksOriginal();
	passed += treasure_map_checkHand_provesOriginalBug();
	passed += treasure_map_checkDeckCount();
	passed += treasure_map_checkCardsGained();
	passed += treasure_map_not2TM();

	printf("%d/%d Treasure Map Card Tests Passed.\n", passed, numTests);
}

// check to see how many cards were played this round
// can't check which cards are trashed, but we can set the 
// playedCardCount = 0, and if it stays at 0 when playing,
// treasure_map, then we can assume treasure map was played and trashed
int treasure_map_checkNumCardsPlayed() {
	struct gameState* gS = newGame();

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

	printf("1. Check if Treasure Map was Played: ");
	return assertTrue(actual, expected);
}

// check hand to make sure treasure maps were discarded
// testing found a bug in the original code for TM,
// so when I was testing use cases, I first tested to make sure
// the card worked before I tested, my bug.
// with my bug, this does not work, which is expected
int treasure_map_checkHand_worksOriginal() {
	struct gameState* gS = newGame();

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

	printf("2. Check Arrangement 1 for discarded Treasure Maps: ");
	return assertTrue(actual, expected);
}

// still want to see what happens with the bug I introduced,
// on top of the existing bug
// this only works because of the bug I added, on top of the existing bug
int treasure_map_checkHand_provesOriginalBug() {
	struct gameState* gS = newGame();

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

	printf("3. Check Arrangement 2 for discarded Treasure Maps: ");
	return assertTrue(actual, expected);
}

// check how many cards are in the deck if we know it started with 1
int treasure_map_checkDeckCount() {
	struct gameState* gS = newGame();

	int expected = 5;
	int actual = 0;

	gS->whoseTurn = 0;

	gS->supplyCount[gold] = 4;

	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = treasure_map;

	gS->deckCount[gS->whoseTurn] = 1;
	gS->deck[gS->whoseTurn][0] = baron;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	// checking it is still P1
	if (gS->whoseTurn == 0) {
		actual = gS->deckCount[gS->whoseTurn];
	}

	printf("4. Check Deck Count: ");
	return assertTrue(actual, expected);
}

// check which cards were added to the top of the deck. need to be gold
int treasure_map_checkCardsGained() {
	struct gameState* gS = newGame();

	int expected = 4;
	int actual = 0;

	gS->whoseTurn = 0;

	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = treasure_map;

	gS->deckCount[gS->whoseTurn] = 1;
	gS->deck[gS->whoseTurn][0] = baron;

	gS->supplyCount[gold] = 4;

	cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	// checking it is still P1, and checking to make sure deck is right size
	if (gS->whoseTurn == 0 && gS->deckCount[gS->whoseTurn] == 5) {
		int i;
		// will check top 4 cards of deck to see if they are gold.
		// if they are gold and the deck size is 5, it is safe to assume,
		// baron was left in its correct position
		for (i = gS->deckCount[gS->whoseTurn]; i > 0; i--) {
			//printf("%d: %d\n", i, gS->deck[gS->whoseTurn][i]);
			if (gS->deck[gS->whoseTurn][i] == gold) {
				actual++;
			}
		}
	}

	//if (gS->whoseTurn == 0) {
	//	if (gS->deckCount[gS->whoseTurn] == 5) {
	//		int i;
	//		// will check top 4 cards of deck to see if they are gold.
	//		// if they are gold and the deck size is 5, it is safe to assume,
	//		// baron was moved down in the deck correctly
	//		for (i = 0; i < 4; i++) {
	//			if (gS->deck[gS->whoseTurn][i] == gold) {
	//				actual++;
	//			}
	//		}
	//	}
	//}

	printf("5. Check if 4 Gold are on Top of deck: ");
	return assertTrue(actual, expected);
}

// check to see if there were not 2 treasure maps to play
int treasure_map_not2TM() {
	struct gameState* gS = newGame();

	int expected = -1;
	int actual = 0;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 4;
	gS->hand[gS->whoseTurn][0] = treasure_map;
	gS->hand[gS->whoseTurn][1] = copper;
	gS->hand[gS->whoseTurn][2] = copper;
	gS->hand[gS->whoseTurn][3] = silver;
	gS->playedCardCount = 0;
	gS->supplyCount[gold] = 4;

	actual = cardEffect(treasure_map, 0, 0, 0, gS, 0, 0);

	printf("6. Check if Play Treasure Map works w/o 2: ");
	return assertTrue(actual, expected);
}