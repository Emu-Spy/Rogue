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
//rolls up a set of stats
void Stats :: roll_stats(){
	//calls the fourdicedroplowest method 6 times, representing rolling 6 stats.
	for (int i = 0; i < 6; i++)
	{
		values[i]=four_dice_drop_low();
		if(values[i]>11)
			mods[i]=(values[i]-11)/2;
		else if(values[i]<10)
			mods[i]=((11-values[i])/2)*-1;
		else
			mods[i]=0;
	}
}
//this method rolls four six-sided dice and ignores the lowest one. Then it adds them all together to get a stat from 3-18
int Stats :: four_dice_drop_low(){
	int stat;
	//we'll need 4 dice, so here's an array of size 4.
	int dice[4];
	//because c++ RNG is terrible, we'll base the seed off the time. 
	srand(time(NULL));
	//the %6 restricts the range to 6, the +1 starts it at 1.
	dice[0]=rand()%6+1;
	dice[1]=rand()%6+1;
	dice[2]=rand()%6+1;
	dice[3]=rand()%6+1;
	//put the lowest value in the array at index 0
	int min=0;
	for(int i=1; i<3; i++){
		if(dice[i]<dice[min]){
			int temp=dice[0];
			dice[0]=dice[i];
			dice[i]=temp;
		}
	}
	stat=dice[1]+dice[2]+dice[3];
	return stat;
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
