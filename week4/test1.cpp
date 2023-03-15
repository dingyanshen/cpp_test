/*位运算程序，设置学⽣成绩*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    const int max=20;
    int a[max] = {0};
    int j,m=0;
    unsigned long scores = 0;
    for(auto i : a){
        scores |= 1UL << i;
    }
    cout<< "input qualified student "<<endl;
    while(cin>>j){
        if (j>=max) continue;
        scores |= 1UL<<j;
    }
    cout<<endl;
    cout << "qualified student:"<<endl;
    for (int i=0;i<20;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(;m<20;m++){
        bool qualify = scores&(1UL<<m);
        cout << qualify <<"\t";
    }
    return 0;
}
