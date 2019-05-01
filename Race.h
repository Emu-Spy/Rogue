//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Race
{
	private:
		string race;
		bool darkvision;
		int speed;
		string languages[3];
		string raceAbilities[3];
	public:
		Race();
		void changeRace(string p_race);
		void racePrint();
};
