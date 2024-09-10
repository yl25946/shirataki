#pragma once

#include "defs.h"
#include "movegen.h"
#include "movelist.h"

template <GenType gen_type>
class MovePicker
{
    MoveList legal_moves;

public:
    MovePicker(const Board &board);

    inline bool has_next() { legal_moves.size() != 0; }
    // pops the last move out of legal_moves
    inline Move next_move()
    {
        Move move = legal_moves[legal_moves.size() - 1];
        legal_moves.pop_back();
        return move;
    }

    inline size_t size() const { return legal_moves.size(); };
};