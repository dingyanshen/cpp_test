/*构造一个文件，每行若干英语单词，共若干行。
编写程序，把文件中英语单词按词频和字典次序排序，
将单词对应词频数一起输出到另一个文件中。
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
void makefile(const char *file1)
{ //也可使用命令构造文件 echo -e "aaa bbb\n ccc aaa">file1.txt
    ofstream f1(file1, ios::out);
    if (!f1)
    {
        cout << "file error";
        return;
    }
    f1 << "aaa bbb abc abc \n cccabc aaa ccabc ccabc";
    f1.close();
}
void printfile(const char *file1)
{
    ifstream f(file1);
    string s;
    while (getline(f, s))
    {
        cout << s << endl;
    }
    f.close();
}

void scanFile(const char *filename, map<string, int> &ans)
{
    ifstream fin(filename);
    if (!fin)
    {
        cout << "file error" << endl;
        return;
    }
    string word;

    while (!fin.eof() && fin >> word)
    {
        if (ans.count(word) == 0)
            ans[word] = 1;
        else
            ans[word]++;
    }
}
int main()
{
    const char *filename = "ted.txt";
    const char *str = "abc";
    //makefile(filename);
    //printfile(filename);

    map<string, int> ans;
    scanFile(filename, ans);
    vector<pair<string, int>> v;
    for (auto a : ans)
    {
        v.push_back(a);
        //cout << a.first << ":" << a.second << endl;
    }
    sort(v.begin(), v.end(), [](const pair<string,int>& a,const pair<string,int>&  b)
         {
             if(a.second>b.second){
                 return true;
             }
             else if(a.second < b.second){
                 return false;
             }
             else
                return a.first<b.first;
//             return (a.second > b.second);
         });
    ofstream ans_file("tedAns.txt",ios::out);
    if(!ans_file){
        cout<<"error file";
        return -1;
    }
    for(auto a:v)
    {
        cout << a.first << ":" << a.second << endl;
        ans_file<< a.first << ":" << a.second << endl;
    }
    ans_file.close();
    return 0;
}
