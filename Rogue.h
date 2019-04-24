#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rogue{
	private:
		int level;
		int xp;
		int speed;
		string race;
		string alignment;
		int age;
		int ac;
		int initiative;
		int hp;
		int perception;
		int death_success;
		string hit_dice;
		int death_fail;
		double gold;
		int proficiency_bonus;
		int inspiration;
		string name;
		string player_name;
		vector <string> equipment;
		//TODO: implement weapons.
		string sneak_attack;
		vector <string> languages;
		string armor;
		bool shield;
		int skills[18];
	public:
		Rogue();
		void print();
		void changeRace(string racial);
		void changeAlignment(string align);
		void addLanguage(string lang);
		string getRace();
};
