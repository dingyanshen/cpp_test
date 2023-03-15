//计算Ackermann函数的值 ack（2,2）
//ack（m,n）定义如下 m>=0,n>=0
//ack(0,n)=n+1
//ack(m,0)=ack(m-1,1)
//ack(m,n)=ack(m-1,ack(m,n-1))  (m>0,n>0)
#include <iostream>
using namespace std;



long int Ack(int m, int n){
    if(m<0||n<0) {cout<<"error"<<endl;return 0;}
    if(m==0)
        return n+1;
    else if(n==0)
        return Ack(m-1,1);
    else
        return Ack(m-1,Ack(m,n-1));
}
int main()
{
    cout<<"test1:"<<endl;
    cout<<Ack(2,2)<<endl;
    return 0;
}
