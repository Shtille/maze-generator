#include "prim_generator.h"
#include "console_painter.h"

#include <iostream>
#include <cstring>

static void print_help(const char* name)
{
	std::cout << "Usage: " << name << " <option(s)>\n"
		<< "Options:\n"
		<< "\t   --help\t\tShow this help message\n"
		<< "\t-w,--width\t\tSpecify the width of the maze\n"
		<< "\t-h,--height\t\tSpecify the height of the maze\n"
		<< "\t-s,--seed\t\tSpecify the seed for random\n"
		<< std::endl;
}
int main(int argc, char const *argv[])
{
	int width = 5, height = 5, seed = 1;

	// Parse arguments
	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "--help") == 0)
		{
			print_help(argv[0]);
			return 0;
		}
		else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--width") == 0)
		{
			if (i+1 < argc)
				width = atoi(argv[++i]);
			else
			{
				std::cout << argv[i] << " option requires an argument" << std::endl;
				return 1;
			}
		}
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--height") == 0)
		{
			if (i+1 < argc)
				height = atoi(argv[++i]);
			else
			{
				std::cout << argv[i] << " option requires an argument" << std::endl;
				return 1;
			}
		}
		else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--seed") == 0)
		{
			if (i+1 < argc)
				seed = atoi(argv[++i]);
			else
			{
				std::cout << argv[i] << " option requires an argument" << std::endl;
				return 1;
			}
		}
		else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--type") == 0)
		{
			// TODO
			std::cout << argv[i] << " option is no implemented yet" << std::endl;
			return 1;
		}
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