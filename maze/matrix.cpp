/**
 * Copyright (c) 2022, Vladimir Sviridov <v.shtille@gmail.com>.
 * Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
 */

#include "matrix.h"

#include <assert.h>

namespace maze {
	
	Matrix::Matrix()
	: matrix_(nullptr)
	, width_(0)
	, height_(0)
	{

	}
	Matrix::~Matrix()
	{
		Deinitialize();
	}
	int Matrix::width() const
	{
		return width_;
	}
	int Matrix::height() const
	{
		return height_;
	}
	bool Matrix::Initialize(int width, int height)
	{
		if (width <= 0 || height <= 0)
			return false;

		// We need to recalculate width and height since we store walls in cells
		width_ = 2 * width + 1;
		height_ = 2 * height + 1;
		matrix_ = new unsigned int*[width_];
		if (matrix_ == nullptr)
			return false;
		for (int i = 0; i < width_; ++i)
		{
			matrix_[i] = new unsigned int[height_];
			if (matrix_[i] == nullptr)
			{
				// Bad allocation
				for (int j = i-1; j >= 0; --j)
				{
					delete[] matrix_[j];
				}
				delete[] matrix_;
				matrix_ = nullptr;
				return false;
			}
		}
		return true;
	}
	void Matrix::Deinitialize()
	{
		if (matrix_ != nullptr)
		{
			for (int i = 0; i < width_; ++i)
			{
				delete[] matrix_[i];
			}
			delete[] matrix_;
			matrix_ = nullptr;
		}
	}
	void Matrix::Fill(unsigned int value)
	{
		for (int i = 0; i < width_; ++i)
		{
			for (int j = 0; j < height_; ++j)
			{
				matrix_[i][j] = value;
			}
		}
	}
	void Matrix::MakeStartRooms()
	{
		for (int i = 0; i < width_; ++i)
		{
			for (int j = 0; j < height_; ++j)
			{
				// Set room if i and j are odd
				if ((i % 2) != 0 && (j % 2) != 0)
					matrix_[i][j] = Cell::kRoom;
			}
		}
	}
	void Matrix::Set(const Position& pos, unsigned int value)
	{
		assert(0 <= pos.x && pos.x < width_);
		assert(0 <= pos.y && pos.y < height_);

		matrix_[pos.x][pos.y] = value;
	}
	unsigned int Matrix::Get(const Position& pos) const
	{
		assert(0 <= pos.x && pos.x < width_);
		assert(0 <= pos.y && pos.y < height_);

		return matrix_[pos.x][pos.y];
	}
	bool Matrix::IsPosValid(const Position& pos) const
	{
		// Exclude walls
		return 0 < pos.x && pos.x < width_-1 &&
			   0 < pos.y && pos.y < height_-1;
	}
	void Matrix::AddFlag(const Position& pos, Cell flag)
	{
		assert(0 <= pos.x && pos.x < width_);
		assert(0 <= pos.y && pos.y < height_);

		matrix_[pos.x][pos.y] |= flag;
	}
	void Matrix::RemoveFlag(const Position& pos, Cell flag)
	{
		assert(0 <= pos.x && pos.x < width_);
		assert(0 <= pos.y && pos.y < height_);

		matrix_[pos.x][pos.y] &= ~flag;
	}
	bool Matrix::HasFlag(const Position& pos, Cell flag)
	{
		assert(0 <= pos.x && pos.x < width_);
		assert(0 <= pos.y && pos.y < height_);

		return (matrix_[pos.x][pos.y] & flag) == flag;
	}

} // namespace maze