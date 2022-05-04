#include <iostream>

#include "timer_singleton.h"
#include "fibonacci.h"
#include "euclid.h"


int main()
{

    timer_singleton * timer = timer_singleton::getInstance();

    auto time_start = std::chrono::high_resolution_clock::now();
    auto time_end   = std::chrono::high_resolution_clock::now();
    auto duration   = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);

    std::cout << "Hello World!" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Fibonacci numbers" << std::endl;
    int64_t n = 41;
    int m = 255;

    auto fib = fibonacci::get_vars(n);
    std::cout << "N-th (" << n << ") fib = " << fib << std::endl;

    std::cout << "Naiive recursive implementation" << std::endl;
    timer->hit_the_clock();
    fibonacci::get_naiive(n);
    timer->hit_the_clock();

    std::cout << "Implementation with std::vector as memory" << std::endl;
    timer->hit_the_clock();
    fibonacci::get_vec(n);
    timer->hit_the_clock();

    std::cout << "Implementation with std::unordered_map as memory" << std::endl;
    timer->hit_the_clock();
    fibonacci::get_um(n);
    timer->hit_the_clock();

    std::cout << "Implementation with 2 variables as memory" << std::endl;
    timer->hit_the_clock();
    fibonacci::get_vars(n);
    timer->hit_the_clock();

    std::cout << std::endl;
    std::cout << "Last digit of N-th (" << n << ") fib = " << fibonacci::get_last_digit(n) << std::endl;
    std::cout << "N-th fib % m (F" << n << "%" << m << ") = " << fibonacci::get_remainder_fast(n, m) << std::endl;


    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Greatest common divisor" << std::endl;
    int a = 15465625;
    int b = 5646545;
    std::cout << "GCD(" << a << ", " << b <<") = " << euclid::gcd(a,b) << std::endl;

    return 0;
}
