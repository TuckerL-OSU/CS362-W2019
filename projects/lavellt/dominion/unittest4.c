// Tucker Lavell
// unit test 4: whoseTurn
// sorry this one is kind of a cop out, I was just exhausted after the other 3
#include "unittests.h"

int whoseTurn_RealPlayer();
int whoseTurn_nonExistPlayer();

int main() {
	int passed = 0;
	int numTests = 2;

	passed += whoseTurn_RealPlayer();
	passed += whoseTurn_nonExistPlayer();

	printf("%d/%d whoseTurn Tests Passed.\n", passed, numTests);
}

int whoseTurn_RealPlayer() {
	struct gameState* gS = newGame();

	int expected = 2;
	gS->whoseTurn = expected;

	int actual = whoseTurn(gS);

	printf("1. Check Player is Correct: ");
	return assertTrue(actual, expected);

	//free gS;
}

// just to make sure it doesn't kill the program, 
// but it would definately mess up other things if a player number got negative
int whoseTurn_nonExistPlayer() {
	struct gameState* gS = newGame();

	int expected = -1;
	gS->whoseTurn = expected;

	int actual = whoseTurn(gS);

	printf("2. Check Non-existent player no weird behavior: ");
	return assertTrue(actual, expected);

	//free gS;
}
