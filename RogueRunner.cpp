#include <iostream>
#include "Rogue.cpp"
using namespace std;

int main()
{
	
	cout<< "Welcome to your guide through making a Rogue class DnD cahracter.";
	cout<< "Here you will be able to set your characters ability scores, weaponry, age, and race." << endl;
	
	
	
	cout<< " Score       Cost\n" << "-------     -------" << endl;
	cout<< "8           0\n" << "9           1\n" << "10          2\n" << "11          3\n";
	cout<< "12          4\n" << "13          5\n" << "14          7\n" << "15          9\n" << endl;
	
	
	//print out default stats (8 in all stats)
	
	cout<< "You can add a total of 27 points to your stats." << endl;
	
	cout<< "How many points would you like in each of the following stats:" << endl;
	
	cout<< "Strength: ";
	cin>> values[0];
	cout<< "\nDexterity: ";
	cin>> values[1];
	cout<< "\nConstitution: ";
	cin>> values[2];
	cout<< "\nIntellignece: ";
	cin>> values[3];
	cout<< "\nWisdom: ";
	cin>> values[4];
	cout<< "\nCharisma: ";
	cin>> values[5];
	
	
	
	
	return 0;
}
