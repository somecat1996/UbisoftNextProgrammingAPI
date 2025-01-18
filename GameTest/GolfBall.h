//---------------------------------------------------------------------------------
// GolfBall.h
// Provides a number of basic helper functions for golf ball movement and render
//---------------------------------------------------------------------------------
#ifndef _BALL_H
#define _BALL_H
//---------------------------------------------------------------------------------
#include <windows.h> 
//---------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// CGolfBall
//-----------------------------------------------------------------------------
class CGolfBall
{
public:
    CGolfBall(const int column = 0, const int row = 0);
    void Update(const float dt);
    void Draw();
    void SetPosition(const int x, const int y) { m_column = x; m_row = y; }

private:
    int   m_column = 0;
    int   m_row = 0;
};

#endif