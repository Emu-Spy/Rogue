//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include "Race.h"
#include "iostream"
#include "string"
using namespace std;

Race :: Race(){
	race="High Elf";
		raceBonus[3] += 1;
		raceBonus[1] +=2;
		languages[0] = "Common";
		languages[1] = "Elvish";
		cout<< "Pick your third language: "<<endl;
		cin>> lang;
		languages[2] = lang;
		cout<< "Pick a cantrip from the wizard list"<<endl;
		cin>> cantrip;
		raceAbilities[0] = "Fey Ancestry";
		raceAbilities[1] = "Trance";
		raceAbilities[2] = "Empty";
		raceAbilities[3] = "Empty";
		raceAbilities[4] = "Empty";
		raceAbilities[5] = "Empty";
		raceAbilities[6] = "Empty";
		skillProficiencies[13]=true;
		size="medium";
		speed=30;
		darkvision=true;
}

void Race :: changeRace(string p_race){
	string lang = "";
	if(p_race=="Elf"){
		race="High Elf";
		raceBonus[3] += 1;
		raceBonus[1] +=2;
		languages[0] = "Common";
		languages[1] = "Elvish";
		cout<< "Pick your third language: "<<endl;
		cin>> lang;
		languages[2] = lang;
		cout<< "Pick a cantrip from the wizard list"<<endl;
		cin>> cantrip;
		raceAbilities[0] = "Fey Ancestry";
		raceAbilities[1] = "Trance";
		raceAbilities[2] = "Empty";
		raceAbilities[3] = "Empty";
		raceAbilities[4] = "Empty";
		raceAbilities[5] = "Empty";
		raceAbilities[6] = "Empty";
		skillProficiencies[13]=true;
		size="medium";
		speed=30;
		darkvision=true;
	}
	if(p_race=="Halfling"){
		race="Lightfoot Halfling";
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
		size = "small";
		speed = 25;
		darkvision = false;
	}
	if(p_race=="Human"){
		race="Human";
		raceBonus[0] += 1;
		raceBonus[1] += 1;
		raceBonus[2] += 1;
		raceBonus[3] += 1;
		raceBonus[4] += 1;
		raceBonus[5] += 1;
		languages[0] = "Common";
		cout<< "Pick your second language: ";
		cin>> lang;
		languages[1] = lang;
		languages[2] = "Empty";
		raceAbilities[0] = "Speed";
		raceAbilities[1] = "Empty";
		raceAbilities[2] = "Empty";
		raceAbilities[3] = "Empty";
		raceAbilities[4] = "Empty";
		raceAbilities[5] = "Empty";
		raceAbilities[6] = "Empty";
		skillProficiencies[13]=true;
		speed = 30;
		size = "Medium";
		darkvision = false;
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
