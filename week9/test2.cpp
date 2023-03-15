/*
构造一个文件，每行若干英语单词，共若干行。
编写程序统计一个文本文件中某个字符串出现的次数，并输出对应出现次数，出现位置。
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void makefile(const char* file1){//也可使用命令构造文件 echo -e "aaa bbb\n ccc aaa">file1.txt
    ofstream f1(file1,ios::out);
    if(!f1) {
        cout<<"file error";
        return ;
    }
    f1<<"aaa bbb abc abc \n cccabc aaa";
    f1.close();
}
void printfile(const char* file1){
    ifstream f(file1);
    string s;
    while(getline(f,s)){
        cout<<s<<endl;
    }
    f.close();
}

    void scanStringFromFile(const char *filename,const char *str) {
        ifstream fin(filename);
        if(!fin){
            cout<<"file error"<<endl;
            return ;
        }
        string line;
        int lineNum=0;
        int count=0;
        while(getline(fin,line)){
            lineNum++;
            int begin=-1;

            while((begin=line.find(str,begin+1))!=string::npos){
                count++;
                cout<<count<<" @ "<<lineNum<<" line:"<<begin<<" col "<<endl;

            }

        }
        cout<<"find "<<count<<endl;
    }
int main(){
    const char* filename="file1.txt";
    const char* str="abc";
    makefile(filename);
    printfile(filename);

    scanStringFromFile(filename,str);

}
