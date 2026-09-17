#pragma once
#include "EngineFramework.h"

class Player : public GameObject, public MeshComponent, public RigidBody, public Collider
{
public:
	Player();
	virtual ~Player();

	void Update() override;

	Vector2 GetDrawingPosition() const override;
	Vector2 GetDrawingSize() const override;

	Vector2 GetMovePosition() const override;
	void SetMovePosition(Vector2 newPos) override;

private:
	void HandleMovement();


};

