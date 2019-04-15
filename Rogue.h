#include <iostream>
#include <string>
#include <vector>
#include "stats.cpp"
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
		int hp_max;
		int current_hp;
		int intel_save;
		int cha_save;
		int dex_save;
		int con_save;
		int wis_save;
		int str_save;
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
		string description;
		string sneak_attack;
		vector <string> feats;
		vector <string> languages;
		string armor;
		bool shield;
		int skills[18];
	public:
		Rogue();
		vector <int> roll_stats();
		int four_dice_drop_low();
		int find_modifier(int stat);
		//TODO: print method
};
