//N 皇后 问题【较难】
//N 皇后问题是指在 n * n 的棋盘上要摆 n 个皇后，
//要求：任何两个皇后不同行，不同列也不再同一条斜线上，
//求给一个整数 n ，返回 n 皇后的摆法数。
//例如： 8 皇后摆法 92
#include <iostream>
using namespace std;
int chess[100]={0};
int count=0;
int abs(int n){
    return n>0?n:-n;
}
bool isOK(int index,int date){
    for(int i=0;i<index;i++){
        if(chess[i]==date||abs(i-index) == abs(chess[i]-date))
            return false;
    }
    return true;
}
int findQ(int n,int max){

    if (n==max){
        cout<<++count<<":";
        for(int i=0;i<max;i++){
            cout<<chess[i]<<",";
        }
        cout<<endl;
        return 0;
    }
    for(int i=0;i<max;i++){
        if(isOK(n,i)){
            chess[n]=i;
            findQ(n+1,max);
        }
    }

    return 0;

}
int slove(int max){
    findQ(0,max);
    return count;
}
int main()
{
    cout<< slove(4)<<endl;
    return 0;
}
//15皇后的解数目：2279184，耗时约2分钟
//20皇后的解数目：39029188884
