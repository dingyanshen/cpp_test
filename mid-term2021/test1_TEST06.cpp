/*
 *排序
 *Description
 *
 *按从小到大的顺序对数列进行排序。数列长度为n。 1<=n<=200
 *
 *
 *Input
 *输入描述:
 *
 *第一行为一个整数n。
 *
 *第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
 *
 *输入样例:
 *
 *3
 *
 *3 2 1
 *
 *
 *Output
 *输出描述:
 *
 *输出一行，按从小到大的顺序输出排序后的数列。
 *
 *输出样例:
 *
 *1 2 3
 */
#include <iostream>
using namespace std;

int A[201];
int sort(){
  int n =0;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>A[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(A[j]>A[j+1]){
        int temp=A[j];
        A[j]=A[j+1];
        A[j+1]=temp;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
  }
  return 0;
}

int main()
{
  sort();
  return 0;
}
