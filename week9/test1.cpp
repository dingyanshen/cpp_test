/*
构造一个文件，每行若干英语单词，共若干行。编写一个拷贝程序，能把这个文件的内容复制到另一个文件中。
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void makefile(const char* file1){//也可使用命令构造文件 echo -e "aaa bbb\n ccc aaa">file1.txt
    ofstream f1(file1,ios::out);
    if(!f1) {
        cout<<"file error";
        return ;
    }
    f1<<"aaa bbb\n ccc aaa";
    f1.close();
}
void copyfile(const char* from,const char* to){
    ifstream f_from(from);
    if(!f_from) {
        cout<<"file error";
        return ;
    }
    ofstream f_to(to);
    string s ;
    while(getline(f_from,s)){
        f_to<<s<<endl;
    }
    f_from.close();
    f_to.close();
}
void printfile(const char* file1){
    ifstream f(file1);
    string s;
    while(getline(f,s)){
        cout<<s<<endl;
    }
    f.close();
}
int main(){
    const char* filename="file1.txt";
    const char* filename2="file2.txt";
    makefile(filename);
    printfile(filename);
    copyfile(filename,filename2);
    printfile(filename2);
}
