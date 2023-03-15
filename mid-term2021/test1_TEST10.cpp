/*
 *使用链表解决约瑟夫问题
 *Description
 *
 *编号为 1到 n的 n个人围成一圈。从编号为 1的人开始报数，报到 m的人离开。
 *
 *下一个人继续从 1开始报数。
 *
 *n-1 轮结束以后，只剩下一个人，问最后留下的这个人编号是多少？
 *
 *
 *
 *
 *数据范围：1 < n , m <10000
 *
 *
 *Input
 *输入两个正整数 n 和 m
 *
 *比如 5 2
 *
 *
 *Output
 *输出一个整数，是最后留下人的编号
 *
 *比如 3
 *
 *开始5个人 1，2，3，4，5 ，从1开始报数，1->1，2->2编号为2的人离开
 *
 *1，3，4，5，从3开始报数，3->1，4->2编号为4的人离开
 *
 *1，3，5，从5开始报数，5->1，1->2编号为1的人离开
 *
 *3，5，从3开始报数，3->1，5->2编号为5的人离开
 *
 *最后留下人的编号是3
 *
 *
 *Sample Input 1
 *
 *5 2
 *Sample Output 1
 *
 *3
 */
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
  struct ListNode {
      int val;
      ListNode *next, *pre;
      ListNode(int x) : val(x), next(NULL), pre(NULL) {}
  };

    int ysf(int n, int m) {
        // step1: build一个环形链表
        ListNode *head = new ListNode(1);
        ListNode *pre, *curr, *next;
        curr = head;
        pre = NULL;

        int count = 1;
        while(count < n) {
            count++;
            ListNode *node = new ListNode(count);
            curr->next = node;
            node->pre = curr;
            curr = curr->next;
        }
        curr->next = head;

        // step2 : 在链表内做算法
        int index = 1;
        curr = head;
        //cout << curr->val << endl;

        while(curr->next != curr) {
            if (++index == m) {
                curr->next = curr->next->next;
                index = 1;
            }
            curr = curr->next;
        }
        // 返回值
        return curr->val;
        // write code here
    }
};

int main(){
  Solution s;
  int n,m;
  cin>>n;
  cin>>m;
  cout<<s.ysf(n,m);
}
