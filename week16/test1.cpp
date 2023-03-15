/*
 *习题1
 *给定下面的类框架，编写它的：
 *1)拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，
 *  并将对象拷贝到ps所指向的位置，而不是拷贝ps本身：
 *2)赋值运算符。类似拷贝构造函数，你的赋值运算符应该将对象拷贝到ps指向的位置。
 *3)一个析构函数。
 *4)移动赋值运算符
 *5)移动构造函数
 *并编写main函数并观察何时会调用这些函数。
 */
/*
 *
 *class HasPtr {
 *public:
 *    HasPtr(const std::string& s = std::string()):
 *        ps(new std::string(s)), i(0) { }
 *private:
 *    std::string *ps;
 *    int i;
 *}
 *
 */

#include<iostream>
#include<string>
using std::cout;
using std::endl;
class HasPtr {
public:
    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0) {
            cout<<"HasPtr(const std::string& s = std::string())"<<endl;
        }
    HasPtr(const HasPtr& a):ps(new std::string(*(a.ps))),i(a.i){
        cout<<"HasPtr(const HasPtr&)"<<endl;
    }
    HasPtr& operator=(const HasPtr& a){
        cout<<"HasPtr& operator=(const HasPtr& )"<<endl;
        if(this!=&a){
            auto p = new std::string(*(a.ps));
            delete ps;
            ps = p;
            i = a.i;

        }
        return *this;
    }
    ~HasPtr(){
        cout<<"~HasPtr()"<<endl;
        delete ps;
    }

    HasPtr& operator=(HasPtr&& a) noexcept {
        cout<<"HasPtr& operator=(HasPtr&& )"<<endl;
        if(this!=&a){
            delete ps;
            ps = a.ps;
            a.ps = nullptr;
            i = a.i;
        }
        return *this;
    }

    HasPtr(HasPtr&& a) noexcept {
        cout<<"HasPtr(HasPtr&& )"<<endl;
        ps = a.ps;
        a.ps = nullptr;
        i = a.i;
    }
private:
    std::string *ps;
    int i;
};

int main(){
    HasPtr a("abc");
    HasPtr b(a);
    b = a;
    HasPtr c(std::move(a));//HasPtr c = std::move(a);
    c = std::move(b);
    return 0;
}
