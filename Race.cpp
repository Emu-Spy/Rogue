//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include "Race.h"
#include "iostream"
#include "string"
using namespace std;

Race :: Race(){
	race="Elf";
	backstory="This character was chosen by the High Council of their town to go out and discover new lands for the townspeople to evactaute to after the forest dies.";
	raceBonus[0]=0;
	raceBonus[1]=2;
	for(int i=2;i<7;i++){
		raceBonus[i]=0;
	}
	speed=30;
	languages[0] = "Common";
	languages[1] = "Elvish";
	languages[2] = "Empty";
	raceAbilities[0] = "Fey Ancestry";
	raceAbilities[1] = "Trance";
	raceAbilities[2] = "Empty";
	for(int j=0;j<18;j++){
		skillProficiencies[j]=false;
	}
	skillProficiencies[13]=true;
	darkvision=true;
}

void Race :: changeRace(string p_race){
	if(p_race=="Elf"){
		race="Elf";
		backstory="This character was chosen by the High Council of their town to go out and discover new lands for the townspeople to evactaute to after the forest dies.";
		raceBonus[0]=0;
		raceBonus[1]=2;
		for(int i=2;i<7;i++){
			raceBonus[i]=0;
		}
		speed=30;
		languages[0] = "Common";
		languages[1] = "Elvish";
		languages[2] = "Empty";
		raceAbilities[0] = "Fey Ancestry";
		raceAbilities[1] = "Trance";
		raceAbilities[2] = "Empty";
		for(int j=0;j<18;j++){
			skillProficiencies[j]=false;
		}
		skillProficiencies[13]=true;
		darkvision=true;
	}
	else{
		race="invalid";
		backstory="ERROR: invalid race";
		for(int i = 0; i < 3; i++)
		{
			languages[i] = "Empty";
			raceAbilities[i] = "Empty";
		}
	}
}

void Race :: racePrint(){
	cout<<"Your race is: "<<race<<endl;
	cout<<"Your backstory is: "<<backstory<<endl;
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
	if(darkvision==true)
		cout<<"You can see in the dark."<<endl;
	else
		cout<<"You can't see in the dark."<<endl;
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
