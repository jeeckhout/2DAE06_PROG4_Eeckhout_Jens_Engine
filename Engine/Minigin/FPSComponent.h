#pragma once
#include "BaseComponent.h"
#include "TextObject.h"

class FPSComponent final : public BaseComponent 
{
public:
	FPSComponent(dae::GameObject *parent);
	~FPSComponent();
	void Update(const float& deltaTime, float = 0, float = 0, float = 0, float = 0) override;
	void Render() override;
	void MakeFont(const std::string& fontPath, unsigned fontSize);
	void MakeFont(const std::shared_ptr<dae::Font> font);

	 FPSComponent(const  FPSComponent& other) = delete;
	 FPSComponent( FPSComponent&& other) = delete;
	 FPSComponent& operator=(const  FPSComponent& other) = delete;
	 FPSComponent& operator=(const  FPSComponent&& other) = delete;

private:
	std::string m_NumFPS{};
	std::shared_ptr<dae::Font> m_Font{ nullptr };
	dae::TextObject* m_TextObj{};

};

