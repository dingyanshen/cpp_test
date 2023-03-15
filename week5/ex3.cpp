//编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
//使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，
//询问其是否输入新数并重新执行try语句块的内容。
#include <iostream>
#include <stdexcept>
using std::cin; using std::cout; using std::endl; using std::runtime_error;
int main(void){
    for (int i, j; cout << "Input two integers:\n", cin >> i >> j; ){
        try {
            if (j == 0)
                throw runtime_error("divisor is 0");
            cout << i / j << endl;}
        catch (runtime_error err) {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;}
    }
    return 0;
}
