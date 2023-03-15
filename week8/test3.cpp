/*
实现字符串类String，提供以下操作并调用执行。
判断子串是否在当前字符串里,bool is_substring(const String &sub_str)
查找子串并替换,返回替换次数,int replace(const char* find,const char* replace)

*/
#include <iostream>
//#include <string.h>
using namespace std;
/*
#include <string.h>
下面的strlen strcpy strncpy就不用写了
*/
size_t strlen(const char* str){
    if (str==NULL)
        return 0;
    int res=0;
    while (*str!='\0'){
        res++;
        str++;
    }
    return res;
}
char * strcpy(char* dst,const char * src){
    if(dst==NULL||src==NULL)
        return NULL;
    char* ret=dst;
    while((*dst++=*src++)!='\0');
    return ret;

}
char * strncpy(char* dst,const char * src,int n){
    if(dst==NULL||src==NULL)
        return NULL;
    char* ret=dst;
    int count=0;
    while(count<n&&(*dst++=*src++)!='\0'){count++;};
    return ret;

}
class String{
    private:
        char* data;


    public:

        String(){//无参构造函数
            data = new char[1];
            data[0]='\0';
        }
        String(const char* str){//带参构造函数
            if(str==NULL){
                data = new char[1];
                data[0]='\0';
            }
            else{
                data = new char[strlen(str)+1];
                strcpy(data,str);
            }
        }
        String(const String& str){//拷贝构造函数
            this->data = new char[strlen(str.data) + 1];
            strcpy(this->data, str.data);
        }
        ~String(){
            if(data!=NULL){
                delete []data;
            }
        }

        bool is_substring(const String & sub_str){
            char* p1 = this->data;
            char* p2 = sub_str.data;
            int cnt;
            while (*p1!='\0')//not end of str
            {
                cnt=0;//clear tmp inner cursor
                while (*(p1+cnt)!='\0' && *(p2+cnt)!='\0')//not end of both str
                {
                    if (*(p1+cnt) != *(p2+cnt))
                        break;//do not use continue
                    cnt++;
                }
                if ('\0' == *(p2+cnt))//bingo!
                    return true;
                p1++;
            }
            return false;
        }
        int find_str(const char* sub_str){//返回子串出现的位置
            char* p1 = this->data;
            const char* p2 = sub_str;
            int cnt;
            while (*p1!='\0')//not end of str
            {
                cnt=0;//clear tmp inner cursor
                while (*(p1+cnt)!='\0' && *(p2+cnt)!='\0')//not end of both str
                {
                    if (*(p1+cnt) != *(p2+cnt))
                        break;//do not use continue
                    cnt++;
                }
                if ('\0' == *(p2+cnt))//bingo!
                    return p1-this->data;
                p1++;
            }
            return -1;


        }
        char* replace1(int pos, int len,const char* str){//从pos开始，len长度的子串替换为str
            char* newdata=NULL;
            if(len<strlen(str))
                newdata = new char[strlen(data)+(strlen(str)-len)+1];
            else
                newdata = data;
            strncpy(newdata,data,pos);
            strcpy(newdata+pos,str);
            strcpy(newdata+pos+strlen(str),data+pos+len);
            if(len<strlen(str))
                delete[] data;
            data = newdata;
            return data;
        }
        int replace(const char* find,const char* replace){
            int pos = find_str(find);
            int count=0;
            while(pos!=-1){
                replace1(pos,strlen(find),replace);
                count++;
                pos = find_str(find);
            }
            return count;
        }
        void display(){
            cout<<data<<" ";
        }


};
int main(){
    String str1=String("abc");
    String str2=String("abcd");
    str1.display();
    cout<<"is substring of ";
    str2.display();
    cout<<":";
    cout<<str2.is_substring(str1)<<endl;
    cout<<"find cdd from ";str2.display();cout<<":";
    cout<<str2.find_str("cdd")<<endl;;
    cout<<"relpace ";str2.display();cout<<" 1,2,e=";
    cout<<str2.replace1(1,2,"e");
    cout<<endl;
    cout<<"relpace ";str1.display();cout<<" a ee=";
    str1.replace("a","ee");
    str1.display();
}
