#include <iostream>
#include "fibonacci.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Fibonacci numbers" << std::endl;
    int64_t n = 22;
    int m = 255;
    std::cout << "N-th (" << n << ") fib = " << fibonacci::get(n) << std::endl;
    std::cout << "Last digit of N-th (" << n << ") fib = " << fibonacci::get_last_digit(n) << std::endl;
    std::cout << "N-th fib % m (F" << n << "%" << m << ") = " << fibonacci::get_remainder_fast(n, m) << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl << std::endl;

    return 0;
}
