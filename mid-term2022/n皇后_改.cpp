//在n*n的棋盘，有n个皇后棋子
//任意的两个皇后都不在同一条横、竖、斜线上，
//棋盘中有一些位置不能放任何皇后。
//问总共有多少种放法？n小于等于8。
//测试用例：
//4
//1 0 1 1
//1 1 1 1
//1 1 1 1
//1 1 1 1
//1
#include <iostream>
using namespace std;
int chess[100]={0};
int count=0;
int M[9][9];
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
        ++count;
        //cout<<++count<<":";
        for(int i=0;i<max;i++){
          //  cout<<chess[i]<<",";
        }
//        cout<<endl;
        return 0;
    }
    for(int i=0;i<max;i++){
        if(M[n][i]==1&&isOK(n,i)){
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
  int n;
  cin>>n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>M[i][j];
    }
  }

    cout<< slove(n)<<endl;
    return 0;
}



