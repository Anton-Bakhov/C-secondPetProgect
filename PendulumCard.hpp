#pragma once

using namespace std;

class PendulumCard : public MagicCard, public MonsterCard
{
public:
	PendulumCard();
	PendulumCard(string, string, unsigned int, unsigned int, type, unsigned short int);

	void setPendulum(unsigned short int);

	unsigned short int getPendulum();

	string getAsString();

private:
	unsigned short int pendulum;

};

