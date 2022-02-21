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
				if (matrix.IsWall(position))
					fputc('#', stdout);
				else if (matrix.IsPath(position))
					fputc('o', stdout);
				else if (matrix.IsRoom(position))
					fputc(' ', stdout);
			}
			fputc('\n', stdout);
		}
	}

} // namespace maze