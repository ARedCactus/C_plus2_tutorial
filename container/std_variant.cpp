#include <variant>
#include <iostream>
#include <string>
#include <math.h>



void test_1() {
    // 定义一个std::variant对象，可以存储int、double和std::string类型的值
    std::variant<int, double, std::string> v;

    // 存储int类型的值
    v = 10;
    // 访问存储的int类型的值
    std::cout << "Stored int value: " << std::get<int>(v) << std::endl;

    // 存储double类型的值
    v = M_PI;
    // 访问存储的double类型的值
    std::cout << "Stored double value: " << std::get<double>(v) << std::endl;

    // 存储std::string类型的值
    v = "Hello";
    // 访问存储的std::string类型的值
    std::cout << "Stored string value: " << std::get<std::string>(v) << std::endl;

    // 使用std::visit访问不同类型的值
    std::visit([](auto && arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "int: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, double>) {
            std::cout << "double: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "string: " << arg << std::endl;
        }
    }, v);
}

// 当处理需要解析多类型数据的情况时，std::variant也可以派上用场。
// 例如，当解析一些类似JSON的结构时，可以使用std::variant来表示不同可能的值类型，从而在解析期间轻松地处理不同类型的值。
struct JsonValue{
    bool isInt();
    bool isDouble();
    bool isBoolean();
    bool isString();
    int getInt();
    double getDouble();
    bool getBoolean();
    std::string getString();
}
std::variant<int, double, std::string, bool> parseValue(const JsonValue& json) {
    if (json.isInt()) {
        return json.getInt();
    } else if (json.isDouble()) {
        return json.getDouble();
    } else if (json.isString()) {
        return json.getString();
    } else if (json.isBoolean()) {
        return json.getBoolean();
    }
    // Handle error, unsupported type, or default case
}

int main(){
    test_1();
    return 0;
}