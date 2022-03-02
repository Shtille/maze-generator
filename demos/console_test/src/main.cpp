#include "prim_generator.h"
#include "backtracking_generator.h"

#include "console_painter.h"

#include <iostream>
#include <cstring>
#include <memory>

static const char* kTypeRandomizedPrim = "prim";
static const char* kTypeModifiedPrim = "modprim";
static const char* kTypeBacktracking = "backtrack";

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
static void wait_for_input_on_windows()
{
#if defined(_WIN64) || defined(_WIN32)
	::system("pause");
#endif
}
int main(int argc, char const *argv[])
{
	// List of available types:
	char const * types[] = {
		kTypeRandomizedPrim,
		kTypeModifiedPrim,
		kTypeBacktracking
	};
	std::unique_ptr<maze::Generator> generator;
	int width = 5, height = 5, seed = 1;
	char const * type = nullptr;

	// Parse arguments
	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "--help") == 0)
		{
			if (i+1 < argc) // specialized help
			{
				++i;
				if (strcmp(argv[i], "t") == 0 || strcmp(argv[i], "type") == 0) // help for type
				{
					std::cout << "List of available types:" << std::endl;
					for (int j = 0; j < sizeof(types)/sizeof(types[0]); ++j)
					{
						std::cout << "- " << types[j] << std::endl;
					}
					return 0;
				}
				else
				{
					std::cout << "Argument '" << argv[i] << "' is unknown" << std::endl;
					return 1;
				}
			}
			else
			{
				print_help(argv[0]);
				return 0;
			}
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
			if (i+1 < argc)
				type = argv[++i];
			else
			{
				std::cout << argv[i] << " option requires an argument" << std::endl;
				return 1;
			}
		}
	}

	// Create generator depending on the chosen type
	if (type == nullptr) // the type is not set
	{
		// Use default type
		generator = std::make_unique<maze::RandomizedPrimGenerator>();
	}
	else if (strcmp(type, kTypeRandomizedPrim) == 0)
	{
		generator = std::make_unique<maze::RandomizedPrimGenerator>();
	}
	else if (strcmp(type, kTypeModifiedPrim) == 0)
	{
		generator = std::make_unique<maze::ModifiedPrimGenerator>();
	}
	else if (strcmp(type, kTypeBacktracking) == 0)
	{
		generator = std::make_unique<maze::BacktrackingGenerator>();
	}
	else // unknown type
	{
		std::cout << "Type '" << type << "' is unknown" << std::endl;
		return 1;
	}

	// Initialize matrix
	if (!generator->Initialize(width, height))
		return 1;

	// Run the generator
	generator->Randomize(seed);
	generator->Run(maze::Position::FromExternal(0, 0));

	// Paint the maze
	maze::ConsolePainter painter;
	painter.Paint(generator->matrix());

	// Wait for user input (Windows only)
	wait_for_input_on_windows();
	return 0;
}