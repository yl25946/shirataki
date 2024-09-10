#pragma once

#include "defs.h"
#include "utils.h"
#include "attacks.h"
#include "magic_bitboards.h"
#include "board.h"
#include "movegen.h"
#include "perft.h"
#include "uci.h"
#include "zobrist.h"
#include "threads.h"

int main()
{
    init_leapers_attacks();
    init_sliders_attacks();
    init_zobrist_tables();

    UCI_loop();

    return 0;
}