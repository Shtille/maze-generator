/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "randomizer.h"

#include <cstdlib>

namespace maze {

	Randomizer::Randomizer()
	{
	}
	void Randomizer::Randomize(int seed)
	{
		std::srand(seed);
	}
	int Randomizer::GetRandom(int maximum)
	{
		return std::rand() % maximum;
	}

} // namespace maze