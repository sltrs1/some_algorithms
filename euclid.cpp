#include "euclid.h"

size_t euclid::gcd(size_t a, size_t b)
{
    assert(a > 0 && b > 0);

    while (b)
    {
        a %= b;
        std::swap (a, b);
    }
    return a;

}
