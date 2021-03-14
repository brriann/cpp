#pragma once

#ifndef Commons_cpp
#define Commons_cpp

#include <tuple>
using std::tuple;

// enum used for grid calculations
enum class MoveDirection { UP = 0, DOWN = 1, RIGHT = 2, LEFT = 3 };

// type definition for grid (row, col) locations
typedef tuple<int, int> IntTuple ;

#endif