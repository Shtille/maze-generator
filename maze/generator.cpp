/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "generator.h"

namespace maze {

	Generator::Generator()
	{

	}
	Generator::~Generator()
	{

	}
	Matrix& Generator::matrix()
	{
		return matrix_;
	}
	const Matrix& Generator::matrix() const
	{
		return matrix_;
	}
	bool Generator::Initialize(int width, int height)
	{
		return matrix_.Initialize(width, height);
	}

} // namespace maze