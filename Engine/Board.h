#pragma once

#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell( const Location& loc ,Color c );
	void DrawBorder();
	int GetWidth() const;
	int GetHeight() const;
	void CenterBorders(Graphics& gfx);
	bool InBoard(const Location& loc) const;
private:
	int boardOffSetx = 0;
	int boardOffSety = 0;
	static constexpr int borderThickness = 2;
	static constexpr Color borderColor = Colors::Magenta;

	static constexpr int padding = 2;
	static constexpr int dimension = 20;
	static constexpr int width = 30;
	static constexpr int height = 20;
	Graphics& gfx;

};