///////////////////////////////////////////////////////////////////////////////
// Filename: GolfBall.cpp
// Class for golf ball movement and render
///////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "../app/app.h"
#include "GolfBall.h"
//------------------------------------------------------------------------

CGolfBall::CGolfBall(const int column = 0, const int row = 0)
{
	SetPosition(column, row);
	m_direction = Up;
	m_status = Stop;
	m_sprite = App::CreateSprite(".\\TestData\\GolfBall.png", 1, 1);
}

void CGolfBall::Update(const float dt)
{
	if (m_status == Stop)
	{

	}
	else
	{
		switch (m_direction)
		{
		case Up:
			break;
		case Down:
			break;
		case Left:
			break;
		case Right:
			break;
		default:
			break;
		}
	}
}

void CGolfBall::Draw()
{

}

bool CGolfBall::Move(MovingDirection direction)
{
	if (m_status == Stop)
	{
		m_status = Moving;
		return true;
	}
	else
	{
		return false;
	}
}