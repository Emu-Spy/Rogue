#include <iostream>
#include "stats.h"
using namespace std;

Stats :: Stats(){
	int *p;
	p=roll_stats();
}
//uses a formula to find modifiers for ability scores
int Stats :: findModifier(int stat){
	int mod;
	//the modifier increases by 1 for every 2 over 10 and decreases by 1 for every 2 under 11. For 10 and 11 it is 0.
	if(stat>11)
		mod=(stat-11)/2;
	else if(stat<10)
		mod=((11-stat)/2)*-1;
	else
		mod=0;
	return mod;	
}
//rolls up a set of stats
int * Stats :: roll_stats(){
	static int stats[6];
	//calls the fourdicedroplowest method 6 times, representing rolling 6 stats.
	stats[0]=four_dice_drop_low();
	stats[1]=four_dice_drop_low(); 
	stats[2]=four_dice_drop_low();
	stats[3]=four_dice_drop_low(); 
	stats[4]=four_dice_drop_low();
	stats[5]=four_dice_drop_low(); 
	return stats;	
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
	for (int i = 0; i < 6; i++)
	{
		cout<< values[i];
	}
}
