//编写一段程序，从标准输入中读取string对象的序列直到
//连续出现两个相同的单词或者所有的单词都读完为止。
//使用while循环一次读取一个单词，当一个单词连续出现两次时
//使用break语句终止循环。
//输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;
int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp) break; else tmp = read;

    if (cin.eof())  cout << "no word was repeated." << endl;
    //eof(end of file)判断输入是否结束,或者文件结束符
    else cout << read << " occurs twice in succession." << endl;

    return 0;
}
