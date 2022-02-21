/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "position.h"

namespace maze {
	
	Position::Position()
	: x(0)
	, y(0)
	{
	}
	Position::Position(int x, int y)
	: x(x)
	, y(y)
	{
	}
	Position::Position(const Position& other)
	: x(other.x)
	, y(other.y)
	{
	}
	Position Position::FromExternal(int x, int y)
	{
		return Position(2 * x + 1, 2 * y + 1);
	}
	void Position::operator =(const Position& other)
	{
		x = other.x;
		y = other.y;
	}
	Position Position::GetNearPosition(Direction direction) const
	{
		switch (direction)
		{
		case Direction::kLeft:
			return Position(x - 1, y);
		case Direction::kRight:
			return Position(x + 1, y);
		case Direction::kTop:
			return Position(x, y - 1);
		case Direction::kBottom:
			return Position(x, y + 1);
		}
	}

} // namespace maze