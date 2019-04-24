#include "Rogue.h"
using namespace std;

Rogue :: Rogue(){
	//How to fix the fact that we have 2 Stats objects: calculate AC in the runner. 
	level=0;
	xp=0;
	race="Elf";
	//default speed for elves is 30
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
	//Every character has Common as a language
	languages.push_back("Common");
}
void Rogue :: changeRace(string racial){
	race=racial;
	//TODO: implement racial bonuses here. 
}
void Rogue :: changeAlignment(string align){
	alignment=align;
}
void Rogue :: addLanguage(string lang){
	languages.push_back("lang");
}
//this is here so we can add racial bonuses in stats.cpp
string Rogue :: getRace(){
	return race;
}
//these two are here so we can calculate AC in the runner. This is needed because it involves things from both here and stats.cpp
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
//TODO: print method