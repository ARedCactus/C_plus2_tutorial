#include <memory>
#include <iostream>

// std::shared_ptr 是一种共享所有权的智能指针，可以有多个 std::shared_ptr 实例共享同一块内存。
// 当最后一个 std::shared_ptr 实例销毁时，所管理的内存才会被释放。

int main(int argc, char* argv[]){
    std::shared_ptr<int> ptr1(new int(10)); // 使用 new 分配内存
    std::shared_ptr<int> ptr2 = std::make_shared<int>(20); // 使用 std::make_shared 分配内存（推荐）
 
    std::cout << "Value pointed to by ptr1: " << *ptr1 << "\n";
    std::cout << "Value pointed to by ptr2: " << *ptr2 << "\n";

    std::shared_ptr<int> ptr3 = ptr1; // 共享所有权
    
    std::cout << "ptr1 use count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use count: " << ptr2.use_count() << std::endl;

    // 自定义删除器
    std::shared_ptr<int> ptr4(new int(30), [](int* p) {
        std::cout << "Deleting ptr4: " << *p << std::endl;
        delete p;
    });

    return 0;
}