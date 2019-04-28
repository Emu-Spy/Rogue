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
		Race(string p_race);
		void racePrint();
		int* returnBonuses();
		int* returnProficiencies();
};