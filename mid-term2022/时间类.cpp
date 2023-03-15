//测试用例
//12 12 59
//12:13:0
#include <iostream>
using namespace std;
class Time{
    public:
        Time(){}
        Time(int h,int m,int s){this->h=h;this->m=m;this->s=s;}
        void app(){
            s++;
            if(s==60)
            {
                s=0;
                m++;
                if(m==60)
                {
                    m=0;
                    h++;
                    if(h==24)
                    {h=0;}
                }
            }
        }
        void display(){cout<<h<<":"<<m<<":"<<s;}

    private:
        int h;
        int m;
        int s;

};



int main() {
    int h,m,s;
    std::cin >>h>>m>>s;
    Time t(h,m,s);
    t.app();
    t.display();
    return 0;
}


