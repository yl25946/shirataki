#pragma once

#include "defs.h"
#include "uci_options.h"
#include "time.h"

class UciOptions;
class Time;

class ThreadManager
{
public:
    UciOptions options;
    std::vector<std::jthread> threads;
    bool searching = false;
    // pretty much only used for bench
    uint64_t nodes = 0;

    ThreadManager() {}

    // void go(Board &board, std::vector<Move> &move_list, Time &time);
    // clears thread data and resizes to new number of threads
    void resize(int new_thread_count);
    void ucinewgame()
    {
    }
    void resize_tt(int new_hash_size) {}

    uint64_t get_nodes();

    // only stops the search doesn't join the search threads, dirty stop
    void stop();
    // stops the input therad until we are done searching
    void join();
    // makes the input thread wait for all the searcher to stop
    void terminate();
};
