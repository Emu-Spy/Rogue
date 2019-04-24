#include "Rogue.h"
#include "Stats.cpp"
using namespace std;

Rogue :: Rogue(){
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
	description="";
	//this is a rogue's sneak attack at level 1, it changes with experience
	sneak_attack="1d6";
	//initial HP is constitution modifier plus 8
	hp_max=s.getModifier(2)+8;
	current_hp=hp_max;
	hit_dice="1d8";
	//perception is wisdom modifier plus 10
	perception=s.getModifier(4)+10;
	equipment.push_back("Burglar's pack");
	equipment.push_back("Thieves' tools");
	armor="leather";
	shield=false;
	//the armor class is the dexterity modifier plus the armor's AC (in this case, leather=11)
	ac=s.getModifier(1)+11;
	//assigning skills
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
	skills[12]+=proficiency_bonus;
	skills[14]+=proficiency_bonus;
	//assign nothing to feats right now, there won't be any at level 1 unless you're variant human
	languages.push_back("Common");
	languages.push_back("Elvish");
}
