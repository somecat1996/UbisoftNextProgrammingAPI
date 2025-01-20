//---------------------------------------------------------------------------------
// GolfBall.h
// Provides functions for golf ball movement, render, and interactions with play board.
//---------------------------------------------------------------------------------
#ifndef _BALL_H
#define _BALL_H
//---------------------------------------------------------------------------------
#include <windows.h> 
#include <cmath>
#include "PlayBoard.h"
#include "Common.h"
//---------------------------------------------------------------------------------
class CGolfBall
{
public:
    // Currect position of golf ball on the play board
    int   m_column = 0;
    int   m_row = 0;
    // Target position of golf ball on the play board
    int   m_targetcolumn = 0;
    int   m_targetrow = 0;
    // Current moving direction of golf ball
    MovingDirection m_direction;
    // Play board class, contains all play board data and functions
    CPlayBoard* m_playboard;
    // Current moving status of golf ball
    MovingStatus m_status;
    //-------------------------------------------------------------------------------------------
    // CGolfBall();
    //-------------------------------------------------------------------------------------------
    // Constructor. Initialize data and asset.
    //-------------------------------------------------------------------------------------------
    CGolfBall();
    //-------------------------------------------------------------------------------------------
    // ~CGolfBall();
    //-------------------------------------------------------------------------------------------
    // Destructor. Deallocate assets.
    //-------------------------------------------------------------------------------------------
    ~CGolfBall();
    //-------------------------------------------------------------------------------------------
    // void Update(const float dt);
    //-------------------------------------------------------------------------------------------
    // Manage golf ball movement.
    //-------------------------------------------------------------------------------------------
    void Update(const float dt);
    //-------------------------------------------------------------------------------------------
    // void Draw();
    //-------------------------------------------------------------------------------------------
    // Manage golf ball and game data display.
    //-------------------------------------------------------------------------------------------
    void Draw();
    //-------------------------------------------------------------------------------------------
    // void SetPosition(int x, int y);
    //-------------------------------------------------------------------------------------------
    // Set position of golf ball on the play board.
    //-------------------------------------------------------------------------------------------
    void SetPosition(int x, int y);
    //-------------------------------------------------------------------------------------------
    // void Move(MovingDirection direction, bool countMove = false);
    //-------------------------------------------------------------------------------------------
    // Set golf ball move direction when the golf ball isn't moving and can move through the next tile.
    // Set countMove true if this move is triggered by player.
    //-------------------------------------------------------------------------------------------
    void Move(MovingDirection direction, bool countMove = false);
    //-------------------------------------------------------------------------------------------
    // void Next();
    //-------------------------------------------------------------------------------------------
    // Load next level (when player wins) or reload current level (when player fails)
    //-------------------------------------------------------------------------------------------
    void Next();

private:
    // Golf ball move speed
    float m_speed = 0.1f;
    // Ball sprite
    CSimpleSprite* m_sprite;
    // Current level
    int m_level = 0;
    // Total moves of player
    int m_currentmove;
    // Whether this level is completed
    bool m_finish;
};

#endif //_BALL_H