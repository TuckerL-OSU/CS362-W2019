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
	phaseTest();

}

int phaseTest() {
	struct gameState* gS = newGame();

	gS->phase = 4;

	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED");
	}
	else {
		printf("TEST FAILED");
	}

	//delete gS;
}