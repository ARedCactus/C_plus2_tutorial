#include <memory>
#include <iostream>

// std::weak_ptr 是一种不拥有对象所有权的智能指针，用于解决 std::shared_ptr 循环引用的问题。
// std::weak_ptr 可以观察但不能直接访问所管理的对象，必须通过 std::shared_ptr 获取对象的访问权。

int main(int argc, char* argv[]){
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
    std::weak_ptr<int> weakPtr = sharedPtr; // weakPtr 观察 sharedPtr
 
    if(auto tmpPtr = weakPtr.lock()) { // 获取 shared_ptr 以访问对象
        std::cout << "Value pointed to by weakPtr: " << *tmpPtr << std::endl;
    }else{
        std::cout << "The managed object has been deleted." << std::endl;
    }
 
    return 0;
}