#include "task1-functions.h"
#include <iostream>
#include <math.h>
using namespace std;

#define KM_PER_MILE 1.609344

// setEngineMode - outputs the engine mode based on speed S (mph) and battery level B (%)
// Returns 0 for battery mode and 1 for petrol
int setEngineMode(int S, int B)
{

	// ************************
	// WRITE YOUR SOLUTION HERE
	// ************************


	//output rounded S
	S = static_cast<int>(round(S));
	//if else statements
	int engineModeE;
	if ((S < 10) && (0 <= S)) {
		if (B > 25) {
			engineModeE = 0;
		}
		else {
			engineModeE = 1;
		}
	}
	else {
		if ((10 <= S) && (S < 30)) {
			if (B >= 45) {
				engineModeE = 0;
			}
			else {
				engineModeE = 1;
			}
		}
		else {
			engineModeE = 1;
		}
	}

	//Change this
	return engineModeE;
};

