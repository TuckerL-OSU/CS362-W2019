// Tucker Lavell
// unit test 1: playCard
#include "unittests.h"

int playCard_phaseTest();
int playCard_actionsTest();
int playCard_checkActionTest_adventurer();
int playCard_checkActionTest_treasure_map();
int playCard_cardEffectTest();
//#define SUCCESS "TEST  SUCCESSFULLY COMPLETED"
//#define FAILURE "TEST FAILED"


int main() {
	int passed = 0;
	int numTests = 7;

	passed += playCard_phaseTest();
	passed += playCard_actionsTest();
	passed += playCard_checkActionTest_adventurer();
	passed += playCard_checkActionTest_treasure_map();
	passed += playCard_cardEffectTest();
	passed += playCard_reduceActions();
	passed += playCard_successfulPlay();

	printf("%d/%d playCard Tests Passed.\n", passed, numTests);
}

int playCard_phaseTest() {
	struct gameState* gS = newGame();

	gS->phase = 4;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	return assertTrue(actual, expected);

	//free gS;
}

int playCard_actionsTest() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 0;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	return assertTrue(actual, expected);

	//free gS;
}

int playCard_checkActionTest_adventurer() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card lower in the enum than adv
	gS->hand[0][0] = curse; // 0

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	return assertTrue(actual, expected);

	//free gS;
}

int playCard_checkActionTest_treasure_map() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = 27; // beyond the current set of cards

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);

	return assertTrue(actual, expected);

	//free gS;
}

// incompelete
int playCard_cardEffectTest() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = 27; // beyond the current set of cards

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);

	return assertTrue(actual, expected);

	//free gS;
}

int playCard_reduceActions() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = (adventurer + treasure_map) / 2; // middle of the cards

	int expected = 0;

	playCard(0, 0, 0, 0, gS);

	int actual = gS->numActions;

	return assertTrue(actual, expected);

	//free gS;
}

int playCard_successfulPlay() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = (adventurer + treasure_map) / 2; // beyond the current set of cards

	int expected = 0;
	int actual = playCard(0, 0, 0, 0, gS);

	return assertTrue(actual, expected);

	//free gS;
}
