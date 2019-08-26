#pragma once
#include "Block.h"

namespace dae
{
	class GameObject;
}
#include "vector"
#include "memory"
class Grid
{
public:
	Grid(float Width, float Height, int rows, int cols);
	~Grid();
	std::vector<std::shared_ptr<dae::GameObject>> GetGameObjects() const;
	Block* GetGrid() const;

private:
	Block* m_pGrid{};
	BlockType m_CurrType{BlockType::Air};
	float m_TotWidth{};
	float m_TotHeight{};
	float m_BlockHeight{};
	float m_BlockWidth{};
	int m_Rows{};
	int m_Cols{};
	void CreateGrid();
	std::vector<std::shared_ptr<dae::GameObject>> m_pGameObjects{};
};

