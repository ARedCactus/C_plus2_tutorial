#include <thread>
#include <iostream>
#include <unordered_map>

#include "standard.hpp"

//宏定义变量命名：对象+属性  以下划线"_"开头
#define _area 3
//宏定义函数命名：单词首字母大写，以下划线"_"开头
#define _maxNumber(a, b)(a>b? a:b)

//不推荐以上 #define obj... 用法，实际项目不会使用
//推荐以下方法代替：

const int _area_1{3};
template<typename T> constexpr T
_maxNumber_1(T a, T b){
    return a>b? a:b;
}

//我们推荐将宏定义放到命名空间下，防止污染标准库
//e.g
namespace TempNameSapce{
const int _area_1{3};
template<typename T> constexpr T
_maxNumber_1(T a, T b){
    return a>b? a:b;
}
};

std::vector<std::unordered_map<int, std::string>>  //函数返回值太长，直接换行
getMap(int num_1, std::string str_1,        // 参数太多，对齐换行
        int num_2, std::string str_2, 
        int num_3, std::string str_3){
    std::unordered_map<int, std::string> map_output{    //列表初始化
        {num_1, str_1},
        {num_2, str_2},
        {num_3, str_3}
    };
    return {
        map_output
    };
}

int main(int argc, char** argv){
    //按照命名空间获取对象
    NameSpaceOutside::NameSpaceInside::Country country_temp;
    double result = country_temp.addTwoNumbers(1.1, 2.2);
    std::cout << "result: " << result << "\n";
    auto [name_1, name_2, name_3] = country_temp.getNames();
    std::cout << "names: " << name_1 << name_2 << name_3 << "\n";

    std::vector<NameSpaceOutside::City> citys{{1, 2}, {1, 2.2}};
    NameSpaceOutside::Province province(3.14);
    auto state = NameSpaceOutside::HIGH;
    {
        //作用域内使用别名
        using NNCountrys = std::vector<NameSpaceOutside::NameSpaceInside::Country>;
        NNCountrys countrys;
        for(size_t index{0}; index < _area; ++index){
            std::cout << "index:" << index << "\n";
            auto country_new = new NameSpaceOutside::NameSpaceInside::Country();
            countrys.push_back(*country_new);
        }
    }
    int max_num = _maxNumber(1, 2);
    std::cout << "max_num:" << max_num << "\n";

    auto u_map = getMap(1, "a", 2, "b", 3, "c");

    return 0;
}