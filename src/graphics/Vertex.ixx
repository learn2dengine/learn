export module aspire.graphics.vertex;

import aspire.graphics.color;

using aspire::graphics::RgbaF;

export namespace aspire::graphics
{
	struct Vec2i
	{
		int x{};
		int y{};
	};

	struct Vec2F
	{
		float x{};
		float y{};
	};

	struct Vertex
	{
		Vec2F position{};
		RgbaF color{};
		Vec2F texCoords{};
	};
}