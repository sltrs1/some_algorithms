#ifndef FIBONACCI_H
#define FIBONACCI_H

#pragma once

#include <cassert>
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

class fibonacci final
{
public:
    static int get(int n);
    static int get_last_digit(int n);
    static int get_remainder_fast(int64_t n, int m);
};

#endif // FIBONACCI_H
