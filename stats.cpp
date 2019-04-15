#include <iostream>
#include "stats.h"
using namespace std;

//uses a formula to find modifiers for ability scores
int stats :: findModifier(int stat){
	int mod;
	//the modifier increases by 1 for every 2 over 10 and decreases by 1 for every 2 under 11. For 10 and 11 it is 0.
	if(stat>11)
		mod=(stat-11)/2;
	else if(stat<10)
		mod=((11-stat)/2)*-1;
	else
		mod=0;
	return mod;	
}
