#pragma once
#include "Board.h"
#include <random>

class Snake
{
private:

	class Segment 
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(std::mt19937& rng);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		Location GetLocation();

	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy( const Location& delta_loc );
	void Grow(std::mt19937& rng);
	Location GetNextHeadLocation(const Location& delta_loc);
	void Draw( Board& brd ) const;
	bool InTile(const Location& nloc, bool ignoreLast = true);
	int getSize();
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};