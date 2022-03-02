/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_PRIM_GENERATOR_H__
#define __MAZE_PRIM_GENERATOR_H__

#include "generator.h"
#include "wall_info.h"

#include <vector>

namespace maze {
	
	/**
	 * Defines randomized Prim's generator.
	 * Uses random, so use Randomize function to set seed.
	 */
	class RandomizedPrimGenerator : public Generator {
	public:

		/**
		 * Runs generator at start position.
		 * 
		 * @param[in] start 	The start position.
		 */
		void Run(const Position& start) override;

	private:

		std::vector<WallInfo> wall_list_;
	};

	/**
	 * Defines modified Prim's generator.
	 * Uses list of adjacent cells instead of list of edges.
	 * Uses random, so use Randomize function to set seed.
	 */
	class ModifiedPrimGenerator : public Generator {
	public:

		/**
		 * Runs generator at start position.
		 * 
		 * @param[in] start 	The start position.
		 */
		void Run(const Position& start) override;

	private:

		std::vector<Position> cells_;
	};

} // namespace maze

#endif