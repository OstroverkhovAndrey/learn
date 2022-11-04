#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx1, mtx2;

void f1 () {

    mtx1.lock();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mtx2.lock();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << '*' << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mtx2.unlock();

    mtx1.unlock();
}

void f2 () {

    mtx2.lock();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mtx1.lock();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << '#' << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mtx1.unlock();

    mtx2.unlock();
}

int main () {
    // если mutex идут в разных порядках и есть задержка
    // то возможна взаимная блокировка потоков 
    
    std::thread th1(f1);
    std::thread th2(f2);

    th1.join();
    th2.join();

    return 0;
}
