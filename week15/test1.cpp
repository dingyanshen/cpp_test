/*
 *习题1
 *使用 shared_ptr 而不是内置指针,编写函数，返回一个动态分配的 int 的vector。
 *将此vector 传递给另一个函数，这个函数读取标准输入，
 *将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。
 *
 */

#include <iostream>
#include <vector>
#include <memory>

using std::vector;

std::shared_ptr<vector<int>> alloc_vector()
{
    return std::make_shared<vector<int>>();
}

void assign_vector(std::shared_ptr<vector<int>> p)
{
    int i;
    while (std::cin >> i)
    {
        p->push_back(i);
    }
}

void print_vector(std::shared_ptr<vector<int>> p)
{
    for (auto i : *p)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);
    return 0;
}


