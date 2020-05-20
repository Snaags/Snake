#pragma once

#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Food
{
public:
	Food(std::mt19937& rng, const Board& brd, Snake& snake);
	Location getLocation() const;
	void Draw(Board& brd) const;
	void Update(std::mt19937& rng, const Board& brd, Snake& snake);

private:
	Location loc;
	Color c;
	static constexpr Color foodColor = Colors::Red;








};