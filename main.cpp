#include <iostream>
#include <tbb/concurrent_queue.h>
#include <thread>

tbb::concurrent_bounded_queue<int> myQueue;

void Producer() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        myQueue.push(i);
    }
}

void Consumer() {
    for (int i = 0; i < 10; ++i) {
        int value;
        myQueue.pop(value);
        std::cout << "Consumed: " << value << std::endl;
    }
}

int main() {
    std::thread producer(Producer);
    std::thread consumer(Consumer);

    producer.join();
    consumer.join();

    return 0;
}