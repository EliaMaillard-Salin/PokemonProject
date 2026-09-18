#ifndef COMBAT_ENTITY_H
#define COMBAT_ENTITY_H

#include "EngineFramework.h"
#include <array>

class Challenger : public GameObject
{
	// Action : Item, Attack, Flee, ChangeActivePokemon
	Challenger();
	
	void ChangeActivePokemon(std::uint8_t newPokemon);
	void Attack(std::uint8_t attackID);

	//void UseItem(Item);
	void Flee();

private:
	// Inventory ?
	bool m_isActivePlayer;
	// std::array<Pokemon, 6> m_pokemonTeam;

};

#endif
