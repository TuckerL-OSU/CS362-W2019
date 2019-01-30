#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int phaseTest();
//#define SUCCESS "TEST  SUCCESSFULLY COMPLETED"
//#define FAILURE "TEST FAILED"


int main() {

	// play card
	//struct gameState* gS = newGame();
	//
	//int expected = -1;
	//int actual = playCard(0, 0, 0, 0, gS);

	//if (actual == expected) {
	//	std::cout << "TEST  SUCCESSFULLY COMPLETED" << endl;
	//}
	//else {
	//	std::cout << "TEST FAILED" << endl;
	//}
	playCard_phaseTest();
	playCard_actionsTest();
	playCard_checkActionTest_adventurer();
	playCard_checkActionTest_treasure_map();
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

//int playCard_checkActionTest_treasure_map() {
//
//}