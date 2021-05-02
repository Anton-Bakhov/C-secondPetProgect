
#pragma once

using namespace std;

class MonsterCard
{
public:
	MonsterCard();
	MonsterCard(string, string, unsigned int, unsigned int);

	void setName(string);
	void setEffect(string);
	void setAttack(unsigned int);
	void setDeffence(unsigned int);

	string getName();
	string getEffect();
	unsigned int getAttack();
	unsigned int getDeffence();

	string getAsString();

protected:
	string name;
	string effect;
	unsigned int attack;
	unsigned int deffence;
};

