#include "Race.h"
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
	languages.push_back("Common");
	languages.push_back("Elvish");
	raceAbilities.push_back("Fey Ancestry");
	raceAbilities.push_back("Trance");
	for(int j=0;j<18;j++){
		skillProficiencies[j]=false;
	}
	skillProficiencies[13]=true;
	darkvision=true;
}

Race :: Race(string p_race){
	if(p_race=="Elf"){
		race="Elf";
		backstory="This character was chosen by the High Council of their town to go out and discover new lands for the townspeople to evactaute to after the forest dies.";
		raceBonus[0]=0;
		raceBonus[1]=2;
		for(int i=2;i<7;i++){
			raceBonus[i]=0;
		}
		speed=30;
		languages.push_back("Common");
		languages.push_back("Elvish");
		raceAbilities.push_back("Fey Ancestry");
		raceAbilities.push_back("Trance");
		for(int j=0;j<18;j++){
			skillProficiencies[j]=false;
		}
		skillProficiencies[13]=true;
		darkvision=true;
	}

}

void Race :: racePrint(){
	cout<<"Your race is: "<<race<<endl;
	cout<<"Your backstory is: "<<backstory<<endl;
	cout<<"The languages you know are: ";
	//this for loop is like this so no comma gets printed after the last language. Ditto for the raceAbilities loop a few lines down.
	for(int i=0; i<languages.size()-1;i++){
		cout<<languages[i]<<", ";
	}
	cout<<languages[languages.size()-1]<<"."<<endl;
	if(darkvision==true)
		cout<<"You can see in the dark."<<endl;
	else
		cout<<"You can't see in the dark."<<endl;
	cout<<"Your racial abilities are: ";
	for(int j=0; j<raceAbilities.size()-1;j++){
		cout<<raceAbilities[j]<<", ";
	}
	cout<<raceAbilities[raceAbilities.size()-1]<<"."<<endl;
}