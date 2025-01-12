#include <iostream>
#include <thread>
#include <mutex>

void T1() {
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c;
    }
}

void T2() {
    for (int i = 0; i <= 32; ++i) {
        std::cout << i;
    }
}

void T3() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::cout << c;
    }
}

int main() {
    std::thread thread1(T1);
    std::thread thread2(T2);
    std::thread thread3(T3);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
