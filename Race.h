//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include <iostream>
#include <string>
using namespace std;
class Race
{
	private:
		string race;
		string size;
		string cantrip;
		bool darkvision;
		int speed;
		string languages[3];
		string raceAbilities[7];
		int raceBonus[6];
		bool skillProficiencies[18];
	public:
		Race();
		void changeRace(string p_race);
		void racePrint();
		string returnRace();
};
