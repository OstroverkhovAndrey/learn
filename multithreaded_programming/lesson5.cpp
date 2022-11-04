#include <iostream>
#include <iterator>
#include <string>
#include <thread>
#include <chrono>

class MyClass {
public:
    void f1 () {
        std::cout << "f1 start,  ID " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "f2 finish, ID " << std::this_thread::get_id() << std::endl;
    }

     void f2 (int a) {
        std::cout << "f2 start,  ID " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "parametr " << a << std::endl;
        std::cout << "f2 finish, ID " << std::this_thread::get_id() << std::endl;
    }
    int f3 (int a, int b) {
        std::cout << "f3 start,  ID " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << "f3 finish, ID " << std::this_thread::get_id() << std::endl;
        return a + b;
    }
};

int main () {

    int a = 2, b = 3, c = 10;
    MyClass mc;

    //std::thread th([&mc, &c](int a, int b){c = mc.f3(a, b);}, a, b);
    //std::thread th(&MyClass::f1, mc);
    std::thread th(&MyClass::f2, mc, c);

    for (int i = 0; i < 10; ++i) {
        std::cout << "Main work, ID " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    th.join();

    std::cout << a << " + " << b << " = " << c << std::endl;

    return 0;
}
