#pragma once
namespace dae
{
	struct float3
	{
		float x{};
		float y{};
		float z{};
	};


	class Transform final
	{
		float3 mPosition{};
	public:
		const float3& GetPosition() const { return mPosition; }
		void SetPosition(float x, float y, float z);
	};
}
