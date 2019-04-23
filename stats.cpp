#include <iostream>
#include "stats.h"
using namespace std;

Stats :: Stats(){
	for(int i = 0; i < 6; i++)
	{
		values[i] = 0;
		mods[i] = 0;
	}
}

int Stats :: findModifier(int stat){
	return mods[stat-1];
}
void Stats :: print ()
{
	cout << "Strength: " << values[0] << ", Mod: " << mods[0] << endl;
	cout << "Dexterity: " << values[1] << ", Mod: " << mods[1] << endl;
	cout << "Constitution: " << values[2] << ", Mod: " << mods[2] << endl;
	cout << "Intelligence: " << values[3] << ", Mod: " << mods[3] << endl;
	cout << "Wisdom: " << values[4] << ", Mod: " << mods[4] << endl;
	cout << "Charisma: " << values[5] << ", Mod: " << mods[5] << endl;
}

void Stats :: changeStat(int stat, int num)
{
	values[stat] = num;
	if(num>11)
		mods[stat]=(num-11)/2;
	else if(num<10)
		mods[stat]=((11-num)/2)*-1;
	else
		mods[stat]=0;
}
