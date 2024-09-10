#include "threads.h"
#include "uci.h"

void search(Searcher *searcher, UciOptions *options)
{
    searcher->search();
}

uint64_t ThreadManager::get_nodes()
{
    uint64_t nodes = 0;

    for (Searcher &searcher : searchers)
        nodes += searcher.nodes;

    return nodes;
}

void ThreadManager::go(Board &board, std::vector<Move> &move_list, Time &time)
{
    // clears away the results from a previous search
    join();
    threads.clear();
}

void ThreadManager::stop()
{
    if (!searching)
        return;

    nodes = get_nodes();

    searching = false;
}

void ThreadManager::join()
{
    if (!searching)
        return;

    nodes = get_nodes();

    searching = false;
}

void ThreadManager::terminate()
{
    if (!searching)
        return;

    nodes = get_nodes();

    searching = false;
}

void ThreadManager::resize(int new_thread_count)
{
    terminate();
    thread_data.clear();
    thread_data.resize(new_thread_count);
    options.threads = new_thread_count;
}
