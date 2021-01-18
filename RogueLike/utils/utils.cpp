#include "utils.h"

namespace roguelike {

int rand_int(int from, int to) {
    if (from > to) {
        int tmp = to;
        to = from;
        from = tmp;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> int_distribution(from, to);
    return int_distribution(mt);
}

}