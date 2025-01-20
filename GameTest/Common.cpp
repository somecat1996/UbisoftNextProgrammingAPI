#include "stdafx.h"
#include "Common.h"

namespace Common
{
	int MaxMapSize = 10;
	int BlockSizeX = 40;
	int BlockSizeY = 20;
	float StartOffsetX = 330.0f;
	float StartOffsetY = 100.0f;
	float ScreenSizeX = 1020.0f;
	float ScreenSizeY = 770.0f;
	void GetMapPosition(float x, float y, int* column, int* row)
	{
		*column = (x - StartOffsetX) / BlockSizeX;
		*row = (ScreenSizeY - StartOffsetY - y) / BlockSizeY;
	}

	void GetScreenPosition(int column, int row, float* x, float* y)
	{
		*x = StartOffsetX + column * BlockSizeX;
		*y = ScreenSizeY - StartOffsetY - row * BlockSizeY;
	}
}
