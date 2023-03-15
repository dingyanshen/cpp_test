/*
使用操作符重载，给出完整的复数定义。
包括加法+ 输入>> 输出<< 以及++ += ==
class Complex{
    double real,imag;
    //其它
}

*/
#include<iostream>
using namespace std;
class Complex{

    double real,imag;
public:
    Complex(){real=imag=0;}
    Complex(double r,double i){real=r;imag=i;}
    void display(){cout<<real<<"+"<<imag<<"i"<<endl;}
    friend ostream& operator<<( ostream& os,Complex& c){
        os<<c.real<<"+"<<c.imag<<"i";
        return os;
    }
    friend istream& operator>>(istream& is,Complex& c){
        is>>c.real>>c.imag;
        return is;
    }
    friend Complex& operator++(Complex& c){
        c.real++;
        return c;
    }
    friend Complex operator++(Complex& c,int a){
        Complex d(c);
        c.real++;
        return d;
    }
    Complex& operator+=(const Complex& i ){
        *this = *this + i;
        return *this;
    }
    bool operator==(const Complex& i){
        return real==i.real&& imag==i.imag;
    }

	friend Complex operator + (const Complex& c1, const Complex& c2);
	friend Complex operator + (const Complex& c1,double d);
	friend Complex operator + (double d,const Complex& c1);
	friend Complex operator - (const Complex& c1, const Complex& c2);
	friend Complex operator - (const Complex& c1,double d);
	friend Complex operator - (double d,const Complex& c1);
} ;
Complex operator + (const Complex& c1, const Complex& c2){
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator + (const Complex& c1,double d){
    return Complex(c1.real+d,c1.imag);
}
Complex operator + (double d,const Complex& c1){
    return Complex(c1.real+d,c1.imag);
}
Complex operator - (const Complex& c1, const Complex& c2){
    return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
Complex operator - (const Complex& c1,double d){
    return Complex(c1.real-d,c1.imag);
}
Complex operator - (double d,const Complex& c1){
    return Complex(d-c1.real,-(c1.imag));
}
int main(){
    Complex c(1,2);
    cout<<c<<endl;
    ++c;
    c++;
    cout<<c<<endl;
    Complex d(0,2);
    cin>>d;
    cout<<d<<endl;
    Complex e=1+c+d+2-1;
    cout<<e<<endl;
    return 0;
}
