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
CGolfBall::CGolfBall()
{
	// Initialize data
	m_direction = MovingDirection::M_Up;
	m_status = Stop;
	m_currentmove = 0;
	m_finish = false;

	// Initialize sprite
	m_sprite = App::CreateSprite(".\\TestData\\GolfBall.png", 1, 1);

	// Initialize play board
	m_playboard = new CPlayBoard(".\\TestData\\level" + std::to_string(m_level) + ".txt");
	SetPosition(m_playboard->m_startx, m_playboard->m_starty);
}

CGolfBall::~CGolfBall()
{
	delete m_sprite;
}

void CGolfBall::Update(const float dt)
{
	float x, y;
	if (m_status == Stop)
	{
		Common::GetScreenPosition(m_column, m_row, &x, &y);
		m_sprite->SetPosition(x, y);
	}
	else
	{
		// Move golf ball
		m_sprite->GetPosition(x, y);
		switch (m_direction)
		{
		case MovingDirection::M_Up:
			y += m_speed * dt;
			break;
		case MovingDirection::M_Down:
			y -= m_speed * dt;
			break;
		case MovingDirection::M_Left:
			x -= m_speed * dt;
			break;
		case MovingDirection::M_Right:
			x += m_speed * dt;
			break;
		default:
			break;
		}
		// Check whether golf ball reaches next tile
		m_sprite->SetPosition(x, y);
		float targetX, targetY;
		Common::GetScreenPosition(m_targetcolumn, m_targetrow, &targetX, &targetY);
		if ((x - targetX) * (x - targetX) + (y - targetY) * (y - targetY) < 0.1f)
		{
			SetPosition(m_targetcolumn, m_targetrow);
			int currentTile = m_playboard->GetValue(m_targetcolumn, m_targetrow);

			m_status = Stop;
			// Change golf ball move direction based on current tile
			switch (currentTile)
			{
			case 0:
				Move(m_direction);
				break;
			case 1:
				break;
			case 2:
				Move(m_direction);
				break;
			case 3:
				// Level complete if golf ball reaches target
				m_finish = true;
				break;
			case 4:
				Move(MovingDirection::M_Up);
				break;
			case 5:
				Move(MovingDirection::M_Down);
				break;
			case 6:
				Move(MovingDirection::M_Left);
				break;
			case 7:
				Move(MovingDirection::M_Right);
				break;
			default:
				break;
			}
		}
	}
}

void CGolfBall::Draw()
{
	// Draw ball sprite
	m_sprite->Draw();

	// Draw game info
	App::Print(100, 100, "Current Moves: ");
	App::Print(300, 100, std::to_string(m_currentmove).c_str());
	App::Print(500, 100, "Ideal Moves: ");
	App::Print(700, 100, std::to_string(m_playboard->m_bestmoves).c_str());
	if (m_finish)
	{
		if (m_currentmove > m_playboard->m_bestmoves)
		{
			App::Print(100, 200, "You can do better! Press down arrow to restart.");
		}
		else
		{
			App::Print(100, 200, "You win! Press down arrow to continue.");
		}
	}
}

void CGolfBall::Move(MovingDirection direction, bool countMove)
{
	if (!m_finish && m_status == Stop)
	{
		// Set target tile position
		switch (direction)
		{
		case M_Up:
			m_targetrow = m_row - 1;
			m_targetcolumn = m_column;
			break;
		case M_Down:
			m_targetrow = m_row + 1;
			m_targetcolumn = m_column;
			break;
		case M_Left:
			m_targetcolumn = m_column - 1;
			m_targetrow = m_row;
			break;
		case M_Right:
			m_targetcolumn = m_column + 1;
			m_targetrow = m_row;
			break;
		default:
			break;
		}
		if (0 <= m_targetrow && m_targetrow <= 9 && 0 <= m_targetcolumn && m_targetcolumn <= 9)
		{
			int nextTile = m_playboard->GetValue(m_targetcolumn, m_targetrow);
			if (nextTile != TileType::Block)
			{
				m_status = Moving;
				m_direction = direction;
				if (countMove)
				{
					m_currentmove += 1;
				}
			}
		}
	}
}

void CGolfBall::SetPosition(int x, int y)
{
	m_row = y;
	m_column = x;
}

void CGolfBall::Next()
{
	if (m_finish)
	{
		if (m_currentmove <= m_playboard->m_bestmoves)
		{
			m_level += 1;
			if (m_level > 3)
			{
				m_level = 0;
			}
		}
		m_playboard = new CPlayBoard(".\\TestData\\level" + std::to_string(m_level) + ".txt");
		SetPosition(m_playboard->m_startx, m_playboard->m_starty);
		m_currentmove = 0;
		m_finish = false;
	}
}