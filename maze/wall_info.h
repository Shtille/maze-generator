/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_WALL_INFO_H__
#define __MAZE_WALL_INFO_H__

#include "position.h"
#include "direction.h"

namespace maze {
	
	/**
	 * Defines wall information for maze generation.
	 * Contains direction information to find next wall/room.
	 */
	struct WallInfo {

		/**
		 * Constructor.
		 * 
		 * @param[in] position 		The wall position in matrix.
		 * @param[in] direction 	The dig direction.
		 */
		WallInfo(const Position& position, Direction direction);

		/**
		 * Returns next position in the picked direction.
		 */
		WallInfo GetNext();

		/**
		 * Returns previous position in the picked direction.
		 */
		WallInfo GetPrev();

		Position position;
		Direction direction;
	};

} // namespace maze

#endif