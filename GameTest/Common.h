#pragma once


extern int MaxMapSize;
extern int BlockSizeX;
extern int BlockSizeY;
extern float StartOffsetX;
extern float StartOffsetY;
extern float ScreenSizeX;
extern float ScreenSizeY;

enum MovingDirection
{
    M_Up,
    M_Down,
    M_Left,
    M_Right
};

enum MovingStatus
{
    Moving,
    Stop
};

enum TileType
{
    Normal,
    Block,
    Start,
    Exit,
    Up,
    Down,
    Left,
    Right
};

namespace Common
{
	void GetMapPosition(float x, float y, int* column, int* row);
	void GetScreenPosition(int column, int row, float* x, float* y);
};

