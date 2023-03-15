//10阶台阶，每次只能上1级或者2级，走完这10级台阶共有多少种走法？
#include <iostream>
using namespace std;
int f(int n){
    if (n==1||n==0)
        return 1;
    return f(n-1)+f(n-2);
}
int main()
{
    cout<<"test2:"<<endl;
    cout<<f(10)<<endl;
    return 0;
}
