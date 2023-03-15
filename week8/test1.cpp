/*  习题1
实现时间类Time,提供以下操作并调用执行。
构造函数，Time(int h,int m,int s)
调整时间，void set(int h,int m,int s)
显示时间，void display()
比较时间，bool equal (Time & other_time)
*/
#include <iostream>
using namespace std;
class Time{
    private:
        int h,m,s;
    public:
        Time(){h=m=s=0;}
        Time(int h,int m,int s){
            this->m=m;
            this->h=h;
            this->s=s;
        }
        void set(int h,int m,int s){
            this->m=m;
            this->h=h;
            this->s=s;
        }
        bool equal(Time & t){
            if(t.h==h&&t.m==m&&t.s==s)
                return true;
            else
                return false;
        }
        void display(){
            cout<<h<<":"<<m<<":"<<s<<endl;
        }
};
int main(){
    Time t= Time(2,2,2);
    t.display();
    t.set(3,3,3);
    t.display();
    Time a= Time(2,2,2);
    a.display();
    if(a.equal(t))
        cout<<"equal"<<endl;
    else
        cout<<"not equal"<<endl;
    return 0;
}
