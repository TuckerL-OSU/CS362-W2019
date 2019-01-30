// Tucker Lavell
// unit tests 1: playCard
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int phaseTest();
int playCard_actionsTest();
int playCard_checkActionTest_adventurer();
int playCard_checkActionTest_treasure_map();
int playCard_cardEffectTest();
//#define SUCCESS "TEST  SUCCESSFULLY COMPLETED"
//#define FAILURE "TEST FAILED"


int main() {
	int passed = 0;
	int numTests = 5;

	passed += playCard_phaseTest();
	passed += playCard_actionsTest();
	passed += playCard_checkActionTest_adventurer();
	passed += playCard_checkActionTest_treasure_map();
	//passed += playCard_cardEffectTest();

	printf("%d/%d playCard Tests Passed.", passed, numTests);
}

int playCard_phaseTest() {
	struct gameState* gS = newGame();

	gS->phase = 4;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	delete gS;
}

int playCard_actionTest() {
	struct gameState* gS = newGame();

	gS->phase = 0;
	gs->numActions = 0;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	delete gS;
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


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	delete gS;
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


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	delete gS;
}

// incompelete
//int playCard_cardEffectTest() {
//	struct gameState* gS = newGame();
//
//	gS->phase = 0;
//	gS->numActions = 1;
//	gS->whoseTurn = 0;
//	// setting first card of P1s hand to any card higher in the enum than TM
//	gS->hand[0][0] = 27; // beyond the current set of cards
//
//	int expected = -1;
//	int actual = playCard(0, 0, 0, 0, gS);
//
//
//	if (actual == expected) {
//		printf("TEST  SUCCESSFULLY COMPLETED\n");
//		return 1;
//	}
//	else {
//		printf("TEST FAILED\n");
//		return 0;
//	}
//
//	delete gS;
//}