#include <variant>
#include <string>
#include <iostream>
 
void test_1(){
    std::variant<int, float> v{12}, w;
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v); // 效果同前一行
 
//  std::get<double>(v); // 错误： [int, float] 中无 double
//  std::get<3>(v);      // 错误：合法的 index 值是 0 和 1
 
    try {
      auto result = std::get<float>(w); // w 含有 int ，非 float ：将抛出异常
    }
    catch (std::bad_variant_access&) {}
}

int main(int argc, char** argv){
    test_1();
    return 0;
}
