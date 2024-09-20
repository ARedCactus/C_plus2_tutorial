#include <iostream>

// constexpr 编译期初始化
// const 和 constexpr 变量之间的主要区别在于：const 变量的初始化可以延迟到运行时，而 constexpr 变量必须在编译时进行初始化。
// 所有 constexpr 变量均为常量，因此必须使用常量表达式初始化。
 
int g_tempA = 4;
const int g_conTempA = 4;
constexpr int g_conexprTempA = 4;
 
int main()
{
	int tempA = 4;
	const int conTempA = 4;
	constexpr int conexprTempA = 4;
 
	/*1.正常运行,编译通过*/
	const int *conptrA = &tempA;
	const int *conptrB = &conTempA;
	const int *conptrC = &conexprTempA;
 
	/*2.局部变量的地址要运行时才能确认，故不能在编译期决定，编译不过*/
	constexpr int *conexprPtrA = &tempA;
	constexpr int *conexprPtrB = &conTempA;
	constexpr int *conexprPtrC = &conexprTempA;
 
	/*3.第一个通过，后面两个不过,因为constexpr int *所限定的是指针是常量，故不能将常量的地址赋给顶层const*/
	constexpr int *conexprPtrD = &g_tempA;
	constexpr int *conexprPtrE = &g_conTempA;
	constexpr int *conexprPtrF = &g_conexprTempA;
 
	/*4.局部变量的地址要运行时才能确认，故不能在编译期决定，编译不过*/
	constexpr const int *conexprConPtrA = &tempA;
	constexpr const int *conexprConPtrB = &conTempA;
	constexpr const int *conexprConPtrC = &conexprTempA;
	/*5.正常运行，编译通过*/
	constexpr const int *conexprConPtrD = &g_tempA;
	constexpr const int *conexprConPtrE = &g_conTempA;
	constexpr const int *conexprConPtrF = &g_conexprTempA;
 
	return 0;
}