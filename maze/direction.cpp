/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "direction.h"

namespace maze {

	Direction GetOppositeDirection(Direction direction)
	{
		switch (direction)
		{
		case Direction::kTop:
			return Direction::kBottom;
		case Direction::kRight:
			return Direction::kLeft;
		case Direction::kBottom:
			return Direction::kTop;
		case Direction::kLeft:
			return Direction::kRight;
		default:
			// Should not happen.
			return Direction::kTop;
		}
	}

} // namespace maze