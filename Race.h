//Names: Logan Parker, Jacob Hoch, Erika Lebron, Skyler Huckabee-Jennings, Ashanti Lomas-Ortega
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Race
{
	public:
		string race;
		string backstory;
		int raceBonus[6];
		int speed;
		vector <string> languages;
		vector <string> raceAbilities;
	private:
		Race();
		Race(string p_race);
		
		void racePrint();
		int* returnArray();
}
