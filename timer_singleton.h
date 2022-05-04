#ifndef TIMER_SINGLETON_H
#define TIMER_SINGLETON_H
#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

class timer_singleton
{
public:
    timer_singleton(timer_singleton & other) = delete;
    void operator=(const timer_singleton& other) = delete;
    static timer_singleton * getInstance();
    void hit_the_clock();
private:
    timer_singleton();
    std::chrono::high_resolution_clock clock;
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
    size_t counter;
};

#endif // TIMER_SINGLETON_H
