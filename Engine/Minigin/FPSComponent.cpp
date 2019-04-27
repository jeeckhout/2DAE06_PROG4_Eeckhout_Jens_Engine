#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "Font.h"


FPSComponent::FPSComponent(dae::GameObject * parent) : BaseComponent(parent)
, m_Font(nullptr)
, m_TextObj(nullptr)
{
}

FPSComponent::~FPSComponent()
{
	delete m_TextObj;
}

void FPSComponent::Update(float deltaTime)
{
	int fps = int(1/deltaTime);
	m_NumFPS = std::to_string(fps);
	m_TextObj->SetText(m_NumFPS);
	m_TextObj->Update(deltaTime);
}

void FPSComponent::Render() const
{
	m_TextObj->Render();
}

void FPSComponent::MakeFont(const std::string& fontPath, unsigned fontSize)
{
	m_Font = std::make_shared<dae::Font>(fontPath, fontSize);
	m_TextObj = new dae::TextObject{ m_NumFPS,m_Font };
	m_TextObj->SetPosition(10, 100);
}

void FPSComponent::MakeFont(const std::shared_ptr<dae::Font> font)
{
	m_Font = font;
	m_TextObj = new dae::TextObject{ m_NumFPS,m_Font };
	m_TextObj->SetPosition(10, 100);
}
