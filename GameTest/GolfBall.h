//---------------------------------------------------------------------------------
// GolfBall.h
// Provides a number of basic helper functions for golf ball movement and render
//---------------------------------------------------------------------------------
#ifndef _BALL_H
#define _BALL_H
//---------------------------------------------------------------------------------
#include <windows.h> 
#include <cmath>
#include "PlayBoard.h"
#include "Common.h"
//---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// CGolfBall
//-----------------------------------------------------------------------------
class CGolfBall
{
public:
    int   m_column = 0;
    int   m_row = 0;
    int   m_targetcolumn = 0;
    int   m_targetrow = 0;
    MovingDirection m_direction;
    CPlayBoard* m_playboard;
    MovingStatus m_status;
    CGolfBall();
    ~CGolfBall();
    void Update(const float dt);
    void Draw();
    void SetPosition(int x, int y);
    void Move(MovingDirection direction, bool countMove = false);
    void Next();

private:
    float m_speed = 0.1f;
    CSimpleSprite* m_sprite;
    int m_level = 0;
    int m_currentmove;
    bool m_finish;
};

#endif