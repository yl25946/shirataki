#pragma once

#include "defs.h"
#include "attacks.h"
#include "board.h"
#include "movelist.h"

// generates all pseudolegal moves and puts them into an array
void generate_moves(const Board &board, MoveList &move_list);

// used for qSearch
void generate_capture_moves(const Board &board, MoveList &move_list);

// used for probcut, generates non capture queen promotions
void generate_queen_promotions(const Board &board, MoveList &move_list);