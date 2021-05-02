
#pragma once

#include <vector>

using namespace std;

class Deck
{
public:
	string getName();

	void setName(string);

	int capacityOfMonsters();
	int capacityOfMagics();
	int capacityOfPendulums();

	void addMonster(MonsterCard& monsterCard);
	void addMagic(MagicCard& magicCard);
	void addPendulum(PendulumCard& pendulumCard);

	void changeMonsterCard(unsigned int index, MonsterCard& newMonster);
	void changeMagicCard(unsigned int index, MagicCard& newMagic);
	void changePendulumCard(unsigned int index, PendulumCard& newPendulum);

	void clearDeck();

	string getDeckAsString();

private: 
	string name;
	vector <MonsterCard> monsters;
	vector <MagicCard> magics;
	vector <PendulumCard> pendulums;
};

