// Tucker Lavell
// unit test 1: playCard
#include "unittests.h"

int playCard_phaseTest();
int playCard_actionsTest();
int playCard_checkActionTest_adventurer();
int playCard_checkActionTest_treasure_map();
int playCard_cardEffectTest();
int playCard_reduceActions();
int playCard_successfulPlay();
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

	printf("1. Currently Play Card Phase: ");
	return assertTrue(actual, expected);

	//free gS;
}

int playCard_actionsTest() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 0;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);

	printf("2. Check Player has Actions: ");
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

	printf("3. Check Card played was Adventurer Action: ");
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

	printf("4. Check Card played was Treasure Map Action: ");
	return assertTrue(actual, expected);

	//free gS;
}

// doesn't really prove much, still triggers same place as treasure_map
int playCard_cardEffectTest() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = 27; // beyond the current set of cards

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);

	printf("5. Check cardEffect(): ");
	return assertTrue(actual, expected);

	//free gS;
}

int playCard_reduceActions() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = baron; // random valid card that doesnt mess with the case

	int expected = 0;

	playCard(0, 0, 0, 0, gS);

	int actual = gS->numActions;

	printf("6. Check Number of Actions Reduced: ");
	return assertTrue(actual, expected);

	//free gS;
}

int playCard_successfulPlay() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gS->numActions = 1;
	gS->whoseTurn = 0;
	// setting first card of P1s hand to any card higher in the enum than TM
	gS->hand[0][0] = baron; // random valid card that doesnt mess with the case

	int expected = 0;
	int actual = playCard(0, 0, 0, 0, gS);

	printf("7. Check Successful Play: ");
	return assertTrue(actual, expected);

	//free gS;
}
