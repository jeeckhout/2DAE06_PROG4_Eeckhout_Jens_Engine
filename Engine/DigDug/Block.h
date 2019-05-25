#pragma once
#include "memory"
namespace dae
{
	class GameObject;
}
class TextureComponent;
enum class BlockType
{
	Air,
	Layer1,
	Layer2,
	Layer3,
	Layer4,
	Rock
};
class Block
{
public:
	Block() = default;
	~Block();
	std::shared_ptr<dae::GameObject> GetGameObject() const;
	void ChangeBlockType(BlockType type);
	void CreateObject(BlockType type);
	void UpdateTextureToFitGridSize(float width, float height);
private:
	BlockType m_Type{};
	std::shared_ptr<dae::GameObject> m_GameObj{};
	TextureComponent* m_TextComp{};
};

