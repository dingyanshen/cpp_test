/*
 *翻转字符串
 *Description
 *
 *以字符串的形式读入一个很长的字符串。将字符串翻转输出。
 *
 *数据范围：输入字符串长度不超过200位。字符串仅由'0'~‘9’，'a'~'z‘，'A'~'Z'构成。
 *
 *
 *Input
 *以字符串的形式读入一个很长的字符串。输入字符串长度不超过200位。字符串非空
 *
 *
 *Output
 *将字符串翻转输出。
 *
 *
 *Sample Input 1
 *
 *abc123
 *Sample Output 1
 *
 *321cba
 */
#include <iostream>
#include <string.h>
using namespace std;
char A[200];
int main(){
  cin >>A;
  int len = strlen(A);
  for (int i=0;i<len/2;i++){
    int temp = A[i];
    A[i]=A[len-i-1];
    A[len-i-1]=temp;
  }
  cout<<A;
}
