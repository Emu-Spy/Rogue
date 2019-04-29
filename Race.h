//Names: Aseanti, Skyler, Logan, Erika, Jacob
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Race
{
	private:
		string race;
		string backstory;
		int raceBonus[6];
		bool skillProficiencies[18];
		bool darkvision;
		int speed;
		vector <string> languages;
		vector <string> raceAbilities;
	public:
		Race();
		void changeRace(string p_race);
		void racePrint();
		//TODO: code these methods and then use them in rogue.cpp
		int* returnBonuses();
		int* returnProficiencies();
};