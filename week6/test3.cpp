//从节点1到节点8有多少条路径？
#include <iostream>
using namespace std;

int f(int n){
    if(n==1||n==2)
        return 1;
    if(n%2==0)
        return f(n-1)+f(n-2)+f(n-3);
    else
        return f(n-1)+f(n-2);
}

int main()
{
    cout<<"test3:"<<endl;
    cout<<f(8)<<endl;
    return 0;
}
