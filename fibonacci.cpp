#include "fibonacci.h"


int fibonacci::get_vec(int n)
{
    assert(n >= 0);

    std::vector<int> fib_arr(n+1);

    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }

    return fib_arr[n];
}


int fibonacci::get_um(int n)
{
    assert(n >= 0);

    std::unordered_map<int, int> fib_um;

    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    fib_um[0] = 0;
    fib_um[1] = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        fib_um[i] = fib_um[i-1] + fib_um[i-2];
    }

    return fib_um[n];

}

int fibonacci::get_naiive(int n)
{
    assert(n >= 0);

    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    return get_naiive(n - 1) + get_naiive(n - 2);
}

int fibonacci::get_vars(int n)
{
    assert(n >= 0);

    if(n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev = 0;
    int curr = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        int new_curr = prev + curr;
        prev = curr;
        curr = new_curr;
    }

    return curr;
}


int fibonacci::get_last_digit(int n)
{
    assert(n >= 1);

    std::vector<int> fib_last_d_arr(n+1);

    if (n == 1)
        return 1;
    if (n == 2)
        return 1;

    fib_last_d_arr[0] = 0;
    fib_last_d_arr[1] = 1;

    for (size_t i = 2; i <= n; ++i)
    {
        fib_last_d_arr[i] = (fib_last_d_arr[i-1] + fib_last_d_arr[i-2]) % 10;
    }

    return fib_last_d_arr[n];
}

// Оптимизировано по скорости и памяти
int fibonacci::get_remainder_fast(int64_t n, int m)
{
    assert(n >= 1);
    assert(m >= 2);

    size_t result;
    size_t index;
    size_t period = n+1;
    size_t sz = std::min(static_cast<size_t>(n+1), static_cast<size_t>(m*m+1));

    std::vector<size_t> F(3);
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;

    for (size_t i = 3; i < sz; i++)
    {
        F.push_back((F[i-2] + F[i-1]) % m);
        if (F[i] == 1 && F[i-1] == 0)
        {
            period = i-1;
            break;
        }
    }

    index = n % period;
    result = F[index];
    return result;

}
