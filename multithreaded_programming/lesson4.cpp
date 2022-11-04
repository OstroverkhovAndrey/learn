#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int Sum (int a, int b) {
    std::cout << "Sum start, ID " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Sum finish, ID " << std::this_thread::get_id() << std::endl;
    return a + b;
}

int main () {
    int a = 2, b = 3, c = 10;
    std::thread th([&c](int a, int b){c = Sum(a, b);}, a, b);

    for (int i = 0; i < 10; ++i) {
        std::cout << "Main work, ID " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    th.join();
    //th.detach();

    std::cout << a << " + " << b << " = " << c << std::endl;
    return 0;
}
