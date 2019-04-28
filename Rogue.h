#include <iostream>
#include <string>
#include <vector>
#include "stats.h"
#include "Race.h"
using namespace std;

class Rogue{
	private:
		Stats s;
		Race ra;
		int level;
		int xp;
		string alignment;
		int age;
		int ac;
		int initiative;
		int death_success;
		string hit_dice;
		int death_fail;
		double gold;
		int proficiency_bonus;
		int inspiration;
		string name;
		string player_name;
		//a vector is basically an array with non-static length
		vector <string> equipment;
		//TODO: implement weapons.
		string sneak_attack;
		string armor;
		bool shield;
	public:
		Rogue();
		void roguePrint();
		void changeAlignment(string align);
		int getArmorStrength();
		void changeAC(int newac);
		//these methods just call a method in stats. There may be a better solution.
		void pointBuy(int index, int pointsSpent);
		void changeSkills();
};
