#include "pch.h"
#include "Grid.h"
#include "GameObject.h"


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
			if (currRow > 0)
			{
				m_CurrType = BlockType::Layer1;
			}
			if (currRow > m_Rows / 4)
			{
				m_CurrType = BlockType::Layer2;
			}
			if(currRow > m_Rows / 2)
			{
				m_CurrType = BlockType::Layer3;
			}
			if(currRow > m_Rows - m_Rows / 4)
			{
				m_CurrType = BlockType::Layer4;
			}
			m_pGrid[currPos].CreateObject(m_CurrType);
			m_pGrid[currPos].GetGameObject()->SetPosition(currWidth, 0 + currHeight);
			m_pGrid[currPos].UpdateTextureToFitGridSize(m_BlockWidth,m_BlockHeight);
			m_pGameObjects.push_back(m_pGrid[currPos].GetGameObject());
			currWidth += m_BlockWidth;
		}
		currHeight += m_BlockHeight;
	}
}
