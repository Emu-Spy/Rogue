//Names: Aseanti, Skyler, Logan, Erika, Jacob
#include <iostream>
#include <string>
using namespace std;
class Race
{
	private:
		string race;
		string languages[3];
		string raceAbilities[3];
		int raceBonus[6];
		bool skillProficiencies[18];
	public:
		Race();
		void changeRace(string p_race);
		void racePrint();
		string returnRace();
};
