/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_MATRIX_H__
#define __MAZE_MATRIX_H__

#include "cell.h"
#include "position.h"

namespace maze {
	
	/**
	 * Defines matrix for walls/rooms data.
	 * Positive x is right, positive y is down.
	 */
	class Matrix {
	public:

		/**
		 * Constructor.
		 */
		Matrix();

		/**
		 * Destructor.
		 */
		~Matrix();

		/**
		 * Returns width of matrix.
		 */
		int width() const;

		/**
		 * Returns height of matrix.
		 */
		int height() const;

		/**
		 * Initializes matrix with passed sizes.
		 * After initialization maze needs to be filled.
		 * 
		 * @param[in] width 	The width of matrix.
		 * @param[in] height 	The height of matrix.
		 * 
		 * @return True if success and false otherwise.
		 * 
		 * @see Fill
		 */
		bool Initialize(int width, int height);

		/**
		 * Fills matrix with value.
		 * 
		 * @param[in] value 	The value to fill.
		 */
		void Fill(unsigned int value);

		/**
		 * Make start rooms at odd positions.
		 */
		void MakeStartRooms();

		/**
		 * Sets value to specific position in matrix.
		 * 
		 * @param[in] pos 		The position of cell.
		 * @param[in] value 	The value of cell.
		 */
		void Set(const Position& pos, unsigned int value);

		/**
		 * Gets value from specific position in matrix.
		 * 
		 * @param[in] pos 		The position of cell.
		 * 
		 * @return Value of cell.
		 */
		unsigned int Get(const Position& pos) const;

		/**
		 * Checks if position is valid.
		 * 
		 * @param[in] pos 		The position of cell.
		 * 
		 * @return True if valid and false otherwise.
		 */
		bool IsPosValid(const Position& pos) const;

		/**
		 * Adds flag at specified position.
		 * 
		 * @param[in] pos 		The position of cell.
		 * @param[in] flag 		The flag to add.
		 */
		void AddFlag(const Position& pos, unsigned int flag);

		/**
		 * Remove flag at specified position.
		 * 
		 * @param[in] pos 		The position of cell.
		 * @param[in] flag 		The flag to remove.
		 */
		void RemoveFlag(const Position& pos, unsigned int flag);

		/**
		 * Checks if matrix has flag set at position.
		 * 
		 * @param[in] pos 		The position of cell.
		 * @param[in] flag 		The flag to check.
		 * 
		 * @return True if success and false otherwise.
		 */
		bool HasFlag(const Position& pos, unsigned int flag);

	private:

		/**
		 * Deinitializes matrix.
		 * 
		 * @see Initialize
		 * @private
		 */
		void Deinitialize();

		unsigned int **matrix_;
		int width_;
		int height_;
	};

} // namespace maze

#endif