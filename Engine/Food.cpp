#include "Food.h"

Food::Food(std::mt19937& rng, const Board& brd, Snake& snake)
{
	Update(rng, brd, snake);
	c = foodColor;
};

Location Food::getLocation() const
{
	return loc;
}

void Food::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Food::Update(std::mt19937& rng, const Board& brd, Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() -1 );
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.InTile(newLoc));
	loc = newLoc;
}

