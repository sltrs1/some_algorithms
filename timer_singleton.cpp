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
        auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Measured time = " << duration.count() << " microseconds" << std::endl;
        ++counter;
    }

}
