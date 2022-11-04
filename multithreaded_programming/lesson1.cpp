#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork () {

    for (int i = 0; i < 10; ++i) {
        stringstream ss;
        ss << "ID " << this_thread::get_id() << " DoWork " << i << "\n";
        cout << ss.str();

        //cout << "ID " << this_thread::get_id() << " DoWork " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main () {

    thread th(DoWork);

    //th.detach();
    //когда закончится основной поток закончится и порожденный

    for (int i = 0; i < 10; ++i) {
        stringstream ss;
        ss << "ID " << this_thread::get_id() << " main " << i << "\n";
        cout << ss.str();


        //cout << "ID " << this_thread::get_id() << " main " << i << "\n";
        //обычный cout может объединять выводы разных потоков
        //через создание отдельной строки выводы будут раздельными
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    th.join();
    //основной поток дождется порожденного

    return 0;
}
