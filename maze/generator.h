/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_GENERATOR_H__
#define __MAZE_GENERATOR_H__

#include "matrix.h"

namespace maze {
	
	/**
	 * Defines abstract generator class.
	 */
	class Generator {
	public:

		/**
		 * Constructor.
		 */
		Generator();

		/**
		 * Destructor.
		 */
		virtual ~Generator();

		/**
		 * Returns matrix.
		 */
		Matrix& matrix();

		/**
		 * Returns matrix. Const version.
		 */
		const Matrix& matrix() const;

		/**
		 * Initializes generator's matrix.
		 * 
		 * @param[in] width 	The width of matrix.
		 * @param[in] height 	The height of matrix.
		 */
		bool Initialize(int width, int height);

		/**
		 * Runs generator at start position.
		 * 
		 * @param[in] start 	The start position.
		 */
		virtual void Run(const Position& start) = 0;

	protected:

		Matrix matrix_;
	};

} // namespace maze

#endif