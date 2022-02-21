/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#ifndef __MAZE_CONSOLE_PAINTER_H__
#define __MAZE_CONSOLE_PAINTER_H__

#include "painter.h"

namespace maze {
	
	/**
	 * Defines console painter.
	 */
	class ConsolePainter : public Painter {
	public:

		/**
		 * Constructor.
		 */
		ConsolePainter();

		/**
		 * Destructor.
		 */
		~ConsolePainter();

		/**
		 * Paints matrix.
		 * 
		 * @param[in] matrix 	The matrix.
		 */
		void Paint(const Matrix& matrix) override;
	};

} // namespace maze

#endif