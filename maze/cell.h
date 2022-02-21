/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_CELL_H__
#define __MAZE_CELL_H__

namespace maze {
	
	/**
	 * Defines cell constants.
	 */
	struct Cell {
		static constexpr unsigned int kWall = 0;
		static constexpr unsigned int kRoom = 1;
		static constexpr unsigned int kPath = 2;
		static constexpr unsigned int kVisited = 4;
	};

} // namespace maze

#endif