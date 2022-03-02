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
		 */
		Position();

		/**
		 * Constructor.
		 * 
		 * @param[in] x 	The column index of the matrix.
		 * @param[in] y 	The row index of the matrix.
		 */
		Position(int x, int y);

		/**
		 * Copy constructor.
		 * 
		 * @param[in] other 	The object to copy from.
		 */
		Position(const Position& other);

		/**
		 * Constructs position from external point.
		 * 
		 * @param[in] x 	The column index of the maze.
		 * @param[in] y 	The row index of the maze.
		 */
		static Position FromExternal(int x, int y);

		/**
		 * Assignment operator overload.
		 * 
		 * @param[in] other 	The object to assign from.
		 */
		void operator =(const Position& other);

		/**
		 * Returns near position in chosen direction.
		 * 
		 * @param[in] direction 	The direction.
		 * 
		 * @return Near position.
		 */
		Position GetNearPosition(Direction direction) const;

		/**
		 * Returns near room in chosen direction.
		 * The same as GetNearPosition, but distance is doubled.
		 * 
		 * @param[in] direction 	The direction.
		 * 
		 * @return Near room.
		 * @see GetNearPosition
		 */
		Position GetNearRoom(Direction direction) const;

		/**
		 * Returns a position between two.
		 * 
		 * @param[in] first 	The first position.
		 * @param[in] second 	The second position.
		 * 
		 * @return Between position.
		 */
		static Position GetBetween(const Position& first, const Position& second);

		int x;
		int y;
	};

} // namespace maze

#endif