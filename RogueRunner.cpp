#include "Rogue.cpp"
#include "stats.cpp"
#include <iostream>
using namespace std;

int main()
{
	int spent_points;
	Rogue r;
	//with this we have 2 Stats objects. A fix for this is in progress.
	Stats s;
	cout<< "Welcome to your guide through making a Rogue class DnD cahracter.";
	cout<< "Here you will be able to set your characters ability scores, weaponry, age, and race." << endl;
	
	
	
	cout<< " Score       Cost\n" << "-------     -------" << endl;
	cout<< "8           0\n" << "9           1\n" << "10          2\n" << "11          3\n";
	cout<< "12          4\n" << "13          5\n" << "14          7\n" << "15          9\n" << endl;
	
	
	//print out default stats (8 in all stats)
	
	cout<< "You can add a total of 27 points to your stats, with a max of 9 in each one." << endl;
	
	cout<< "How many points would you like in each of the following stats:" << endl;
	
	cout<< "Strength: "<<endl;
	cin>> spent_points;
	s.pointBuy(0, spent_points);
	cout<< "Dexterity: "<<endl;
	cin>> spent_points;
	s.pointBuy(1, spent_points);
	cout<< "Constitution: "<<endl;
	cin>> spent_points;
	s.pointBuy(2, spent_points);
	cout<< "Intellignece: "<<endl;
	cin>> spent_points;
	s.pointBuy(3, spent_points);
	cout<< "Wisdom: "<<endl;
	cin>> spent_points;
	s.pointBuy(4, spent_points);
	cout<< "Charisma: "<<endl;
	cin>> spent_points;
	s.pointBuy(5, spent_points);
	
	//this is here in the interest of disentagling rogue and stats
	r.changeAC(r.getArmorStrength()+s.getModifier(1));
	
	return 0;
}
