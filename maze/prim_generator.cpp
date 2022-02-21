/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "prim_generator.h"

#include <cstdlib>

namespace maze {
	
	static int GetRandom(int maximum)
	{
		return std::rand() % maximum;
	}
	RandomizedPrimGenerator::RandomizedPrimGenerator()
	{

	}
	// Main algorithm:
	//   1. Start with a grid full of walls.
	//   2. Pick a cell, mark it as part of the maze. Add the walls of the cell to the wall list.
	//   3. While there are walls in the list:
	//     1. Pick a random wall from the list. If only one of the cells that the wall divides is visited, then:
	//       1. Make the wall a passage and mark the unvisited cell as part of the maze.
	//       2. Add the neighboring walls of the cell to the wall list.
	//     2. Remove the wall from the list.
	void RandomizedPrimGenerator::Run(const Position& start)
	{
		// Start with a grid full of walls.
		matrix_.Fill(Cell::kWall);
		matrix_.MakeStartRooms();
		// Pick a cell, mark it as part of the maze. Add the walls of the cell to the wall list.
		matrix_.AddFlag(start, Cell::kVisited);
		Position pos;
		for (int i = 0; i < 4; ++i)
		{
			Direction direction = static_cast<Direction>(i);
			pos = start.GetNearPosition(direction);
			if (matrix_.IsPosValid(pos))
				wall_list_.push_back(WallInfo(pos, direction));
		}
		// While there are walls in the list:
		while (!wall_list_.empty())
		{
			// Pick a random wall from the list. If only one of the cells that the wall divides is visited, then:
			int random_index = GetRandom(static_cast<int>(wall_list_.size()));
			WallInfo& wall = wall_list_[random_index];
			WallInfo next_wall = wall.GetNext();
			if (!matrix_.HasFlag(next_wall.position, Cell::kVisited))
			{
				// Make the wall a passage and mark the unvisited cell as part of the maze.
				matrix_.Set(wall.position, Cell::kRoom);
				matrix_.AddFlag(next_wall.position, Cell::kVisited);
				// Add the neighboring walls of the cell to the wall list.
				for (int i = 0; i < 4; ++i)
				{
					Direction direction = static_cast<Direction>(i);
					pos = start.GetNearPosition(direction);
					if (matrix_.IsPosValid(pos) && matrix_.Get(pos) == Cell::kWall)
						wall_list_.push_back(WallInfo(pos, direction));
				}
			}
			// Remove the wall from the list.
			wall_list_.erase(wall_list_.begin() + random_index);
		}
	}

} // namespace maze