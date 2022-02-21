#include "prim_generator.h"
#include "console_painter.h"

#include <cstdio>

int main(int argc, char const *argv[])
{
	const int kWidth = 5;
	const int kHeight = 5;
	maze::RandomizedPrimGenerator generator;
	if (!generator.Initialize(kWidth, kHeight))
		return 1;
	generator.Run(maze::Position::FromExternal(0, 0));
	maze::ConsolePainter painter;
	painter.Paint(generator.matrix());
	(void)getc(stdin);
	return 0;
}