#include "prim_generator.h"
#include "console_painter.h"

#include <cstdlib>
#include <cstring>

static void print_help()
{
	#define MAZE_HELP \
		"Possible options of usage:\n"\
		"- with seed:                   <app> seed\n"\
		"- with width and height:       <app> width height\n"\
		"- with width, height and seed: <app> width height seed\n"\
		"Default values: width=5, height=5, seed=1\n"
	printf(MAZE_HELP);
	#undef MAZE_HELP
}
int main(int argc, char const *argv[])
{
	int width = 5, height = 5, seed = 1;
	// Parse arguments
	if (argc == 2 && (
		strcmp(argv[1], "help") == 0 || 
		strcmp(argv[1], "-help") == 0 ||
		strcmp(argv[1], "--help") == 0))
	{
		print_help();
		return 0;
	}
	else if (argc == 4)
	{
		width = atoi(argv[1]);
		height = atoi(argv[2]);
		seed = atoi(argv[3]);
	}
	else if (argc == 3)
	{
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}
	else if (argc == 2)
	{
		seed = atoi(argv[1]);
	}

	maze::RandomizedPrimGenerator generator;
	if (!generator.Initialize(width, height))
		return 1;
	generator.Randomize(seed);
	generator.Run(maze::Position::FromExternal(0, 0));
	maze::ConsolePainter painter;
	painter.Paint(generator.matrix());
	return 0;
}