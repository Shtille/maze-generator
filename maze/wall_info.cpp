/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "wall_info.h"

namespace maze {
	
	WallInfo::WallInfo(const Position& position, Direction direction)
	: position(position)
	, direction(direction)
	{
	}
	WallInfo WallInfo::GetNext()
	{
		Position next_position = position.GetNearPosition(direction);
		return WallInfo(next_position, direction);
	}
	WallInfo WallInfo::GetPrev()
	{
		Position prev_position = position.GetNearPosition(GetOppositeDirection(direction));
		return WallInfo(prev_position, direction);
	}

} // namespace maze