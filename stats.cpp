#include <iostream>
#include "stats.h"
using namespace std;

Stats :: Stats(){
	for(int i=0;i<6;i++){
		mods[i]=-1;
		values[i]=8;
		points=27;
	}
	//assigning skills TODO: a method for changing these
	for(int i=0; i<18; i++){
		skills[i]=-1;
	}
	hp=getModifier(2)+8;
	perception=getModifier(4)+10;
}
//uses a formula to find modifiers for ability scores
int Stats :: calcModifier(int stat){
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

int Stats :: getModifier(int index){
	return mods[index];
}

int Stats :: getStat(int index){
	return values[index];
}

void Stats :: changeStat(int index, int newStat){
	values[index]=newStat;
	mods[index]=calcModifier(newStat);
}
//looks a bit ugly, could possibly be improved with a switch case
void Stats :: pointBuy(int index, int pointsSpent){
	if(pointsSpent=0)
		//do nothing
		points-=0;
	else if(pointsSpent=1){
		values[index]=9;
		points-=1;
	}
	else if(pointsSpent=2){
		values[index]=10;
		points-=2;
	}
	else if(pointsSpent=3){
		values[index]=11;
		points-=3;	
	}
	else if(pointsSpent=4){
		values[index]=12;
		points-=4;
	}
	else if(pointsSpent=5){
		values[index]=13;
		points-=5;
	}
	else if(pointsSpent=7){
		values[index]=14;
		points-=7;
	}
	else if(pointsSpent=9){
		values[index]=15;
		points-=9;
	}
}

void Stats :: changeSkills(){
	//assigning skills. Run this after determining stats.
	skills[0]=mods[0];
	for(int i=1; i<4; i++){
		skills[i]=mods[1];
	}
	for(int j=4; j<9; j++){
		skills[j]=mods[3];
	}
	for(int k=9; k<14; k++){
		skills[k]=mods[4];
	}
	for(int l=14; l<18; l++){
		skills[l]=mods[5];
	}
}
//TODO: racial bonuses