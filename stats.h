#include <iostream>
using namespace std;
class Stats
{
	private:
		int values[6];
		int mods[6];
		//saving throws are the last 6 elements here
		int skills[24];
		int points;
		//these are now here and not in Rogue.h because they're calculated off stats and it's much easier to do that here.
		int hp;
		int perception;
	public:
		Stats();
		int calcModifier(int stat);
		int getModifier(int index);
		int getStat(int index);
		void changeStat(int index, int newStat);
		void pointBuy(int index, int pointsSpent);
		void changeSkills();
		void applyRacialModifiers();
		void statsPrint();
		void addProficiency(int skill);
};
