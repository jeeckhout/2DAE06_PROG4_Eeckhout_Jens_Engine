#include "pch.h"
#include "Grid.h"
#include "GameObject.h"
#include "TypeComponent.h"


Grid::Grid(float Width, float Height, int rows, int cols) : m_TotWidth(Width)
,m_TotHeight(Height)
,m_Rows(rows)
,m_Cols(cols)
{
	CreateGrid();
}

Grid::~Grid()
{
	delete[] m_pGrid;
	m_pGrid = nullptr;
}

std::vector<std::shared_ptr<dae::GameObject>> Grid::GetGameObjects() const
{
	return m_pGameObjects;
}

Block* Grid::GetGrid() const
{
	return m_pGrid;
}

void Grid::CreateGrid()
{
	m_BlockHeight = m_TotHeight / m_Rows;
	m_BlockWidth = m_TotWidth / m_Cols;
	m_pGrid = new Block[m_Cols * m_Rows]{};
	float currHeight{};
	for(int currRow = 0; currRow < m_Rows; ++currRow)
	{
		float currWidth{};
		for (int currCol = 0; currCol < m_Cols; ++currCol)
		{
			int currPos = (currRow * m_Cols) + currCol;

			m_pGrid[currPos].CreateObject(m_CurrType);

			TypeComponent* pType = nullptr;

			switch (m_CurrType)
			{
				case BlockType::Air:
				pType = new TypeComponent{m_pGrid[currPos].GetGameObject().get(),GameObjectType::AirBlock};
				break;

				case BlockType::Wire:
				pType = new TypeComponent{m_pGrid[currPos].GetGameObject().get(),GameObjectType::Wire};

				case BlockType::Crystal:
				pType = new TypeComponent{m_pGrid[currPos].GetGameObject().get(),GameObjectType::SpecialBlock};
				break;

				case BlockType::EggBlock:
				pType = new TypeComponent{m_pGrid[currPos].GetGameObject().get(),GameObjectType::EggBlock};
				break;

				case BlockType::IceBlock:
				pType = new TypeComponent{m_pGrid[currPos].GetGameObject().get(),GameObjectType::IceBlock};
				break;
			}

			m_pGrid[currPos].GetGameObject()->SetPosition(currWidth, 0 + currHeight);
			m_pGrid[currPos].GetGameObject()->AddComponentToVector(pType);
			m_pGrid[currPos].UpdateTextureToFitGridSize(m_BlockWidth,m_BlockHeight);
			m_pGameObjects.push_back(m_pGrid[currPos].GetGameObject());
			currWidth += m_BlockWidth;
		}
		currHeight += m_BlockHeight;
	}
}
