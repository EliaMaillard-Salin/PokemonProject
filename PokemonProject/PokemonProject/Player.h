#pragma once
#include "EngineFramework.h"

class Player : public GameObject
{
public:
	Player();
	virtual ~Player();

	void Update() override;

private:
	void HandleMovement();


};

