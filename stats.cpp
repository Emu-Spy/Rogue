//Names: Ashanti, Skyler, Erika, Logan, Jacob
#include <iostream>
#include "stats.h"
using namespace std;

Stats :: Stats(){
	for(int i=0;i<6;i++)
	{
		mods[i]=-1;
		values[i]=8;
	}
}

int Stats :: returnStat(int i)
{
	return values[i];
}

int Stats :: returnMod(int i)
{
	return mods[i];
}

void Stats :: change(string var, int i, int newVal)
{
	if(var == "stats")
	{
		values[i] = newVal;
	}
	if(var == "mods")
	{
		mods[i] = newVal;
	}
}
