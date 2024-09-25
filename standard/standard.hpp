#ifndef STANDARD_HPP
#define STANDARD_HPP    // *.hpp，*.h文件开头均以 "#ifndef+文件名字母大写" 开头

//先写std标准库文件
#include <string>
#include <variant>
#include <vector>
#include <tuple>
#include <iostream>
// ---> 空一行
//再写外部库头文件，例如Eigen，opencv, pcl，ros等外部库
 //include <Eigen>
// ---> 空一行
//最后写自己的头文件
// #include "other.h"
// ---> 空一行
//三种头文件之间空出一行， 不同头文件不要混在一起

// 外层命名空间
namespace NameSpaceOutside{
// 内层命名空间
namespace NameSpaceInside{
// 类，结构体，联合体的命名：每个单词的首字母大写
class Country{
public:
    Country(): name_("a"), name_last_("b"), name_last_long_red_("c"){}
    virtual ~Country() = default;
    //函数命名 第一个单词首字母小写，其余单词首字母大写
    //函数参数，局部变量命名： 对象+属性 结尾不加下划线“_”
    constexpr double addTwoNumbers(double num_1, double num_2){
        double result = num_1 + num_2;
        return result;
    }
    std::tuple<std::string, std::string, std::string> getNames(){
        return {
            name_, 
            name_last_, 
            name_last_long_red_
        };
    }
private:
    // 类成员变量命名 以下划线"_"结尾 
    std::string name_; //直接命名
    std::string name_last_; //对象+属性
    std::string name_last_long_red_; //对象+属性+属性+属性+.... //存在多个属性
};
}; // namespace NameSpaceInside
//结构体，联合体的变量命名：对象+属性 结尾不加下划线“_”
struct City{
    // 函数参数与成员的命名冲突， 函数参数结尾加上下划线"_"
    int population;
    std::variant<int, double> random_data;

    City(int population_, int random_data_){
        population = population_;
        random_data = random_data_;
    }
    City(int population_, double random_data_){
        population = population_;
        random_data = random_data_;
    }
    City(int population_, std::variant<int, double> random_data_){
        population = population_;
        random_data = random_data_;
    }
};
union Province{
private:
    double area;
    std::vector<City> citys;
    
public:
    // 函数参数与成员的命名冲突， 函数参数结尾加上下划线"_"
    Province(double area_){
        area = area_;
    }
    ~Province(){
        citys.clear();
    }
};

//枚举的成员变量全部大写
enum DevelopingState{
    LOW, 
    MIDDLE, 
    HIGH
};

}; // namespace NamespaceOutside

#endif