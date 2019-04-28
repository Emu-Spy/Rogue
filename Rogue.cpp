//Names: Aseanti, Skyler, Logan, Erika, Jacob
#include "Rogue.h"
using namespace std;

Rogue :: Rogue(){
	//How to fix the fact that we have 2 Stats objects: calculate AC in the runner. 
	level=0;
	xp=0;
	alignment="Chaotic Neutral";
	age=122;
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
	equipment.push_back("Burglar's pack");
	equipment.push_back("Thieves' tools");
	armor="no";
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
	cout<<"Your alignment is "<<alignment<<"and you are "<<age<<" years old."<<endl;
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