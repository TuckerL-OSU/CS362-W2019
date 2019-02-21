// Tucker Lavell
// random test: Smithy
#include "unittests.h"

int main() {
	srand(time(NULL));
	// game vars
	struct gameState* pre = newGame();
	int seed = 100000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize = 0;
	int handSize = 0;

	// test vars
	int totalTestsPassed = 0;
	//int numCases = 3;
	int chosenCardPickUpFailed = 0;
	int blockOverpricedCardFailed = 0;
	int feastInSupplyNotTrashFailed = 0;
	int feastInHandNotTrashFailed = 0;
	int feastInDiscardNotTrashFailed = 0;
	int feastInDeckNotTrashFailed = 0;
	int feastInPlayedCardsNotTrashFailed = 0;
	//int trashFeastFailed = 0;

	int i;
	for (i = 0; i < MAX_TESTS; i++) {
		printf("Test #%d\n", i + 1);
		// set up a game
		initializeGame(numPlayers, k, seed, pre);
		// set a players turn, which player doesn't matter
		pre->whoseTurn = currentPlayer;
		deckSize = rand() % (MAX_DECK + 1);
		// just to prevent the hand from being bigger than the deck
		handSize = rand() % (deckSize + 1);

		// number of cards left in deck is total - number in hand
		pre->deckCount[currentPlayer] = deckSize - handSize;
		pre->handCount[currentPlayer] = handSize;
		pre->discardCount[currentPlayer] = 0;

		// choose a card from 0-26 (matches enum)
		//int chosenCard = rand() % (27 + 1) - 1;
		//int card = -1;
		//while (1) {
		//	card = rand() % (27 + 1) - 1;
		//	if (card != gold) {
		//		break;
		//	}
		//}
		int card = duchy;

		// set supply counts to 0 for testing later
		int j;
		for (j = 0; j < (treasure_map + 1); j++) {
			// if it is the chosen card give it 1 for the sake of run
			if (j == card) {
				pre->supplyCount[j] = 1;
			}
			else {
				pre->supplyCount[j] = 0;
			}
		}

		// position of feast
		int handPos = 0;

		// create the object to modify (copy of pre), saves pre for comparison later
		struct gameState post;
		memcpy(&post, pre, sizeof(struct gameState));

		cardEffect(feast, card, 0, 0, &post, handPos, 0);

		// *** Test Cases *** 
		// used for true/false flagging in if structure
		int allCasesPassed = 1;

		printf("1. Check that Chosen Card was Picked Up: ");
		if (!assertTrue(post.discard[currentPlayer][0], card)) {
			chosenCardPickUpFailed++;
			allCasesPassed = 0;
		}

		// only testing province 
		printf("2. Try to Buy Overpriced Card: ");
		// there are 3 cards in our set that are "overpriced" for feast
		switch (post.discard[currentPlayer][0]) {
		case province:
			assertTrue(post.discard[currentPlayer][0], province;
			blockOverpricedCardFailed++;
			allCasesPassed = 0;
			break;
		case gold:
			assertTrue(post.discard[currentPlayer][0], gold);
			blockOverpricedCardFailed++;
			allCasesPassed = 0;
			break;
		case adventurer:
			assertTrue(post.discard[currentPlayer][0], adventurer)
			blockOverpricedCardFailed++;
			allCasesPassed = 0;
			break;
		default:
			break;
		}
		//if (assertTrue(post.discard[currentPlayer][0], province) ||
		//	assertTrue(post.discard[currentPlayer][0], gold) ||
		//	assertTrue(post.discard[currentPlayer][0], adventurer)) {
		//	blockOverpricedCardFailed++;
		//	allCasesPassed = 0;
		//}

		// flag to see if any of the trash tests fail
		int trashCheck = 1;
		printf("3. Check if Feast was Moved to Supply Piles: ");
		int x;
		// check supply piles for anything > 0, indicate feast/problem
		for (x = 0; x < (treasure_map + 1); x++) {
			if (post.supplyCount[x] != 0) {
				trashCheck = 0;
			}

			if (trashCheck == 0) {
				if (!assertTrue(post.supplyCount[x], 0)) {
					feastInSupplyNotTrashFailed++;
					allCasesPassed = 0;
				}
			}

		}
		//for (x = 0; x < (treasure_map + 1); x++) {
		//	if (!assertTrue(post.supplyCount[x], 0)) {
		//		//assertTrue(post.supplyCount[x], feast);
		//		feastInSupplyNotTrashFailed++;
		//		allCasesPassed = 0;
		//	}
		//}

		printf("4. Check if Feast was Moved to Hand: ");
		// check if there is a feast in the hand
		for (x = 0; x < post.handCount[currentPlayer]; x++) {
			if (post.hand[currentPlayer][x] == feast) {
				if (!assertTrue(post.hand[currentPlayer][x], feast)) {
					//trashCheck = 0;
					feastInHandNotTrashFailed++;
					allCasesPassed = 0;
				}
			}
		}

		printf("5. Check if Feast was Moved to Discard: ");
		// check discard for feast
		for (x = 0; x < post.discardCount[currentPlayer]; x++) {
			if (post.discard[currentPlayer][x] == feast) {
				if (!assertTrue(post.discard[currentPlayer][x], feast)) {
					//trashCheck = 0;
					feastInDiscardNotTrashFailed++;
					allCasesPassed = 0;
				}
			}
		}

		printf("6. Check if Feast was Moved to Deck: ");
		// check deck for feast
		for (x = 0; x < post.deckCount[currentPlayer]; x++) {
			if (post.deck[currentPlayer][x] == feast) {
				if (!assertTrue(post.deck[currentPlayer][x], feast)) {
					//trashCheck = 0;
					feastInDeckNotTrashFailed++;
					allCasesPassed = 0;
				}
			}
		}

		printf("7. check if feast was moved to played cards: ");
		// check played cards for feast
		for (x = 0; x < post.playedCardCount; x++) {
			if (post.playedCards[x] == feast) {
				if (!assertTrue(post.playedCards[x], feast)) {
					//trashCheck = 0;
					feastInPlayedCardsNotTrashFailed++;
					allCasesPassed = 0;
				}
			}
		}

		//if (!assertTrue(trashCheck, 0)) {
		//	trashFeastFailed++;
		//}
		
		if (allCasesPassed == 1) {
			totalTestsPassed++;
		}
	}

	printf("\nFeast Summary\n");
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);
	printf("1. Chosen Card Picked Up Failed: %d\n", chosenCardPickUpFailed);
	printf("2. Block Buying Overpriced Card Failed: %d\n", blockOverpricedCardFailed);
	//printf("3. Feast was Trashed Failed: %d\n", trashFeastFailed);
	printf("3. Feast is in Supply Piles NOT Trash Failed: %d\n", feastInSupplyNotTrashFailed);
	printf("4. Feast is in Hand NOT Trash Failed: %d\n", feastInHandNotTrashFailed);
	printf("5. Feast is in Discard NOT Trash Failed: %d\n", feastInDiscardNotTrashFailed);
	printf("6. Feast is in Deck NOT Trash Failed: %d\n", feastInDeckNotTrashFailed);
	printf("7. Feast is in Played Cards NOT Trash Failed: %d\n", feastInPlayedCardsNotTrashFailed);

	return 0;
}