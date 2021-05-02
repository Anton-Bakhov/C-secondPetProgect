
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Duelist.hpp"

Duelist::Duelist(string name)
{
	this->name = name;
}

Deck Duelist::getDeck()
{
	return this->deck;
}

bool Duelist::writeDeckToFile(string filename)
{
	fstream file;
	file.open(filename, fstream::out);
	if (file.is_open()) {
		ostringstream file_header;
		file_header << deck.getName() << "|" << deck.capacityOfMonsters() << "|" << deck.capacityOfMagics() << "|" << deck.capacityOfPendulums() << "\n";
		string file_str = file_header.str().append(deck.getDeckAsString());
		file << file_str;
		file.close();
		return true;
	}
	return false;
}

bool Duelist::updateDeckfromFile(string filename)
{
	ifstream file;
	file.open(filename, fstream::in);
	if (file.is_open())
	{
		string line;
		int line_counter = 0;
		int monster_cards_count = 0;
		int magic_cards_count = 0;
		int pendulum_cards_count = 0;
		while (getline(file, line))
		{
			if (line_counter == 0) {
				string* first_line_tokens = parseFirstLine(line);
				deck.setName(first_line_tokens[0]);
				monster_cards_count = stoi(first_line_tokens[1]);
				magic_cards_count = stoi(first_line_tokens[2]);
				pendulum_cards_count = stoi(first_line_tokens[3]);
				line_counter++;
				continue;
			}
			if (line_counter < monster_cards_count + 1)
			{
				MonsterCard card = parseMonsterCardLine(line);
				deck.addMonster(card);
			}
			else if (line_counter < monster_cards_count + magic_cards_count + 1)
			{
				MagicCard card = parseMagicCardLine(line);
				deck.addMagic(card);
			}
			else if (line_counter < monster_cards_count + magic_cards_count + pendulum_cards_count + 1)
			{
				PendulumCard card = parsePendulumCardLine(line);
				deck.addPendulum(card);
			}
			line_counter++;
		}
		return true;
	}
	return false;
}

string* Duelist::parseFirstLine(string line)
{
	string delimiter = "|";
	string tokens[4];
	tokens[0] = line.substr(0, line.find(delimiter));
	for (int i = 0; i < 4; i++) {
		int position = line.find(delimiter);
		tokens[i] = line.substr(0, position);
		line = line.substr(position + 1, line.size());
	}
	return tokens;
}

MonsterCard Duelist::parseMonsterCardLine(string line)
{
	string delimiter = "|";
	string tokens[4];
	tokens[0] = line.substr(0, line.find(delimiter));
	for (int i = 0; i < 4; i++) {
		int position = line.find(delimiter);
		tokens[i] = line.substr(0, position);
		line = line.substr(position + 1, line.size());
	}
	MonsterCard card(tokens[0], tokens[1], stoi(tokens[2]), stoi(tokens[3]));
	return card;
}

MagicCard Duelist::parseMagicCardLine(string line)
{
	string delimiter = "|";
	string tokens[3];
	tokens[0] = line.substr(0, line.find(delimiter));
	for (int i = 0; i < 3; i++) {
		int position = line.find(delimiter);
		tokens[i] = line.substr(0, position);
		line = line.substr(position + 1, line.size());
	}
	MagicCard card(tokens[0], tokens[1], MagicCard::of_string(tokens[2]));
	return card;
}

PendulumCard Duelist::parsePendulumCardLine(string line)
{
	string delimiter = "|";
	string tokens[6];
	tokens[0] = line.substr(0, line.find(delimiter));
	for (int i = 0; i < 6; i++) {
		int position = line.find(delimiter);
		tokens[i] = line.substr(0, position);
		line = line.substr(position + 1, line.size());
	}
	PendulumCard card;
	card.MonsterCard::setName(tokens[0]);
	card.MonsterCard::setEffect(tokens[1]);
	card.setAttack(stoi(tokens[2]));
	card.setDeffence(stoi(tokens[3]));
	card.setPendulum(stoi(tokens[4]));
	card.setType(MagicCard::of_string(tokens[5]));

	return card;
}
