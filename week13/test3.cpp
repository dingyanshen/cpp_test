//重写书店程序，使用一个vector保存交易记录，使用不同算法完成处理。
//使用 sort 和10.3.1节中的 compareIsbn 函数来排序交易记录，
//然后使用 find 和 accumulate 求和。
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_item.h"
int main(){
    std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
    std::vector<Sales_item> vec;
    while (in_iter != in_eof)
        vec.push_back(*in_iter++);
    sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
        end = find_if(beg, vec.cend(),
        [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn()))
                    << std::endl;
    }
    return 0;
}

