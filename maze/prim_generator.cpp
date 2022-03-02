/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "prim_generator.h"

namespace maze {
	
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
			int random_index = randomizer_.GetRandom(static_cast<int>(wall_list_.size()));
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
					pos = next_wall.position.GetNearPosition(direction);
					if (matrix_.IsPosValid(pos) && matrix_.Get(pos) == Cell::kWall)
						wall_list_.push_back(WallInfo(pos, direction));
				}
			}
			// Remove the wall from the list.
			wall_list_.erase(wall_list_.begin() + random_index);
		}
	}

	// Although the classical Prim's algorithm keeps a list of edges, for maze generation we could instead 
	// maintain a list of adjacent cells. If the randomly chosen cell has multiple edges that connect it to 
	// the existing maze, select one of these edges at random. This will tend to branch slightly more than 
	// the edge-based version above.
	void ModifiedPrimGenerator::Run(const Position& start)
	{
		std::vector<WallInfo> edges;

		// Start with a grid full of walls.
		matrix_.Fill(Cell::kWall);
		matrix_.MakeStartRooms();
		// Pick a cell, mark it as part of the maze. Add adjacent cells to the list.
		matrix_.AddFlag(start, Cell::kVisited);
		for (int i = 0; i < 4; ++i)
		{
			Direction direction = static_cast<Direction>(i);
			Position position = start.GetNearRoom(direction);
			if (matrix_.IsPosValid(position))
				cells_.push_back(position);
		}
		// While there are cells in the list:
		while (!cells_.empty())
		{
			// Pick a random cell from the list.
			int random_index = randomizer_.GetRandom(static_cast<int>(cells_.size()));
			Position chosen = cells_[random_index];
			if (!matrix_.HasFlag(chosen, Cell::kVisited)) // there might be duplicates in the list
			{
				// Check for edges that connect to the existing maze
				edges.clear();
				for (int i = 0; i < 4; ++i)
				{
					Direction direction = static_cast<Direction>(i);
					Position position = chosen.GetNearPosition(direction);
					WallInfo wall(position, direction);
					WallInfo next_wall = wall.GetNext();
					if (matrix_.IsPosValid(next_wall.position) && matrix_.HasFlag(next_wall.position, Cell::kVisited))
						edges.push_back(wall);
				}
				int edge_index;
				if (edges.size() > 1) // select one of these edges at random
					edge_index = randomizer_.GetRandom(static_cast<int>(edges.size()));
				else if (edges.size() == 1)
					edge_index = 0;
				else
					edge_index = -1;
				if (edge_index >= 0)
				{
					WallInfo& wall = edges[edge_index];
					//assert(wall.GetPrev() == chosen);
					// Make the wall a passage and mark the unvisited cell as part of the maze.
					matrix_.Set(wall.position, Cell::kRoom);
					matrix_.AddFlag(chosen, Cell::kVisited);
					// Add the adjacent cells to the cells list.
					for (int i = 0; i < 4; ++i)
					{
						Direction direction = static_cast<Direction>(i);
						Position position = chosen.GetNearRoom(direction);
						if (matrix_.IsPosValid(position) && !matrix_.HasFlag(position, Cell::kVisited))
							cells_.push_back(position);
					}
				}
			}
			// Remove the cell from the list.
			cells_.erase(cells_.begin() + random_index);
		}
	}

} // namespace maze