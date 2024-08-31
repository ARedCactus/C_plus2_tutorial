#include <iostream>
#include <deque>

// std::deque (双端队列) 两端操作速度优于 std::vector

void printDeque(const std::deque<int>& d){
    for(std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

//deque构造
void test1() {
    // 无参默认构造函数
    std::deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    // 通过区间方式进行构造
    std::deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    // n 个 elem 方式进行构造
    std::deque<int> d3(10,100);
    printDeque(d3);

    // 拷贝构造函数
    std::deque<int> d4(d3);
    printDeque(d4);
}

int main(int argc, char* argv[]){
    test1();
}