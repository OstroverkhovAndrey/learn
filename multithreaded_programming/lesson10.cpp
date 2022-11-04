#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

class SimpleTimer {
private:
    std::chrono::steady_clock::time_point start, finish;
    std::chrono::duration<float> duration;
public:
    SimpleTimer(){
        this->start = std::chrono::steady_clock::now();
    }
    ~SimpleTimer(){
        this->finish = std::chrono::steady_clock::now();
        duration = finish - start;
        std::cout << "Прошло времени " << duration.count()  << " секунд" << std::endl;
    }
};

std::mutex mtx;
// спользуется для невозможности исполнять кусок 
// кода в двух потоках одновременно

void f(char c) {

    // unique_lock позоляет более гибко чем lock_guard
    // работать с mutex
    std::unique_lock<std::mutex> ul(mtx, std::defer_lock);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    //std::unique_lock<std::mutex> ul(mtx);
    ul.lock();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout << c << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    ul.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main () {
    SimpleTimer st;

    std::thread th1(f, '*');
    std::thread th2(f, '#');

    //f('*');
    //f('#');

    th1.join();
    th2.join();

    return 0;
}

