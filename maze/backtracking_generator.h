/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_BACKTRACKING_GENERATOR_H__
#define __MAZE_BACKTRACKING_GENERATOR_H__

#include "generator.h"

#include <stack>

namespace maze {
	
	/**
	 * Defines backtracking (depth-first search) generator with iterative implementation.
	 * Uses random, so use Randomize function to set seed.
	 */
	class BacktrackingGenerator : public Generator {
	public:

		/**
		 * Runs generator at start position.
		 * 
		 * @param[in] start 	The start position.
		 */
		void Run(const Position& start) override;

	private:

		std::stack<Position> stack_;
	};

} // namespace maze

#endif