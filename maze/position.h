/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_POSITION_H__
#define __MAZE_POSITION_H__

#include "direction.h"

namespace maze {
	
	/**
	 * Defines position in matrix.
	 * 
	 * @see Matrix
	 */
	struct Position {

		/**
		 * Constructor.
		 * 
		 * @param[in] x 	The column index of the matrix.
		 * @param[in] y 	The row index of the matrix.
		 */
		Position(int x, int y);

		/**
		 * Constructs position from external point.
		 * 
		 * @param[in] x 	The column index of the maze.
		 * @param[in] y 	The row index of the maze.
		 */
		static Position FromExternal(int x, int y);

		/**
		 * Returns near position in chosen direction.
		 * 
		 * @param[in] direction 	The direction.
		 * 
		 * @return Near position.
		 */
		Position GetNearPosition(Direction direction);

		int x;
		int y;
	};

} // namespace maze

#endif