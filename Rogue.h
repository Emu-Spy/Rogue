#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rogue{
	private:
		Stats s;
		int level;
		int xp;
		int speed;
		string race;
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
		vector <string> languages;
		string armor;
		bool shield;
	public:
		Rogue();
		void print();
		void changeRace(string racial);
		void changeAlignment(string align);
		void addLanguage(string lang);
		int getArmorStrength();
		string getRace();
		void changeAC(int newac);
};
