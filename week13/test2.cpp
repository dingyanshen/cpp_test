//编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
//输入文件保存的应该是整数。使用 istream_iterator 读取输入文件。
//使用 ostream_iterator 将奇数写入第一个输入文件，每个值后面都跟一个空格。
//将偶数写入第二个输出文件，每个值都独占一行。
//

#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 4) return -1;
    std::ifstream ifs(argv[1]);
    std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);
    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
    std::for_each(in, in_eof, [&out_odd, &out_even](const int i)
    {
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });
    return 0;
}
//g++ test2.cpp -o test2
// test2 in.txt out1.txt out2.txt
