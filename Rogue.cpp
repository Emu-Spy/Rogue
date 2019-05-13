//Names: Ashanti, Skyler, Logan, Erika, Jacob
#include "Rogue.h"
using namespace std;

Rogue :: Rogue(){
	level=0;
	points=27;
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
	for(int i=0; i<24; i++){
		skills[i]=-1;
	}
	hp=calcModifier(2)+8;
	perception=calcModifier(4)+10;
	castAbility="Intelligence";
	abilities[0]="Empty";
	abilities[1]="Empty";
	archetype="None";
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
void Rogue :: changeSkills(){
	skills[0] = s.returnMod(0);
	for(int i=1; i<4; i++){
		skills[i]=s.returnMod(1);
	}
	for(int j=4; j<9; j++){
		skills[j]=s.returnMod(3);
	}
	for(int k=9; k<14; k++){
		skills[k]=s.returnMod(4);
	}
	for(int l=14; l<18; l++){
		skills[l]=s.returnMod(5);
	}
	skills[18]=s.returnMod(0);
	skills[19]=s.returnMod(1);
	skills[20]=s.returnMod(2);
	skills[21]=s.returnMod(3);
	skills[22]=s.returnMod(4);
	skills[23]=s.returnMod(5);

	changeAC(getArmorStrength()+calcModifier(1));
}
void Rogue :: roguePrint(){
	cout<<"Your level is "<<level<<" and you have "<<xp<<" experience points."<<endl;
	cout<<"Your alignment is "<<alignment<<" and you are "<<age<<" years old."<<endl;
	cout<<"Your name is "<<player_name<<" and your character's name is "<<name<<endl;
	ra.racePrint();
	statsPrint();
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
	cout<<"Your roguish archetype is "<<archetype<<"."<<endl;
	if(level>=3)
		cout<<"your class abilities are: "<<abilities[1]<<" and "<<abilities[2]<<endl;
	else if(level==2)
		cout<<"You have one racial ability, "<<abilities[1]<<endl;
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
	addRacialBonuses();
}
void Rogue :: addRacialProficiencies(bool profs[]){
	for(int j=0;j<18;j++){
		if(profs[j]==true)
			addProficiency(j);
	}
}

int Rogue :: calcModifier(int stat){
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

int Rogue :: getStat(int index){
	return s.returnStat(index);
}

void Rogue :: changeStat(int index, int newStat){
	s.change("stats", index, newStat);
	s.change("mods", index, calcModifier(newStat));
}

void Rogue :: addProficiency(int skill){
	skills[skill]+=2;
}

void Rogue :: statsPrint(){
	cout<<"Your stats are:"<<endl;
	cout<<"Strength is: "<<s.returnStat(0)<<" with a modifier of: "<<s.returnMod(0)<<" and a saving throw of: "<<skills[18]<<endl;
	cout<<"Dexterity is: "<<s.returnStat(1)<<" with a modifier of: "<<s.returnMod(1)<<" and a saving throw of: "<<skills[19]<<endl;
	cout<<"Constitution is: "<<s.returnStat(2)<<" with a modifier of: "<<s.returnMod(2)<<" and a saving throw of: "<<skills[20]<<endl;
	cout<<"Intelligence is: "<<s.returnStat(3)<<" with a modifier of: "<<s.returnMod(3)<<" and a saving throw of: "<<skills[21]<<endl;
	cout<<"Wisdom is: "<<s.returnStat(4)<<" with a modifier of: "<<s.returnMod(4)<<" and a saving throw of: "<<skills[22]<<endl;
	cout<<"Charisma is: "<<s.returnStat(5)<<" with a modifier of: "<<s.returnMod(5)<<" and a saving throw of: "<<skills[23]<<endl;
	cout<<"Here are your skills, listed from top on the character sheet to bottom"<<endl;
	for(int i=0;i<18;i++){
		cout<<skills[i]<<endl;
	}
}

void Rogue :: levelUp(int p_level){
	if(p_level==4){
		//recursion-esque, ensures every level gets the bonuses of all the levels below it
		levelUp(3);
		level=4;
		//do the ability score improvement
		cout<<"You have 2 points to improve your 6 ability scores. Where would you like your first point?"<<endl;
		cout<<"0. Strength 1. Dexterity 2. Constitution 3. Intelligence 4. Wisdom 5. Charisma"<<endl;
		int temp;
		cin>>temp;
		changeStat(temp, getStat(temp)+1);
		cout<<"And your second point?"<<endl;
		cin>>temp;
		changeStat(temp, getStat(temp)+1);
	}
	else if(p_level==3){
		levelUp(2);
		level=3;
		archetype="Thief";
		sneak_attack="2d6";
		abilities[1]="Fast Hands";
	}
	else if(p_level==2){
		level=2;
		abilities[0]="Cunning Action";
		archetype="None";
	}
	else if(p_level==1){
		level=1;
		archetype="None";
	}
	else{
		level=1;
		archetype="None";
	}
}

void Rogue :: addRacialBonuses()
{
	int temp;
	for(int i=0; i>6; i++)
	{
		temp = s.returnStat(i)+ra.returnBonus(i);
		s.change("stats", i, temp);
	}
}
