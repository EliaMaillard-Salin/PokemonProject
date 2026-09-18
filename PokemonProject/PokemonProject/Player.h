#pragma once
#include "EngineFramework.h"

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	void Update() override;

	void EncounterEnemy();

private:
	void HandleMovement();

private:
	bool m_isInCombat;
	// Enemy
};

