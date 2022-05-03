#include "timer_singleton.h"

timer_singleton * timer_singleton::instance = nullptr;

timer_singleton::timer_singleton()
{
    clock = std::chrono::high_resolution_clock();
    start = clock.now();
    stop = clock.now();
    counter = 0;
}

timer_singleton * timer_singleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new timer_singleton();
    }
    return instance;
}

void timer_singleton::hit_the_clock()
{

    if (counter % 2 == 0)
    {
        // Clocks start ticking
        start = clock.now();
        ++counter;
    }
    else
    {
        // Clocks stop ticking and print time measured time
        stop = clock.now();
        auto duration =  std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        auto c(duration.count());
        std::ostringstream oss;
        oss << std::setfill('0')                // set field fill character to '0'
            << (c % 1000000000000) / 1000000000 // format seconds
            << " sec "
            << std::setw(3)                     // set width of milliseconds field
            << (c % 1000000000) / 1000000       // format milliseconds
            << " millisec "
            << std::setw(3)                     // set width of microseconds field
            << (c % 1000000) / 1000             // format microseconds
            << " microsec "
            << std::setw(3)                     // set width of nanoseconds field
            << c % 1000                         // format nanoseconds
            << " nanosec ";
        auto formatted(oss.str());
        std::cout << "Measured time = " << formatted << std::endl;
        ++counter;
    }

}
