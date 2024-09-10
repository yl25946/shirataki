#pragma once

#include "movepick.h"

template <GenType gen_type>
MovePicker<gen_type>::MovePicker(const Board &board)
{
    MoveList pseudolegal_moves;

    if (gen_type == GenType::ALL)
    {
        generate_moves(board, pseudolegal_moves);

        for (int i = 0; i < pseudolegal_moves.size(); ++i)
        {
            Board copy = board;
            copy.make_move(pseudolegal_moves[i]);

            if (copy.was_legal())
                legal_moves.insert(pseudolegal_moves[i]);
        }
    }
}