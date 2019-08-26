#pragma once
#include "BaseComponent.h"

enum class GameObjectType
{
	Player,
	Snowbee,
	IceBlock,
	EggBlock,
	SpecialBlock,
	AirBlock,
	Wire
};
class TypeComponent :
	public BaseComponent
{
public:
	TypeComponent(dae::GameObject *parent, GameObjectType type);
	~TypeComponent() = default;
	GameObjectType GetType();
	void SetType(GameObjectType newType);
	void Update(const float&, float, float, float, float) override {;};
	void Render() override{;};
private:
	GameObjectType m_Type;
};

