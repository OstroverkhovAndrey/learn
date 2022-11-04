#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

void Sum (int a, int b, int & res) {

    cout << "Sum start, ID " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(4000));
    res = a + b;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Sum finish, ID " << this_thread::get_id() << endl;

}

int main () {

    int a = 2, b = 3, c = 10;
    thread th(Sum, a, b, std::ref(c));

    for (int i = 0; i < 10; ++i) {
        cout << "Main work, ID " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    th.join();
    //th.detach();
    // с join мы точно дождемся результата
    // с detach мы можем завершиться не дожидаясь результата

    cout << a << " + " << b << " = " << c << endl;

    return 0;
}
