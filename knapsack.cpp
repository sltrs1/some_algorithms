#include "knapsack.h"

bool Item::operator<(const Item & other) const
{
    return static_cast<double>(weight)/value < static_cast<double>(other.weight)/other.value;
}

double get_max_knapsack_value(int capacity, std::vector <Item> items)
{
    double value = 0.0;

    std::sort(items.begin(), items.end());

    for(const auto & item : items)
    {
        if (capacity > item.weight)
        {
            capacity -= item.weight;
            value += item.value;
        }
        else
        {
            value += item.value * (static_cast<double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}
