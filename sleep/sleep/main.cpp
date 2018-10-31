#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "hello ";
    this_thread::sleep_for(chrono::seconds(10)); // 10000 / 100 = 10 seconds
    cout << "world\n";
    return 0;
}
