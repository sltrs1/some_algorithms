#include <iostream>
#include <random>
#include <vector>
#include "timer_singleton.h"
#include "fibonacci.h"
#include "euclid.h"
#include "knapsack.h"


int main()
{

    timer_singleton * timer = timer_singleton::getInstance();

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


    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Greedy algorithms" << std::endl;
    std::cout << std::endl;
    std::cout << "Max Knapsack" << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());

    constexpr int min_amount_of_items = 1;
    constexpr int max_amount_of_items = 10e3;
    constexpr int min_knapsack_capacity = 0;
    constexpr int max_knapsack_capacity = 2*10e6;
    constexpr int min_price = 0;
    constexpr int max_price = 2*10e6;
    constexpr int min_volume = 1;
    constexpr int max_volume = 2*10e6;

    std::uniform_int_distribution<int> dis(min_amount_of_items, max_amount_of_items);
    size_t amount_of_items = dis(gen);
    dis.param(std::uniform_int_distribution<int>::param_type{min_knapsack_capacity, max_knapsack_capacity});
    size_t knapsack_volume = dis(gen);
    dis.param(std::uniform_int_distribution<int>::param_type{min_price, max_price});
    std::uniform_int_distribution<int> dis2(min_volume, max_volume);

    std::vector<Item> items;

    for (size_t i = 0; i < amount_of_items; i++)
    {
        items.emplace_back(dis(gen), dis2(gen));
    }

    timer->hit_the_clock();
    auto max_knapsack_value = get_max_knapsack_value(knapsack_volume, items);
    timer->hit_the_clock();
    std::cout << "Max knapsack value = " << max_knapsack_value << std::endl;
    return 0;



}
