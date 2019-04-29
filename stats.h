//Names: Ashanti, Skyler, Erika, Logan, Jacob
#include <iostream>
using namespace std;
class Stats
{
	private:
		int values[6];
		int mods[6];
	public:
		Stats();
		
		int returnStat(int i);
		int returnMod(int i);
		void change(string var, int i, int newVal);
};
