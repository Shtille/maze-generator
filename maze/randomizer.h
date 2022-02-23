/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_RANDOMIZER_H__
#define __MAZE_RANDOMIZER_H__

namespace maze {
	
	/**
	 * Defines randomizer.
	 */
	class Randomizer {
	public:

		/**
		 * Constructor.
		 */
		Randomizer();

		/**
		 * Picks another seed.
		 * 
		 * @param[in] seed 	The seed.
		 */
		void SetSeed(int seed);

		/**
		 * Gets random value from range [0; maximum].
		 * 
		 * @param[in] maximum 	The maximum value.
		 * 
		 * @return The random value.
		 */
		int GetRandom(int maximum);
	};

} // namespace maze

#endif