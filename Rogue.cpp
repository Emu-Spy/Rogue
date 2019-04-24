#include "Rogue.h"
#include "stats.cpp"
using namespace std;

Rogue :: Rogue(){
	//How to fix the fact that we have 2 Stats objects: write additional methods to calculate hp, perception, and AC. Then move everything involving skills to stats.cpp and implement saving throws there as well.
	Stats s;
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
	//initial HP is constitution modifier plus 8
	hp=s.getModifier(2)+8;
	hit_dice="1d8";
	//perception is wisdom modifier plus 10
	perception=s.getModifier(4)+10;
	equipment.push_back("Burglar's pack");
	equipment.push_back("Thieves' tools");
	armor="none";
	shield=false;
	//the armor class is the dexterity modifier plus the armor's AC (in this case, leather=11)
	ac=s.getModifier(1)+11;
	//assigning skills TODO: move this to stats.cpp
	skills[0]=s.getModifier(0);
	for(int i=1; i<4; i++){
		skills[i]=s.getModifier(1);
	}
	for(int j=4; j<9; j++){
		skills[j]=s.getModifier(3);
	}
	for(int k=9; k<14; k++){
		skills[k]=s.getModifier(4);
	}
	for(int l=14; l<18; l++){
		skills[l]=s.getModifier(5);
	}
	//there's proficiency in Acrobatics, Athletics, Intimidation, and Investigation (due to Rogue) and Perception (due to Elf), so add the proficiency bonus to those.
	skills[0]+=proficiency_bonus;
	skills[1]+=proficiency_bonus;
	skills[6]+=proficiency_bonus;
	skills[14]+=proficiency_bonus;
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
string Rogue :: getRace(){
	return race;
}
//suboptimal implementation, but if it works it works
int Rogue :: getArmorStrength(){
	//leather is the only armor a rogue can have on generation
	if(armor="leather")
		return 10;
	else
		return 0;
}