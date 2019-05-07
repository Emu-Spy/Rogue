//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include "Race.h"
#include "iostream"
#include "string"
using namespace std;

Race :: Race(){
	race="Elf";
	for(int i=0;i<7;i++){
		raceBonus[i]=0;
	}
	raceBonus[1]=2;
	languages[0] = "Common";
	languages[1] = "Elvish";
	languages[2] = "Empty";
	raceAbilities[0] = "Fey Ancestry";
	raceAbilities[1] = "Trance";
	raceAbilities[2] = "Empty";
	size=medium;
	speed=30;
	darkvision=true;
	for(int j=0;j<18;j++){
		skillProficiencies[j]=false;
	}
	skillProficiencies[13]=true;
}

void Race :: changeRace(string p_race){
	string lang = "";
	if(p_race=="Elf"){
		race="Elf";
		raceBonus[3] += 1;
		raceBonus[1] +=2;
		languages[0] = "Common";
		languages[1] = "Elvish";
		cout<< "Pick your third language: ";
		cin<< lang;
		languages[2] = lang;
		raceAbilities[0] = "Fey Ancestry";
		raceAbilities[1] = "Trance";
		raceAbilities[2] = "Empty";
		raceAbilities[3] = "Empty";
		raceAbilities[4] = "Empty";
		raceAbilities[5] = "Empty";
		raceAbilities[6] = "Empty";
		skillProficiencies[13]=true;
	}
	if(p_race=="Halfling"){
		race="Halfling";
		raceBonus[1] += 2;
		raceBonus[5] += 1;
		languages[0] = "Common";
		languages[1] = "Halfling";
		languages[2] = "Empty";
		raceAbilities[0] = "Lucky";
		raceAbilities[1] = "Brave";
		raceAbilities[2] = "Halfling Nimbleness";
		raceAbilities[3] = "Naturally Stealthy";
		raceAbilities[4] = "Empty";
		raceAbilities[5] = "Empty";
		raceAbilities[6] = "Empty";
		
		skillProficiencies[13]=true;
	}
	else{
		race="invalid";
		for(int i = 0; i < 3; i++)
		{
			languages[i] = "Empty";
			raceAbilities[i] = "Empty";
		}
	}
}

void Race :: racePrint(){
	cout<<"Your race is: "<<race<<endl;
	cout<<"The languages you know are: ";
	//this for loop is like this so no comma gets printed after the last language. Ditto for the raceAbilities loop a few lines down.
	for(int i=0;i<2;i++){
		if(languages[i] == "Empty")
		{	
			cout<<"."<<endl;
			i=2;
		}
		else
			cout<<languages[i]<<", ";
	}
	if(languages[2] != "Empty")
		cout<<languages[2]<<"."<<endl;
	cout<<"Your racial abilities are: ";
	for(int j=0; j<2;j++){
		if(raceAbilities[j] == "Empty")
		{
			cout<<"."<<endl;
			j=2;
		}
		else
			cout<<raceAbilities[j]<<", ";
	}
	if(raceAbilities[2] != "Empty")
		cout<<raceAbilities[2]<<"."<<endl;
}

string Race :: returnRace()
{
	return race;
}
