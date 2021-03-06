/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snake( {2,2} ),
	food(rng, brd,snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameOver)
	{

		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}

		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}

		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}

		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
		snakeMoveCounter++;
		if (snakeMoveCounter > snakeMovePeriod) {

			if ((brd.InBoard(snake.GetNextHeadLocation(delta_loc)) == false) || (snake.InTile(snake.GetNextHeadLocation(delta_loc))))
			{
				gameOver = true;
			}

			else
			{



				if (snake.GetNextHeadLocation(delta_loc) == food.getLocation())
				{
					snake.Grow(rng);
					snake.MoveBy(delta_loc);
					food.Update(rng, brd, snake);

					if (snakeSizeOld < (snake.getSize() - 2)) {
						increaseSpeed();
						snakeSizeOld = snake.getSize();
					}
					
				}
				else 
				{
					snake.MoveBy(delta_loc);
				}
				
				
				snakeMoveCounter = 0;
			}
		}
	}
	
}

void Game::increaseSpeed()
{
	if (snakeMovePeriod > 1) {
		snakeMovePeriod -= 1;
	}
}

void Game::ComposeFrame()
{

	snake.Draw(brd);
	food.Draw(brd);
	brd.DrawBorder();
	if (gameOver) 
	{
		SpriteCodex::DrawGameOver(gfx.ScreenWidth/2 - 50,gfx.ScreenHeight/2 -50 , gfx);
	}
}
