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
		int card = gold;
		while (card == gold) {
			rand() % (27 + 1) - 1;
		}

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

		printf("2. Try to Buy Overpriced Card: ");
		// there are 3 cards in our set that are "overpriced" for feast
		if (!assertTrue(post.discard[currentPlayer][0], province) ||
			!assertTrue(post.discard[currentPlayer][0], gold) ||
			!assertTrue(post.discard[currentPlayer][0], adventurer)) {
			blockOverpricedCardFailed++;
			allCasesPassed = 0;
		}

		printf("3. Check if Feast was Moved to Supply Piles: ");
		// check supply piles for anything > 0, indicate feast/problem
		//for (i = 0; i < (treasure_map + 1); i++) {
		//	if (post.supplyCount[i] != 0) {
		//		assertTrue(post.supplyCount[i], feast);
		//		feastInSupplyNotTrashFailed++;
		//		allCasesPassed = 0;
		//	}
		//}
		for (i = 0; i < (treasure_map + 1); i++) {
			if (!assertTrue(post.supplyCount[i], 0)) {
				//assertTrue(post.supplyCount[i], feast);
				feastInSupplyNotTrashFailed++;
				allCasesPassed = 0;
			}
		}

		printf("4. Check if Feast was Moved to Hand: ");
		// check if there is a feast in the hand
		for (i = 0; i < post.handCount[currentPlayer]; i++) {
			if (!assertTrue(post.hand[currentPlayer][i], feast)) {
				//assertTrue(post.hand[currentPlayer][i], feast);
				feastInHandNotTrashFailed++;
				allCasesPassed = 0;
			}
		}

		printf("5. Check if Feast was Moved to Discard: ");
		// check discard for feast
		for (i = 0; i < post.discardCount[currentPlayer]; i++) {
			//if (gS->discard[gS->whoseTurn][i] == feast) {
			if (!assertTrue(post.discard[currentPlayer][i], feast)) {
				feastInDiscardNotTrashFailed++;
				allCasesPassed = 0;
			}
		}

		printf("6. Check if Feast was Moved to Deck: ");
		// check deck for feast
		for (i = 0; i < post.deckCount[currentPlayer]; i++) {
			//if (gS->deck[gS->whoseTurn][i] == feast) {
			if (!assertTrue(post.deck[currentPlayer][i], feast)) {
				feastInDeckNotTrashFailed++;
				allCasesPassed = 0;
			}
		}

		printf("7. Check if Feast was Moved to Played Cards: ");
		// check played cards for feast
		for (i = 0; i < post.playedCardCount; i++) {
			//if (post.playedCards[i] == feast) {
			if (!assertTrue(post.playedCards[i], feast)) {
				feastInPlayedCardsNotTrashFailed++;
				allCasesPassed = 0;
			}
		}
		
		if (allCasesPassed == 1) {
			totalTestsPassed++;
		}

		//if (feastInSupplyNotTrashFailed != 0 ||
		//	feastInHandNotTrashFailed != 0 ||
		//	feastInDiscardNotTrashFailed != 0 ||
		//	feastInDeckNotTrashFailed != 0 ||
		//	feastInPlayedCardsNotTrashFailed != 0) {
		//	feastTrashedFailed++;
		//}

		/*if (!assertTrue(feastTrashedFailed,))*/

		
		//int opCard = rand() % (3 + 1);
		//switch (card) {
		//case 1:
		//	cardEffect(feast, province, 0, 0, &post, handPos, 0);
		//	break;
		//case 2:
		//	cardEffect(feast, gold, 0, 0, &post, handPos, 0);
		//	break;
		//case 3:
		//	cardEffect(feast, adventurer, 0, 0, &post, handPos, 0);
		//	break;
		//}



		// adv, province, gold 
	}

	printf("\nFeast Summary\n");
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);
	printf("1. Chosen Card Picked Up Failed: %d\n", chosenCardPickUpFailed);
	printf("2. Block Buying Overpriced Card Failed: %d\n", blockOverpricedCardFailed);
	printf("3. Feast is in Supply Piles NOT Trash Failed: %d\n", feastInSupplyNotTrashFailed);
	printf("4. Feast is in Hand NOT Trash Failed: %d\n", feastInHandNotTrashFailed);
	printf("5. Feast is in Discard NOT Trash Failed: %d\n", feastInDiscardNotTrashFailed);
	printf("6. Feast is in Deck NOT Trash Failed: %d\n", feastInDeckNotTrashFailed);
	printf("7. Feast is in Played Cards NOT Trash Failed: %d\n", feastInPlayedCardsNotTrashFailed);

	return 0;
}