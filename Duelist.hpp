
#pragma once

#include "Deck.hpp"

using namespace std;

class Duelist
{
private:
	string name;
	Deck deck;

public:
	Duelist(string);

	Deck getDeck();
	bool writeDeckToFile(string);
	bool updateDeckfromFile(string);

private:
	string* parseFirstLine(string);
	MonsterCard parseMonsterCardLine(string);
	MagicCard parseMagicCardLine(string);
	PendulumCard parsePendulumCardLine(string);
};

