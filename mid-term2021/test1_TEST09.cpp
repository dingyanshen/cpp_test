/*
 *红白皇后
 *Description
 *
 *在n*n的棋盘，有n个红皇后棋子，还有n个白皇后棋子，
 *
 *任意的两个红皇后都不在同一条横、竖、斜线上，
 *
 *任意的两个白皇后都不在同一条横、竖、斜线上。
 *
 *棋盘中有一些位置不能放任何皇后。
 *
 *问总共有多少种放法？n小于等于8。
 *
 *
 *Input
 *输入描述:
 *
 *输入的第一行为一个整数n，表示棋盘的大小。
 *
 *接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
 *
 *输入样例:
 *
 *4
 *
 *1 1 1 1
 *
 *1 1 1 1
 *
 *1 1 1 1
 *
 *1 1 1 1
 *
 *
 *Output
 *输出描述:
 *
 *输出一个整数，表示总共有多少种放法。
 *
 *输出样例:
 *
 *2
 *
 *
 *
 */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n,ans;
int a[10][10];
int black_location[10],white_location[10];//不喜欢用全局变量可以写在main（）函数中指针调用
void print(){
    for(int i=1;i<=n;i++)
        cout<<black_location[i]<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++)
        cout<<white_location[i]<<" ";
    cout<<endl;
    cout<<endl;
}
int vaild_white(int row,int conlumn)
{
	for(int i=1;i<row;i++)
		if(conlumn==white_location[i]||abs(row-i)==abs(conlumn-white_location[i]))
			return 0;
	return 1;
}
int vaild_black(int row,int conlumn)
{
	for(int i=1;i<row;i++)
	{
		if(conlumn==black_location[i]||abs(row-i)==abs(conlumn-black_location[i]))
			return 0;

	}
		return 1;
}
void Queen_black(int row)
{
	if(row==n+1)
	{
		ans++;
		//return ;
        //print();
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(a[row][i]==0||i==white_location[row])
				continue ;
			else if(vaild_black(row,i))
			{
				black_location[row]=i;
				Queen_black(row+1);
			}
	}
}
void Queen_white(int row)
{
	if(row==n+1)
	{
		Queen_black(1);
		return ;

	}
	else
	{
		for(int i=1;i<=n;i++)
			if(a[row][i]==0)
				continue;
			else if(vaild_white(row,i))
			{
				white_location[row]=i;
				Queen_white(row+1);
			}
	}

}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	Queen_white(1);
	printf("%d",ans);
	return 0;

}
