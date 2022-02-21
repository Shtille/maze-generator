/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_DIRECTION_H__
#define __MAZE_DIRECTION_H__

namespace maze {
	
	/**
	 * Defines cell direction.
	 * Directions are being enumerated clockwise.
	 */
	enum class Direction : int {
		kTop,
		kRight,
		kBottom,
		kLeft
	};

} // namespace maze

#endif