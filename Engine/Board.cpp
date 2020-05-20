#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx( gfx )
{
	CenterBorders(gfx);
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectDim(boardOffSetx + loc.x * dimension + padding, boardOffSety + loc.y * dimension + padding, dimension -padding, dimension -padding, c);
}

void Board::DrawBorder()
{
	//Draw left
	gfx.DrawRect(boardOffSetx - borderThickness, boardOffSety - borderThickness, boardOffSetx, boardOffSety + (dimension * height),borderColor);
	//Draw right
	gfx.DrawRect(boardOffSetx + (dimension * width), boardOffSety - borderThickness, boardOffSetx + (dimension * width) + borderThickness,  boardOffSety + (dimension * height) + borderThickness, borderColor);
	//Draw top
	gfx.DrawRect(boardOffSetx - borderThickness, boardOffSety - borderThickness, boardOffSetx + (dimension * width), boardOffSety, borderColor);
	//Draw bottom
	gfx.DrawRect(boardOffSetx - borderThickness, boardOffSety  + (dimension * height), boardOffSetx + (dimension * width), boardOffSety + (dimension * height) + borderThickness, borderColor);
}

 int Board::GetWidth() const
{
	return width;
}

 int Board::GetHeight() const
{
	return height;
}

 void Board::CenterBorders(Graphics& gfx)
 {
	 boardOffSetx = (gfx.ScreenWidth - (dimension * width))/2;
	 boardOffSety = (gfx.ScreenHeight - (dimension * height))/2;
 }



bool Board::InBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.y >= 0 && loc.x < width && loc.y < height;
}
