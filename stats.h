#include <iostream>
using namespace std;

class Stats
{
	private:
		int values[6];
		int mods[6];
	
	public:
		Stats();
		Stats(int p_values[]);
		void print();
		void changeStat();
		void findModifier();
};
