
#include <iostream>
#include <string>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Duelist.hpp"
#include "Deck.hpp"


int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction", 3000, 2500);

	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);

	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", MagicCard::type::spell);

	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", MagicCard::type::trap);

	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 1200, 600, MagicCard::type(2), 8 );

	Duelist firstDuelist("Ivan Ivanov");

	firstDuelist.getDeck().setName("Magician Deck");

	firstDuelist.getDeck().addMonster(dragon);
	firstDuelist.getDeck().addMagic(swords);
	firstDuelist.getDeck().addMonster(magician);
	firstDuelist.getDeck().addMagic(cylinder);
	firstDuelist.getDeck().addPendulum(timegazer);
	firstDuelist.writeDeckToFile("magician_deck.txt");
	firstDuelist.updateDeckfromFile("magician_deck.txt");
	cout << firstDuelist.getDeck().getDeckAsString();
	MagicCard box("Mystic Box", "Destroy one monster.", MagicCard::type::spell);
	

	return 0;
}