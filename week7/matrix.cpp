/*
习题2
N*N幻方。（打印N=9 幻方）N为奇数。在N*N方阵中，填入1,2，，，N*N各个数，使得行、列、两对角线和相等。
当N为奇数时，我们可以通过以下方法构建一个幻方：
首先将1写在第一行的中间。之后，按如下方式从小到大依次填写每个数K(K=2,3,…,N*N)：
1.若(K−1)在第一行但不在最后一列，则将K填在最后一行，(K−1)所在列的右一列；
2.若(K−1)在最后一列但不在第一行，则将K填在第一列，(K−1)所在行的上一行；
3.若(K−1)在第一行最后一列，则将K填在(K−1)的正下方；
4.若(K−1)既不在第一行，也不在最后一列，如果(K−1)的右上方还未填数，则将K填在(K−1)的右上方，否则将K填在(K−1)的正下方。
*/
#include <iostream>
using namespace std;
int printMatrix(int n){
    if (n%2==0){
        cout<<"N为偶数。退出打印幻方"<<endl;
        return -1;
    }
    int A[99][99]={0};
    for(int i=0;i<99;i++)
        for(int j=0;j<99;j++)
            A[i][j]=0;

    int x=0,y=n/2,k=1;
    A[x][y]=k;
    k++;
    for(;k<=n*n;k++){
        if(x==0&&y!=n-1){
            x=n-1;
            y=y+1;

        }
        else if(y==n-1&&x!=0){
            x=x-1;
            y=0;
        }
        else if(y==n-1&&x==0){
            x=x+1;
        }
        else if(y!=n-1&&x!=0){
            if(A[x-1][y+1]==0){
                x=x-1;
                y=y+1;
            }
            else{
                x=x+1;
            }
        }
        A[x][y]=k;
        //cout<<k<<":"<<x<<","<<y<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;


}
int main(){
    printMatrix(9);
}
