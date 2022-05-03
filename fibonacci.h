#ifndef FIBONACCI_H
#define FIBONACCI_H

#pragma once

#include <cassert>
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_map>

class fibonacci final
{
public:
    static int get_vec(int n); // Vector as memory
    static int get_um(int n); // Hash Table as memory
    static int get_vars(int n); // 2 varalbles as memory
    static int get_naiive(int n); // Naiive recursive implementation
    static int get_last_digit(int n); // Lastr digit of n-th Fibonacci number
    static int get_remainder_fast(int64_t n, int m); // Remainder F(n)%m where n and m are very big
};

#endif // FIBONACCI_H
