//给定一个包含10 个元素的vector，将位置1到6之间的元素按逆序拷贝到一个list中。

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> l;

    copy(v.crbegin()+(10-1-6), v.crbegin() + (10-1-1+1), back_inserter(l));

    for (auto i : l) std::cout << i << " ";
    cout << endl;
    return 0;
}


