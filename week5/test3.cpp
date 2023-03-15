#include <iostream>
#include <iomanip>
using namespace std;
void pi(){
    long double i=1.0;
    long double temp=1.0/i;
    long double res=1.0;
    long double flag = 1.0;
    while((temp>0?temp:-temp)>1e-8){
        i+=2.0;
        temp = 1.0/i;
        flag = -flag;
        res+=(flag)*temp;
    }
    cout<<setprecision(9)<<4.0*res<<endl;
}
int main(){
    pi();
    return 0;
}
