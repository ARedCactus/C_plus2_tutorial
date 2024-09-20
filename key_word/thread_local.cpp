#include <iostream>

#include <iostream>
#include <mutex>
#include <thread>
std::mutex cout_mutex;    //方便多线程打印

void thread_func(const std::string& thread_name) {
    for (int i = 0; i < 3; ++i) {
        thread_local  int x = 1;  //只在每个线程创建时初始化一次
        x++;
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "thread[" << thread_name << "]: x = " << x << std::endl;
    }
}

int main() {
    std::thread t1(thread_func, "t1");
    std::thread t2(thread_func, "t2");
    t1.join();
    t2.join();
    return 0;
}


// 输出： 只在每个线程创建时初始化一次
// thread[t1]: x = 2
// thread[t1]: x = 3
// thread[t1]: x = 4
// thread[t2]: x = 2
// thread[t2]: x = 3
// thread[t2]: x = 4

// 如果不加thread_local，相当于局部变量
// thread[t2]: x = 2
// thread[t2]: x = 2
// thread[t2]: x = 2
// thread[t1]: x = 2
// thread[t1]: x = 2
// thread[t1]: x = 2

