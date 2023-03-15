//编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词，
//所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续
//重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的
//最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。
//例如：如果输入是：
//how now now now brown cow cow
//那么输出应该表明单词now连续出现了3次。
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string; using std::pair;
int main()
{
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr) ++count;
            else count = 0;
        if (count > max_duplicated.second) max_duplicated = { prestr, count };
    }
    if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
    else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
    return 0;
}
