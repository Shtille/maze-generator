/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "console_painter.h"

#include <cstdio>

namespace maze {
	
	ConsolePainter::ConsolePainter()
	{
	}
	ConsolePainter::~ConsolePainter()
	{
	}
	void ConsolePainter::Paint(const Matrix& matrix)
	{
		// Enumerate cells in row-first order
		for (int j = 0; j < matrix.height(); ++j)
		{
			for (int i = 0; i < matrix.width(); ++i)
			{
				Position position(i, j);
				unsigned int value = matrix.Get(position);
				if (value == Cell::kWall)
					fputc('#', stdout);
				else if (matrix.HasFlag(position, Cell::kRoom))
					fputc(' ', stdout);
				else if (matrix.HasFlag(position, Cell::kPath))
					fputc('o', stdout);
			}
			fputc('\n', stdout);
		}
	}

} // namespace maze