#include <iostream>
#include <memory>

// std::unique_ptr 是一种独占所有权的智能指针，即一个 std::unique_ptr 对象只能独自拥有某块内存.
// 当 std::unique_ptr 超出其作用域时，它会自动销毁所管理的对象，并释放相应的内存。
// make_unique 在C++14标准中才出现

int main(int argc, char* argv[]){
    std::unique_ptr<int> ptr1(new int(10)); // 使用 new 分配内存
    std::unique_ptr<int> ptr2 = std::make_unique<int>(20); // 使用 std::make_unique 分配内存（推荐）
 
    std::cout << "Value pointed to by ptr1: " << *ptr1 << "\n";
    std::cout << "Value pointed to by ptr2: " << *ptr2 << "\n";

    // 传递所有权
    // 由于 std::unique_ptr 具有独占所有权，不能直接复制它，但可以通过 std::move 传递所有权
    std::unique_ptr<int> ptr3 = std::move(ptr1); // ptr1 所有权转移到 ptr3
    std::cout << "Value pointed to by ptr3: " << *ptr3 << "\n";
    if(!ptr1){
        std::cout << "ptr1 is now empty" << "\n";
    }

    // 重置和释放内存
    // 使用 reset() 方法可以重置 std::unique_ptr，并释放其管理的内存
    ptr2.reset(); // 释放 ptr2 所管理的内存
    if(!ptr2){
        std::cout << "ptr2 is reseted" << std::endl;
    }

    // 自定义删除器
    // 可以为 std::unique_ptr 提供自定义删除器，用于在释放内存时执行特定操作
    std::unique_ptr<int, void(*)(int*)> ptr4(new int(30), [](int* p){
        std::cout << "Deleting ptr4: " << *p << "\n";
        delete p;
    });
 
    return 0;
}