#include <iostream>
using namespace std;
void f(){
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=1;k<10;k++){
                if ((k*100+j*10+i)==(i*i*i+j*j*j+k*k*k))
                    cout<<k*100+j*10+i<<endl;
            }
        }
    }
}
int main(){
    f();
    return 0;
}
