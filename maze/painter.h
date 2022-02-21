/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_PAINTER_H__
#define __MAZE_PAINTER_H__

#include "matrix.h"

namespace maze {
	
	/**
	 * Defines abstract painter.
	 */
	class Painter {
	public:

		/**
		 * Destructor.
		 */
		virtual ~Painter() = default;

		/**
		 * Paints matrix.
		 * 
		 * @param[in] matrix 	The matrix.
		 */
		virtual void Paint(const Matrix& matrix) = 0;
	};

} // namespace maze

#endif