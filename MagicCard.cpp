
#include <string>
#include <sstream>
#include "MagicCard.hpp"


MagicCard::MagicCard() : name(" "), effect(" "), card_type(type(0))
{
}

MagicCard::MagicCard(string name, string effect, type type) : name(name), effect(effect), card_type(type)
{
}

void MagicCard::setName(string name)
{
	this->name = name;
}

void MagicCard::setEffect(string effect)
{
	this->effect = effect;
}

void MagicCard::setType(type card_type)
{
	this->card_type = card_type;
}

string MagicCard::getName()
{
	return name;
}

string MagicCard::getEffect()
{
	return effect;
}

MagicCard::type MagicCard::getType()
{
	return card_type;
}

string MagicCard::getAsString()
{
	ostringstream result;
	result << name << "|" << effect << "|" << card_type << "\n";
	return result.str();
}

MagicCard::type MagicCard::of_string(string str)
{
	if (str == "trap")
	{
		return type(0);
	}
	else if (str == "buff") {
		return type(1);
	}
	else if (str == "spell") {
		return type(2);
	}
	return type(4);
}
