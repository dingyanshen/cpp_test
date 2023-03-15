/*
 *习题3
 *TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。
 *对这两个类编写你自己的版本。
 */
// g++ ex_12_27.cpp test3.cpp -o a.out

#include <iostream>
#include <string>
#include <fstream>
#include "ex_12_27.h"

using namespace std;

void runQueries(ifstream& infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream ifs("in.txt");
    runQueries(ifs);
    return 0;
}


