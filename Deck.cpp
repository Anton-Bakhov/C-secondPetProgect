
#include <string>
#include <vector>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Deck.hpp"


string Deck::getName()
{
	return this->name;
}

void Deck::setName(string name)
{
	this->name = name;
}

int Deck::capacityOfMonsters()
{
	return monsters.size();
}

int Deck::capacityOfMagics()
{
	return magics.size();
}

int Deck::capacityOfPendulums()
{
	return pendulums.size();
}

void Deck::addMonster(MonsterCard& monsterCard)
{
	monsters.push_back(monsterCard);
}

void Deck::addMagic(MagicCard& magicCard)
{
	magics.push_back(magicCard);
}

void Deck::addPendulum(PendulumCard& pendulumCard)
{
	pendulums.push_back(pendulumCard);
}

void Deck::changeMonsterCard(unsigned int index, MonsterCard& newMonster)
{
	if (index >= 0 && index < monsters.size()) {
		monsters[index] = newMonster;
	}
}

void Deck::changeMagicCard(unsigned int index, MagicCard& newMagic)
{
	if (index >= 0 && index < magics.size()) {
		magics[index] = newMagic;
	}
}

void Deck::changePendulumCard(unsigned int index, PendulumCard& newPendulum)
{
	if (index >= 0 && index < pendulums.size()) {
		pendulums[index] = newPendulum;
	}
}

void Deck::clearDeck()
{
	monsters.clear();
	magics.clear();
	pendulums.clear();
}

string Deck::getDeckAsString()
{
	string result = "";
	for (MagicCard magic_card : magics)
	{
		result = result.append(magic_card.getAsString());
	}
	for (MonsterCard monster_card : monsters)
	{
		result = result.append(monster_card.getAsString());
	}
	for (PendulumCard pendulum_card : pendulums)
	{
		result = result.append(pendulum_card.getAsString());
	}
	return result;
}


