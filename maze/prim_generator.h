/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_PRIM_GENERATOR_H__
#define __MAZE_PRIM_GENERATOR_H__

#include "generator.h"
#include "wall_info.h"
#include "randomizer.h"

#include <vector>

namespace maze {
	
	/**
	 * Defines randomized Prim's generator class.
	 */
	class RandomizedPrimGenerator : public Generator {
	public:

		/**
		 * Constructor.
		 */
		RandomizedPrimGenerator();

		/**
		 * Picks another seed.
		 * 
		 * @param[in] seed 	The seed.
		 */
		void Randomize(int seed);

		/**
		 * Runs generator at start position.
		 * 
		 * @param[in] start 	The start position.
		 */
		void Run(const Position& start) override;

	private:

		std::vector<WallInfo> wall_list_;
		Randomizer randomizer_;
	};

} // namespace maze

#endif