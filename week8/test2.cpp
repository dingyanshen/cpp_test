/*
习题2
定义一个类A，使得程序只能创建一个类A的对象，当试图创建类A的第二个对象时，返回第一个对象的指针。
*/
#include <iostream>
using namespace std;
class A{
    private:
        A(){}
        static A* p;
    public:
        static A * getA(){
            if(p!=NULL)
                return p;
            p = new A();
            return p;
        }
};
A* A::p=NULL;
int main(){
    A* p1 = A::getA();
    A* p2 = A::getA();
    cout<<p1<<endl;
    cout<<p2<<endl;
    return 0;
}
