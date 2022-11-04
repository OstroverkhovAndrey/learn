#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::recursive_mutex rmtx;

void f (int a) {

    rmtx.lock();

    std::cout << a << " " << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    if (a<1) {
        std::cout << std::endl;
        rmtx.unlock();
        return;
    }
    f(a-1);
    rmtx.unlock();
    return;
}

int main () {

    std::thread th1(f, 10);
    std::thread th2(f, 10);

    th1.join();
    th2.join();

    return 0;
}
