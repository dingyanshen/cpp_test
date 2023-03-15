//编写一个递归函数，输出vector对象的内容。
//开关调试状态：
//CC -D NDEBUG coutVector.cpp 可以定义变量NDEBUG,避免检查开销
//等价于在文件里 #define NDEBUG

//改写使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。
//例如，每次调用时输出vector对象的大小。
//分别在打开和关闭调试器的情况下编译并执行这个程序。
#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;
#define NDEBUG
void printVec(vector<int> &vec){
#ifdef NDEBUG
    cout << "vector size: " << vec.size() << endl;
#endif
    if (!vec.empty()){
        auto tmp = vec.back();
        vec.pop_back();//尾端删除元素
        printVec(vec); cout << tmp << " ";
    }}
int main(){
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printVec(vec);    cout << endl;
    return 0;
}

