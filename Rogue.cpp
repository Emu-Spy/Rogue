#include "Rogue.h"
using namespace std;

Rogue :: Rogue(){
	//How to fix the fact that we have 2 Stats objects: calculate AC in the runner. 
	level=0;
	xp=0;
	speed=30;
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
	armor="none";
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
void Rogue :: statsPrint(){
	s.statsPrint();
}
void Rogue :: racePrint(){
	ra.racePrint();
}
//TODO: print method