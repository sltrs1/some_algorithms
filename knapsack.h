#ifndef KNAPSACK_H
#define KNAPSACK_H

#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
    Item(int w, int v) : weight(w), value(v) {};
    int weight;
    int value;
    bool operator< (const Item & other) const;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items);

#endif // KNAPSACK_H
