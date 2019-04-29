//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include "Rogue.h"
using namespace std;

Rogue :: Rogue(){
	//How to fix the fact that we have 2 Stats objects: calculate AC in the runner. 
	level=0;
	xp=0;
	alignment="Chaotic Neutral";
	age=45;
	initiative=0;
	death_success=0;
	death_fail=0;
	gold=0;
	//default proficiency bonus for lvl1
	proficiency_bonus=2;
	inspiration=0;
	name="Rogueus Genericus";
	player_name="Wren";
	//this is a rogue's sneak attack at level 1, it changes with experience
	sneak_attack="1d6";
	hit_dice="1d8";
	armor="no";
	equipment.push_back("dagger");
	equipment.push_back("dagger");
	equipment.push_back("thieves' tools");
	armor="leather";
	shield=false;
}

void Rogue :: changeAlignment(string align){
	alignment=align;
}

int Rogue :: getArmorStrength(){
	//leather is the only armor a rogue can have on generation
	if(armor=="leather")
		return 10;
	else
		return 0;
}
void Rogue :: changeAC(int newac){
	ac=newac;
}

void Rogue :: pointBuy(int index, int pointsSpent){
	s.pointBuy(index, pointsSpent);
}
void Rogue :: changeSkills(){
	s.changeSkills();
	//putting this here simply because I can't think of a better place
	changeAC(getArmorStrength()+s.getModifier(1));
}
void Rogue :: roguePrint(){
	cout<<"Your level is "<<level<<" and you have "<<xp<<" experience points."<<endl;
	cout<<"Your alignment is "<<alignment<<" and you are "<<age<<" years old."<<endl;
	cout<<"Your name is "<<player_name<<" and your character's name is "<<name<<endl;
	ra.racePrint();
	s.statsPrint();
	cout<<"You have "<<initiative<<" initiative and "<<inspiration<<" inspiration."<<endl;
	cout<<"You have failed "<<death_fail<<" death saves and succeded "<<death_success<<"."<<endl;
	cout<<"For sneak attack, roll "<<sneak_attack<<", and for hit dice, roll "<<hit_dice<<endl;
	cout<<"At your disposal, you have: ";
	for(int i=0; i<equipment.size()-1;i++){
		cout<<equipment[i]<<", ";
	}
	cout<<equipment[equipment.size()-1]<<"."<<endl;
	cout<<"You have "<<armor<<" armor and ";
	if(shield==true)
		cout<<"a shield."<<endl;
	else
		cout<<"no shield."<<endl;
}
void Rogue :: changeName(string newname){
	name=newname;
}
void Rogue :: addEquipment(string newEquip){
	equipment.push_back(newEquip);
}
void Rogue :: changeAge(int newAge){
	age=newAge;
}
void Rogue :: changeRace(string newrace){
	ra.changeRace(newrace);
}
void Rogue :: addRacialProficiencies(bool profs[]){
	for(int j=0;j<18;j++){
		if(profs[j]==true)
			s.addProficiency[j];
	}
}

Stats :: Stats(){
	for(int i=0;i<6;i++){
		mods[i]=-1;
		values[i]=8;
		points=27;
	}
	for(int i=0; i<24; i++){
		skills[i]=-1;
	}
	hp=getModifier(2)+8;
	perception=getModifier(4)+10;
}
//uses a formula to find modifiers for ability scores
int Stats :: calcModifier(int stat){
	int mod;
	//the modifier increases by 1 for every 2 over 10 and decreases by 1 for every 2 under 11. For 10 and 11 it is 0.
	if(stat>10)
		mod=(stat-10)/2;
	else if(stat<10)
		mod=((10-stat)/2)*-1;
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
	if(pointsSpent==0)
		//do nothing
		points-=0;
	else if(pointsSpent==1){
		changeStat(index,9);
		points-=1;
	}
	else if(pointsSpent==2){
		changeStat(index,10);
		points-=2;
	}
	else if(pointsSpent==3){
		changeStat(index,11);
		points-=3;	
	}
	else if(pointsSpent==4){
		changeStat(index,12);
		points-=4;
	}
	else if(pointsSpent==5){
		changeStat(index,13);
		points-=5;
	}
	else if(pointsSpent==7){
		changeStat(index,14);
		points-=7;
	}
	else if(pointsSpent==9){
		changeStat(index,15);
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
	skills[18]=mods[0];
	skills[19]=mods[1];
	skills[20]=mods[2];
	skills[21]=mods[3];
	skills[22]=mods[4];
	skills[23]=mods[5];
}
void Stats :: addProficiency(int skill){
	skills[skill]+=2;
}

void Stats :: statsPrint(){
	cout<<"Your stats are:"<<endl;
	cout<<"Strength is: "<<values[0]<<" with a modifier of: "<<mods[0]<<" and a saving throw of: "<<skills[18]<<endl;
	cout<<"Dexterity is: "<<values[1]<<" with a modifier of: "<<mods[1]<<" and a saving throw of: "<<skills[19]<<endl;
	cout<<"Constitution is: "<<values[2]<<" with a modifier of: "<<mods[2]<<" and a saving throw of: "<<skills[20]<<endl;
	cout<<"Intelligence is: "<<values[3]<<" with a modifier of: "<<mods[3]<<" and a saving throw of: "<<skills[21]<<endl;
	cout<<"Wisdom is: "<<values[4]<<" with a modifier of: "<<mods[4]<<" and a saving throw of: "<<skills[22]<<endl;
	cout<<"Charisma is: "<<values[5]<<" with a modifier of: "<<mods[5]<<" and a saving throw of: "<<skills[23]<<endl;
	cout<<"Here are your skills, listed from top on the character sheet to bottom"<<endl;
	for(int i=0;i<18;i++){
		cout<<skills[i]<<endl;
	}
}
