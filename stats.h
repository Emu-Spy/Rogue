#include <iostream>
using namespace std;

class Stats
{
	private:
		int values[6] = {0, 0, 0, 0, 0, 0};
		int mods[6] = {};
	
	public:
		void print();
		void changeStat();
		void findModifier();
};
