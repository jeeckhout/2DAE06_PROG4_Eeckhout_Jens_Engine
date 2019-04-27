#pragma once
#include "BaseComponent.h"
#include "TextObject.h"
class dae::GameObject;
class dae::Font;
class Texture2D;

class FPSComponent final : public BaseComponent 
{
public:
	FPSComponent(dae::GameObject *parent);
	~FPSComponent();
	void Update(float deltaTime) override;
	void Render() const;
	void MakeFont(const std::string& fontPath, unsigned fontSize);
	void MakeFont(const std::shared_ptr<dae::Font> font);
private:
	std::string m_NumFPS{};
	std::shared_ptr<dae::Font> m_Font{ nullptr };
	dae::TextObject* m_TextObj{};

};

