//以字符串的形式读入两个很长的字符串。这两个字符串的内容都是十进制数字，编写程序计算第一个字符串减去第二个字符串的差，以字符串形式输出。
//数据范围：输入字符串长度不超过200位。字符串仅由'0'~‘9’构成。且第一个字符串大于第二个字符串。
//注意：long long 类型存不下200位的十进制数，会溢出。
//Input
//两个字符串，长度都不超过200位。字符串仅由'0'~‘9’构成。
//Output
//一个字符串。是第一个字符串减去第二个字符串的差。
//Sample Input 1
//33333333333333333333
//22222222222222222222
//Sample Output 1
//11111111111111111111



#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    int x;
    Node * next;
};

Node* reLink(Node* head){
    if(head==NULL)
        return head;
    else if(head->next==NULL)
        return head;
    else{
        Node* p1,*p2,*p3;
        p1=head;
        p2=p1->next;
        p3=p2->next;

        p2->next=p1;
        p1->next=NULL;

        p1=p2;
        p2=p3;
        while(p3!=NULL){
            p3=p3->next;
            p2->next=p1;
            p1=p2;
            if(p3==NULL){
                return p2;
            }
            p2=p3;
        }
        return p1;
    }
}
Node* buildLink(char * C){

    //cout<<"iput nodes, end with -1"<<endl;
    int len = strlen(C);
    int countIndex=0;
    int i;
    //cin>>i;
    i=C[countIndex++]-'0';
    if(i==-1)
        return NULL;

    Node* head= NULL;
    Node* p= NULL;
    Node* q = new Node;
    q->x=i;
    q->next=NULL;
    head = q;
    p= q;

    //cin>>i;
    i=C[countIndex++]-'0';
    while(i!='\0'-'0'){
        Node* q = new Node;
        q->x=i;
        q->next=NULL;
        p->next=q;
        p=p->next;

        //cin>>i;
        i=C[countIndex++]-'0';
    }
    return head;
}
void printLink(Node* q){
    while(q!=NULL){
        cout<<q->x;
        q=q->next;
    }
    cout<<endl;
}
void deleteLink(Node* p){
    Node* q=p;
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
}
Node* subLink(Node* a,Node* b){
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    Node* a1 = reLink(a);
    //printLink(a1);
    Node* b1 = reLink(b);
    //printLink(b1);
    Node*pa=a1;
    Node*pb=b1;
    Node* ret = new Node;
    ret->x=0;
    Node* p=ret;
    int carry = 0;
    while(pa!=NULL||pb!=NULL||carry!=0){
        int sum=((pa!=NULL)?pa->x:0)-((pb!=NULL)?pb->x:0)-carry;
        //int x1 = (pa!=NULL)?pa->x:0;
        //int x2 = (pb!=NULL)?pb->x:0;
        //cout<<"sum"<<sum<<":"<<"x1:"<<x1<<" x2:"<<x2<<" C"<<carry<<endl;
        carry=(sum<0)?1:0;
        sum=(sum<0)?sum+10:sum;

        p->x=sum;
        if(pa!=NULL)
            pa=pa->next;
        if(pb!=NULL)
            pb=pb->next;
        if(pa==NULL&&pb==NULL&&carry==0){
            p->next = NULL;
        }
        else{

            p->next = new Node();
            p=p->next;
            p->next=NULL;
            p->x=0;
        }

    }
    reLink(a1);
    reLink(b1);
    ret = reLink(ret);
    if(ret!=NULL&&ret->x==0&&ret->next!=NULL){Node* pd=ret;ret=ret->next;delete pd;}
    //printLink(ret);
    return ret;
}
char A[202];
char B[202];

int main()
{
    cin>>A>>B;

    Node* p = buildLink(A);
    //printLink(p);
    Node* q = buildLink(B);
    //printLink(q);
    Node* ans = subLink(p,q);
    //cout<<"-------"<<endl;
    //printLink(p);
    //cout<<"+"<<endl;
    //printLink(q);
    //cout<<"="<<endl;
    printLink(ans);
    deleteLink(p);
    deleteLink(q);
    deleteLink(ans);
    return 0;
}




