/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_CELL_H__
#define __MAZE_CELL_H__

namespace maze {
	
	/**
	 * Defines cell type.
	 */
	enum class Cell : unsigned int {
		kWall = 0,
		kRoom = 1,
		kPath = 2,
		kVisited = 4
	};

} // namespace maze

#endif