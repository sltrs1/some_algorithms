#include <iostream>
#include <chrono>
#include "fibonacci.h"
#include "euclid.h"

int main()
{

    auto time_start = std::chrono::high_resolution_clock::now();
    auto time_end   = std::chrono::high_resolution_clock::now();
    auto duration   = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);

    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Fibonacci numbers" << std::endl;
    int64_t n = 41;
    int m = 255;
    int fib = 0;

    time_start = std::chrono::high_resolution_clock::now();
    fib = fibonacci::get_naiive(n);
    time_end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);
    std::cout << "N-th (" << n << ") fib = " << fib << std::endl;
    std::cout << "Naiive implementation takes " << duration.count() << " microseconds" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    fibonacci::get_v(n);
    time_end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);
    std::cout << "Implementation with std::vector as memory takes " << duration.count() << " microseconds" << std::endl;
    time_start = std::chrono::high_resolution_clock::now();
    fibonacci::get_um(n);
    time_end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);
    std::cout << "Implementation with std::unordered_map as memory takes " << duration.count() << " microseconds" << std::endl;

    std::cout << "Last digit of N-th (" << n << ") fib = " << fibonacci::get_last_digit(n) << std::endl;
    std::cout << "N-th fib % m (F" << n << "%" << m << ") = " << fibonacci::get_remainder_fast(n, m) << std::endl;


    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Greatest common divisor" << std::endl;
    int a = 15465625;
    int b = 5646545;
    std::cout << "GCD(" << a << ", " << b <<") = " << euclid::gcd(a,b) << std::endl;

    return 0;
}
