#include<iostream>
using namespace std;
char * strcpy(char* dst,const char * src){
    if(dst==NULL||src==NULL)
        return NULL;
    char* ret=dst;
    while((*dst++=*src++)!='\0');
    return ret;

}
int main(){
    char s[] = "asdf";
    char d[] = "hijk";
    char* f=new char[10];
    strcpy(f,s);
    cout<< f<<endl;
    return 0;
}
