// 概念：C/C++ 中的 assert 是一个宏，用于在运行时检查一个条件是否为真，如果条件不满足，则运行时将终止程序的执行并输出一条错误信息。
// 注意：assert 只有在 Debug 版本中才有效，如果编译为 Release 版本则被忽略。 

#include <cassert>
#include <iostream>

int main(int argc, char **argv){
    int a{10}, b{20};
    assert(a>b && "failed addition"); //条件不成立，异常退出
    std::cout << "here\n";

    return 0;
}