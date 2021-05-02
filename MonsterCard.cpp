/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Anton Bakhov
* @idnumber 855334
* @task 1
* @compiler VC
*/
#include <string>
#include <sstream>
#include "MonsterCard.hpp"


MonsterCard::MonsterCard() : name(" "), effect(" "), attack(0), deffence(0) {}

MonsterCard::MonsterCard(string name, string effect, unsigned int attack, unsigned int deffence)
	: name(name), effect(effect), attack(attack), deffence(deffence) {}

void MonsterCard::setName(string name)
{
	this->name = name;
}

void MonsterCard::setEffect(string effect)
{
	this->effect = effect;
}

void MonsterCard::setAttack(unsigned int attack)
{
	this->attack = attack;
}

void MonsterCard::setDeffence(unsigned int deffence)
{
	this->deffence = deffence;
}

string MonsterCard::getName()
{
	return name;
}

string MonsterCard::getEffect()
{
	return effect;
}

unsigned int MonsterCard::getAttack()
{
	return attack;
}

unsigned int MonsterCard::getDeffence()
{
	return deffence;
}

string MonsterCard::getAsString()
{
	ostringstream result;
	result << name << "|" << effect << "|" << attack << "|" << deffence << "\n";
	return result.str();
}

