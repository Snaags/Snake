#include "Snake.h"
#include <assert.h>
#include <random>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for(int i= nSegments -1;  i > 0; --i )
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow(std::mt19937& rng)
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(rng);
		nSegments++;
	}
}


//Gets the next location of the snakes head
Location Snake::GetNextHeadLocation(const Location& delta_loc)
{

	Location NextLoc = segments[0].GetLocation();
	NextLoc.Add(delta_loc);
	return NextLoc;
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++) 
	{
		segments[i].Draw( brd );
	}
}

bool Snake::InTile(const Location& nloc, bool ignoreLast)
{
	int offset = 1;
	if (ignoreLast == false) {
		offset = 0;
	}
	
	for (int i = 0; i < (nSegments -offset);i++) 
	{
		if (segments[i].GetLocation() == nloc) 
		{
			return true;
		}
	}
	return false;
}

int Snake::getSize()
{
	return (nSegments -1);
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(std::mt19937& rng)
{
	c = Snake::bodyColor;
	std::uniform_int_distribution<int> Dist(100,255);
	c.SetG(Dist(rng));
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert((abs(delta_loc.x) + abs(delta_loc.y)) == 1);
	loc.Add( delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

//Gets the location struct of the segment
Location Snake::Segment::GetLocation()
{
	return loc;
}
