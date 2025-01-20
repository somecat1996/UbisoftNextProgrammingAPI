//---------------------------------------------------------------------------------
// PlayBoard.h
// Provides a number of basic helper functions for play board
//---------------------------------------------------------------------------------
#ifndef _BOARD_H
#define _BOARD_H
//---------------------------------------------------------------------------------
#include <windows.h> 
#include "Common.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
//---------------------------------------------------------------------------------
class CPlayBoard
{
public:
	int m_startx;
	int m_starty;
	int m_bestmoves;
	CPlayBoard(std::string fileName);
	~CPlayBoard();
	void SetValue(int row, int col, int value);
	int GetValue(int row, int col);
	void Reload(std::string fileName);

private:
	int** m_board;
	void AllocateMemory();
	void FreeMemory();
	int m_size = 10;
};


#endif