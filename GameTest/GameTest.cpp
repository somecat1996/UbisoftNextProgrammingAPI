///////////////////////////////////////////////////////////////////////////////
// Filename: GameTest.cpp
// Provides a demo of how to use the API
///////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
#include "Common.h"
#include "GolfBall.h"
#include "PlayBoard.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
CSimpleSprite *testSprite;
CSimpleSprite* blockSpriteNormal;
CSimpleSprite* blockSpriteBlock;
CSimpleSprite* blockSpriteStart;
CSimpleSprite* blockSpriteExit;
CSimpleSprite* blockSpriteUp;
CSimpleSprite* blockSpriteDown;
CSimpleSprite* blockSpriteLeft;
CSimpleSprite* blockSpriteRight;
CGolfBall* golfBall;
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	//------------------------------------------------------------------------
	// Initiate block sprite
	blockSpriteNormal = App::CreateSprite(".\\TestData\\TestBlockNormal.png", 1, 1);
	blockSpriteBlock = App::CreateSprite(".\\TestData\\TestBlockBlock.png", 1, 1);
	blockSpriteStart = App::CreateSprite(".\\TestData\\TestBlockStart.png", 1, 1);
	blockSpriteExit = App::CreateSprite(".\\TestData\\TestBlockTarget.png", 1, 1);
	blockSpriteUp = App::CreateSprite(".\\TestData\\TestBlockUp.png", 1, 1);
	blockSpriteDown = App::CreateSprite(".\\TestData\\TestBlockDown.png", 1, 1);
	blockSpriteLeft = App::CreateSprite(".\\TestData\\TestBlockLeft.png", 1, 1);
	blockSpriteRight = App::CreateSprite(".\\TestData\\TestBlockRight.png", 1, 1);
	blockSpriteNormal->SetScale(1.0f);
	blockSpriteBlock->SetScale(1.0f);
	blockSpriteStart->SetScale(1.0f);
	blockSpriteExit->SetScale(1.0f);
	blockSpriteUp->SetScale(1.0f);
	blockSpriteDown->SetScale(1.0f);
	blockSpriteLeft->SetScale(1.0f);
	blockSpriteRight->SetScale(1.0f);

	// Initiate golf ball
	golfBall = new CGolfBall();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime)
{
	//------------------------------------------------------------------------
	golfBall->Update(deltaTime);
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		golfBall->Move(MovingDirection::M_Right, true);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		golfBall->Move(MovingDirection::M_Left, true);
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		golfBall->Move(MovingDirection::M_Up, true);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		golfBall->Move(MovingDirection::M_Down, true);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		golfBall->Next();
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			float x, y;
			int tileType;
			Common::GetScreenPosition(j, i, &x, &y);
			tileType = golfBall->m_playboard->GetValue(j, i);
			switch (tileType)
			{
			case 0:
				blockSpriteNormal->SetPosition(x, y);
				blockSpriteNormal->Draw();
				break;
			case 1:
				blockSpriteBlock->SetPosition(x, y);
				blockSpriteBlock->Draw();
				break;
			case 2:
				blockSpriteStart->SetPosition(x, y);
				blockSpriteStart->Draw();
				break;
			case 3:
				blockSpriteExit->SetPosition(x, y);
				blockSpriteExit->Draw();
				break;
			case 4:
				blockSpriteUp->SetPosition(x, y);
				blockSpriteUp->Draw();
				break;
			case 5:
				blockSpriteDown->SetPosition(x, y);
				blockSpriteDown->Draw();
				break;
			case 6:
				blockSpriteLeft->SetPosition(x, y);
				blockSpriteLeft->Draw();
				break;
			case 7:
				blockSpriteRight->SetPosition(x, y);
				blockSpriteRight->Draw();
				break;
			default:
				blockSpriteNormal->SetPosition(x, y);
				blockSpriteNormal->Draw();
				break;
			}
		}
		if (golfBall->m_row == i - 1 && golfBall->m_direction == M_Down && golfBall->m_status == Moving)
		{
			golfBall->Draw();
		}
		else if (golfBall->m_row == i)
		{
			golfBall->Draw();
		}
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	delete blockSpriteNormal;
	delete blockSpriteBlock;
	delete blockSpriteStart;
	delete blockSpriteExit;
	delete blockSpriteUp;
	delete blockSpriteDown;
	delete blockSpriteLeft;
	delete blockSpriteRight;
	//------------------------------------------------------------------------
}