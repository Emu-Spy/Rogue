#include <iostream>
using namespace std;
class Stats
{
	private:
		int values[6];
		int mods[6];
		int points;
	public:
		Stats();
		int calcModifier(int stat);
		int getModifier(int index);
		int getStat(int index);
		void changeStat(int index, int newStat);
		void pointBuy(int index, int pointsSpent);
};
