
#pragma once

using namespace std;

class MagicCard
{
public:
	enum type
	{
		trap = 0,
		buff = 1,
		spell = 2,
		Defaut = 4
	};
	MagicCard();
	MagicCard(string, string, type);

	void setName(string);
	void setEffect(string);
	void setType(type);
	
	string getName();
	string getEffect();
	type getType();

	string getAsString();

	static type of_string(string);

protected: 
	string name;
	string effect;
	type card_type;
};

