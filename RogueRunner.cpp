//Names: Aseanti, Skyler, Logan, Erika, Jacob
#include "Rogue.h"
#include <iostream>
using namespace std;

int main()
{
	int spent_points;
	string equip;
	//these are named vaguely because they're used for taking in various things.
	string stuff;
	int things;
	Rogue r;
	cout<< "Welcome to your guide through making a Rogue class DnD character. ";
	cout<< "Here you will be able to set your character's ability scores, weaponry, age, and race." << endl;
	cout<< "WARNING: when asked for input, at no point should you enter any spaces. Enter underscores instead"<<endl;
	
	cout<< "What level would you like your character to be? (1-4)"<<endl;
	cin>>things;
	r.levelUp(things);

	//put equipment & stuff here
	cout<<"Would you like a rapier or a shortsword?"<<endl;
	cin>>equip;
	r.addEquipment(equip);
	cout<<"Would you like a shortbow (with 20 arrows) or a shortsword?"<<endl;
	cin>>equip;
	r.addEquipment(equip);	
	//pirate speak because cin can't handle spaces
	cout<<"Would you like a pack'o'burgling, a pack'o'dungeoneering, or a pack'o'exploring?"<<endl;
	cin>>equip;
	r.addEquipment(equip);
	
	
	cout<< " Score       Cost\n" << "-------     -------" << endl;
	cout<< "8           0\n" << "9           1\n" << "10          2\n" << "11          3\n";
	cout<< "12          4\n" << "13          5\n" << "14          7\n" << "15          9\n";
	
	
	//print out default stats (8 in all stats)
	
	cout<< "You can add a total of 27 points to your stats, with a max of 9 in each one." << endl;
	
	cout<< "How many points would you like in each of the following stats?:" << endl;
	
	cout<< "Strength: "<<endl;
	cin>> spent_points;
	r.pointBuy(0, spent_points);
	cout<< "Dexterity: "<<endl;
	cin>> spent_points;
	r.pointBuy(1, spent_points);
	cout<< "Constitution: "<<endl;
	cin>> spent_points;
	r.pointBuy(2, spent_points);
	cout<< "Intellignece: "<<endl;
	cin>> spent_points;
	r.pointBuy(3, spent_points);
	cout<< "Wisdom: "<<endl;
	cin>> spent_points;
	r.pointBuy(4, spent_points);
	cout<< "Charisma: "<<endl;
	cin>> spent_points;
	r.pointBuy(5, spent_points);
	r.changeSkills();
	cout<< "What's your character's name?"<<endl;
	cin>> stuff;
	r.changeName(stuff);
	cout<< "And what's their alignment?"<<endl;
	cout<< "Pick one from Chaotic, Neutral, Lawful and one from Evil, Neutral, Good, and write it like this: CN for Chaotic Neutral, LE for Lawful Evil, etc."<<endl;
	cin>>stuff;
	r.changeAlignment(stuff);
	cout<< "And their age?"<<endl;
	cin>>things;
	r.changeAge(things);
	cout<<"And their race? (Dwarf, Elf, Halfling, Human)"<<endl;
	cin>>stuff;
	r.changeRace(stuff);
	//once the returnProficiencies method is done, add some code here to change racial proficiencies.
	r.addRacialBonuses();
	r.roguePrint();
	
	
	return 0;
}
