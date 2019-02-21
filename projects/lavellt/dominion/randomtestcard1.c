// Tucker Lavell
// random test: Smithy
#include "unittests.h"

#define MAX_TESTS 1000
//#define MAX_TESTS 1000000

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
	//int deckBefore;
	//int deckAfter;
	//int handBefore;
	//int handAfter;
	//int discardBefore;
	//int discardAfter;

	// test vars
	int totalTestsPassed = 0;
	int numCases = 3;
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
		pre->deckCount[0] = deckSize - handSize;
		pre->handCount[0] = handSize;

		// position of smithy
		int handPos = 0;

		////personal checks
		//deckBefore = G.deckCount[0];
		////printf("deck before %d\n", deckBefore);
		//handBefore = G.handCount[0];
		////printf("Hand before %d\n",handBefore);
		//discardBefore = G.playedCardCount;
		////printf("Discard before %d\n", discardBefore);

		// create the object to modify (copy of pre), saves pre for comparison later
		struct gameState post;
		memcpy(&post, pre, sizeof(struct gameState));

		cardEffect(smithy, 0, 0, 0, &pre, handPos, 0);

		// *** Test Cases *** 
		// setting these vars here because I want them to reset for each loop
		int casesPassed = 0;
		// used for true/false flagging in if structure
		//int allCasesPassed = 1;

		printf("1. Check Number of Cards in Deck: ");
		if (!assertTrue(post.deckCount[currentPlayer], pre->deckCount[currentPlayer] - 3)) {
			cardsInDeckFailed++;
		}
		else {
			casesPassed++;
		}

		printf("2. Check Number of Cards in Hand: ");
		if (!assertTrue(post.handCount[currentPlayer], pre->handCount[currentPlayer] + 2)) {
			cardsInHandFailed++;
		}
		else {
			casesPassed++;
		}

		printf("3. Check Discard for Smithy: ");
		if (!assertTrue(post.playedCards[0], smithy)) {
			discardSmithyFailed++;
		}
		else {
			casesPassed++;
		}
	}

	printf("\n\n");
	printf("1. Number of Cards in Deck Failed: %d\n", cardsInDeckFailed);
	printf("2. Number of cards in Hand Failed: %d\n", cardsInHandFailed);
	printf("3. Smithy Discarded Tests Failed: %d\n", discardSmithyFailed);
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);

	return 0;
}