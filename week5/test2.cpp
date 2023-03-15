#include <iostream>
using namespace std;
bool huiwen(int a){
    int temp = a;
    int temp2 =0;
    while(temp!=0){
        temp2*=10;
        temp2+=temp%10;
        temp/=10;
    }
    if(temp2==a)
        return true;
    else
        return false;

}
int main(){
    int a=1231;
    if(huiwen(a)){
        cout<<a<<" is OK"<<endl;
    }
    else
        cout<<a<<" not OK"<<endl;
    return 0;
}
