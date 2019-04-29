//Names: Ashanti, Skyler, Logan, Erika, Jacob
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
		int hp;
		int perception;
		int skills[24];
		int points;
	public:
		Rogue();
		void roguePrint();
		void changeAlignment(string align);
		int getArmorStrength();
		void changeAC(int newac);
		void pointBuy(int index, int pointsSpent);
		void changeSkills();
		void changeName(string newname);
		void addEquipment(string newEquip);
		void changeAge(int newAge);
		void changeRace(string newrace);
		void addRacialProficiencies(bool profs[]);
		int calcModifier(int stat);
		int getModifier(int index);
		int getStat(int index);
		void changeStat(int index, int newStat);
		void statsPrint();
		void addProficiency(int skill);
};
