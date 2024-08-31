#include <iostream>
#include <future>
#include <thread>
#include <chrono>

//std::async返回一个 std::future<T>，它存储由 std::async()执行的函数对象返回的值

namespace test{
template<class Fn, class... Args>
std::future<typename std::result_of<Fn(Args...)>::type> 
async(std::launch policy, Fn&& fn, Args&&...args);
};

// std::async中的第一个参数是启动策略，它控制std::async的异步行为，我们可以用三种不同的启动策略来创建std::async
// ·std::launch::async
// 保证异步行为，即传递函数将在单独的线程中执行
// ·std::launch::deferred
// 当其他线程调用get()来访问共享状态时，将调用非异步行为
// ·std::launch::async | std::launch::deferred
// 默认行为。有了这个启动策略，它可以异步运行或不运行，这取决于系统的负载，但我们无法控制它。

std::string fetchDataFromDB(std::string recvData) {
  //确保函数要3秒才能执行完成
  std::this_thread::sleep_for(std::chrono::seconds(3));
 
  //处理创建数据库连接、获取数据等事情
  return "DB_" + recvData;
}
 
std::string fetchDataFromFile(std::string recvData) {
  //确保函数要3秒才能执行完成
  std::this_thread::sleep_for(std::chrono::seconds(3));
 
  //处理获取文件数据
  return "File_" + recvData;
}

int main(int argc, char* argv[]){
// [单线程操作]
{
  auto time_begin = std::chrono::system_clock::now(); 
  //从数据库获取数据
  std::string dbData = fetchDataFromDB("Data");
  //从文件获取数据
  std::string fileData = fetchDataFromFile("Data");
  auto time_end = std::chrono::system_clock::now();
  auto time_consume = std::chrono::duration_cast<std::chrono::seconds>(time_end-time_begin);
  std::cout << "[单线程操作]: " << time_consume.count() << " seconds\n";
}
// [多线程操作] 并行处理两个任务
{
  auto time_begin = std::chrono::system_clock::now();
  auto DBCallBack = std::async(std::launch::async, fetchDataFromDB, "Data");
  std::string fileData = fetchDataFromFile("Data");
  std::string dbData = DBCallBack.get();
  auto time_end = std::chrono::system_clock::now();
  auto time_consume = std::chrono::duration_cast<std::chrono::seconds>(time_end-time_begin);
  std::cout << "[多线程操作]: " << time_consume.count() << " seconds\n";
}
  return 0;
}

// 用Function对象作为回调调用std::async
struct DataFetcher {
  std::string operator ()(std::string recvdData) {
    //确保函数要5秒才能执行完成
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //处理获取文件数据
    return "File_" + recvdData;
  }
};
 
//用函数对象调用std::async
std::future<std::string> fileResult = std::async(DataFetcher(), "Data"); 


// 用lambda函数作为回调调用std::async
std::future<std::string> resultFromDB = std::async([](std::string recvdData) {
 
  std::this_thread::sleep_for(std::chrono::seconds(5));
  //处理创建数据库连接、获取数据等事情
  return "DB_" + recvdData;
 
}, "Data"); 