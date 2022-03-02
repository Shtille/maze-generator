/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "backtracking_generator.h"

#include <vector>

namespace maze {

	// Main algorithm:
	//   1. Choose the initial cell, mark it as visited and push it to the stack
    //   2. While the stack is not empty
    //     1. Pop a cell from the stack and make it a current cell
    //     2. If the current cell has any neighbours which have not been visited
	//       1. Push the current cell to the stack
    //       2. Choose one of the unvisited neighbours
	//       3. Remove the wall between the current cell and the chosen cell
    //       4. Mark the chosen cell as visited and push it to the stack
	void BacktrackingGenerator::Run(const Position& start)
	{
		std::vector<Position> not_visited;

		// Start with a grid full of walls.
		matrix_.Fill(Cell::kWall);
		matrix_.MakeStartRooms();
		// Choose the initial cell, mark it as visited and push it to the stack
		matrix_.AddFlag(start, Cell::kVisited);
		stack_.push(start);
		// While the stack is not empty
		while (!stack_.empty())
		{
			// Pop a cell from the stack and make it a current cell
			Position current = stack_.top();
			stack_.pop();
			// Enumerate all unvisited neighbours
			not_visited.clear();
			for (int i = 0; i < 4; ++i)
			{
				Direction direction = static_cast<Direction>(i);
				Position position = current.GetNearRoom(direction);
				if (matrix_.IsPosValid(position) && !matrix_.HasFlag(position, Cell::kVisited))
				{
					not_visited.push_back(position);
				}
			}
			// If the current cell has any neighbours which have not been visited
			if (!not_visited.empty())
			{
				// Push the current cell to the stack
				stack_.push(current);
				// Choose one of the unvisited neighbours
				int random_index = randomizer_.GetRandom(static_cast<int>(not_visited.size()));
				Position chosen = not_visited[random_index];
				// Remove the wall between the current cell and the chosen cell
				Position wall_position = Position::GetBetween(current, chosen);
				matrix_.Set(wall_position, Cell::kRoom);
				// Mark the chosen cell as visited and push it to the stack
				matrix_.AddFlag(chosen, Cell::kVisited);
				stack_.push(chosen);
			}
		}
	}

} // namespace maze