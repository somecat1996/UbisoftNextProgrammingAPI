//---------------------------------------------------------------------------------
// Common.h
// Provides a number of basic helper functions about coordinate conversion
//---------------------------------------------------------------------------------
#ifndef _COMMON_H
#define _COMMON_H
//---------------------------------------------------------------------------------
// Global Parameters
//---------------------------------------------------------------------------------
extern int MaxMapSize;
extern int BlockSizeX;
extern int BlockSizeY;
extern float StartOffsetX;
extern float StartOffsetY;
extern float ScreenSizeX;
extern float ScreenSizeY;
//---------------------------------------------------------------------------------
// Enum about golf ball moving direction
//---------------------------------------------------------------------------------
enum MovingDirection
{
    M_Up,
    M_Down,
    M_Left,
    M_Right
};
//---------------------------------------------------------------------------------
// Enum about golf ball moving status
//---------------------------------------------------------------------------------
enum MovingStatus
{
    Moving,
    Stop
};
//---------------------------------------------------------------------------------
// Enum about tile type of play board
//---------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------
namespace Common
{
    //-------------------------------------------------------------------------------------------
    // void GetMapPosition(float x, float y, int* column, int* row);
    //-------------------------------------------------------------------------------------------
    // Convert screen position to play board position.
    //-------------------------------------------------------------------------------------------
	void GetMapPosition(float x, float y, int* column, int* row);
    //-------------------------------------------------------------------------------------------
    // void GetScreenPosition(int column, int row, float* x, float* y);
    //-------------------------------------------------------------------------------------------
    // Convert play board position to screen position.
    //-------------------------------------------------------------------------------------------
	void GetScreenPosition(int column, int row, float* x, float* y);
};

#endif //_COMMON_H
