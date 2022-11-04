#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

void Sum (int a, int b, string mes) {

    cout << "Mes: " << mes << endl;
    cout << "Sum start\n";
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << a+b << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Sum finish\n";

}

int main () {

    thread th(Sum, 2, 3, "My message!");

    for (int i = 0; i < 20; ++i) {
        cout << "main work\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    th.join();

    return 0;
}
