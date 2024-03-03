#include <iostream>
#include <thread>
#include <vector>

// 这是我们将在多个线程中运行的函数
void worker(int n) {
    std::cout << "Worker " << n << " is running on thread " << std::this_thread::get_id() << "\n";
}

int main() {
    std::vector<std::thread> threads;

    // 启动5个工作线程
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(worker, i));
    }

    // 等待所有线程结束
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}