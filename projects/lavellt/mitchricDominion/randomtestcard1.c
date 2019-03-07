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
	int cardsInDeckFailed = 0;
	int cardsInHandFailed = 0;
	int discardSmithyFailed = 0;

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
		pre->playedCardCount = 0;

		// position of smithy
		int handPos = 0;

		// create the object to modify (copy of pre), saves pre for comparison later
		struct gameState post;
		memcpy(&post, pre, sizeof(struct gameState));

		cardEffect(smithy, 0, 0, 0, &post, handPos, 0);

		// *** Test Cases *** 
		// used for true/false flagging in if structure
		int allCasesPassed = 1;

		printf("1. Check Number of Cards in Deck: ");
		if (!assertTrue(post.deckCount[currentPlayer], pre->deckCount[currentPlayer] - 3)) {
			cardsInDeckFailed++;
			allCasesPassed = 0;
		}

		printf("2. Check Number of Cards in Hand: ");
		if (!assertTrue(post.handCount[currentPlayer], pre->handCount[currentPlayer] + 2)) {
			cardsInHandFailed++;
			allCasesPassed = 0;
		}

		// ?????????????????????????????????????????????????????????????????????
		printf("3. Check if Smithy was Played: ");
		//if (!assertTrue(post.discard[currentPlayer][0], smithy)) {
		if (!assertTrue(post.playedCards[0], smithy)) {
			discardSmithyFailed++;
			allCasesPassed = 0;
		}

		// TODO: 4. Check if Smithy was removed from Hand

		if (allCasesPassed == 1) {		
			totalTestsPassed++;
		}
	}

	printf("\nSmithy Summary\n");
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);
	printf("1. Number of Cards in Deck Failed: %d\n", cardsInDeckFailed);
	printf("2. Number of cards in Hand Failed: %d\n", cardsInHandFailed);
	printf("3. Smithy Played Tests Failed: %d\n", discardSmithyFailed);
	
	return 0;
}