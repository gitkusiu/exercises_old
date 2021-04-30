#include <iostream>
#include <chrono>
#include <vector>

struct Timer
{
    Timer()
    {
        m_timeStampStart = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

private:

    void Stop()
    {
        auto timeStampStop = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_timeStampStart).time_since_epoch();
        auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(timeStampStop).time_since_epoch();
        auto duration = (stop - start).count();
        double ms = duration * 0.001;
        std::cout << duration << "us (" << ms  << "ms)"<< std::endl; 
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> m_timeStampStart;
};

void kosmider1()
{
    std::vector<double> v(200);
}

void kosmider2()
{
    std::vector<double> v(400);
}

int main()
{
    std::cout << "vector " << std::endl; 
    {
        Timer t;
        for(int i{0}; i<100000; i++)
        {
            kosmider1();
        }
    }
    {
        Timer t;
        for(int i{0}; i<100000; i++)
        {
            kosmider2();
        }
    }
}
