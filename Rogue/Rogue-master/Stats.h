#include <iostream>
using namespace std;
//these two are included for random number generation
#include <stdlib.h>
#include <time.h>
class Stats
{
	private:
		int values[6];
		int mods[6];
	
	public:
		Stats();
		Stats(int p_values[]);
		void print();
		void changeStat(int stat);
		void findModifier();
		int * roll_stats();
		int four_dice_drop_low();
};
