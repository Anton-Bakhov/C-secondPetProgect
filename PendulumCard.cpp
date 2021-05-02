#include <string>
#include <sstream>
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "PendulumCard.hpp"


PendulumCard::PendulumCard() : MonsterCard(" ", " ", 0, 0), MagicCard(" ", " ", type(0)), pendulum(1)
{
}

PendulumCard::PendulumCard(string name, string effect, unsigned int attack, unsigned int deffence, type card_type, unsigned short int pendulum)
	: MonsterCard(name, effect, attack, deffence), MagicCard(name, effect, card_type), pendulum(pendulum)
{
}

void PendulumCard::setPendulum(unsigned short int pendulum)
{
	if (pendulum >= 1 && pendulum <= 13) {
		this->pendulum = pendulum;
	}
}

unsigned short int PendulumCard::getPendulum()
{
	return this->pendulum;
}

string PendulumCard::getAsString()
{
	ostringstream result;
	result << MonsterCard::name << "|" << MonsterCard::effect << "|" << attack << "|" << deffence << "|" << pendulum << "|" << card_type << "\n";
	return result.str();
}
