#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore(int count = 0) : count(count) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return count > 0; });
        --count;
    }

    void signal() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

#endif // SEMAPHORE_H
