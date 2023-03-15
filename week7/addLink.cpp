//两个 链表生成相 加链表【中等】
//假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
//给定两个这种链表，请生成代表两个整数相加值的结果链表。
//例如：链表 1 为 9->3->7 ，链表 2 为 6->3 ，最后生成新的结果链表为 1->0->0->0 。
#include <iostream>
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
Node* buildLink(){

    cout<<"iput nodes, end with -1"<<endl;
    int i;
    cin>>i;
    if(i==-1)
        return NULL;

    Node* head= NULL;
    Node* p= NULL;
    Node* q = new Node;
    q->x=i;
    q->next=NULL;
    head = q;
    p= q;

    cin>>i;
    while(i!=-1){
        Node* q = new Node;
        q->x=i;
        q->next=NULL;
        p->next=q;
        p=p->next;

        cin>>i;
    }

    return head;



}
void printLink(Node* q){
    while(q!=NULL){
        cout<<"->"<<q->x;
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
Node* addLink(Node* a,Node* b){
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
        int sum=((pa!=NULL)?pa->x:0)+((pb!=NULL)?pb->x:0)+carry;
        //int x1 = (pa!=NULL)?pa->x:0;
        //int x2 = (pb!=NULL)?pb->x:0;
        //cout<<"sum"<<sum<<":"<<"x1:"<<x1<<" x2:"<<x2<<" C"<<carry<<endl;
        carry=sum/10;
        sum=sum%10;
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
    //printLink(ret);
    return ret;
}
int main()
{

    Node* p = buildLink();
    //printLink(p);
    Node* q = buildLink();
    //printLink(q);
    Node* ans = addLink(p,q);
    cout<<"-------"<<endl;
    printLink(p);
    cout<<"+"<<endl;
    printLink(q);
    cout<<"="<<endl;
    printLink(ans);
    deleteLink(p);
    deleteLink(q);
    deleteLink(ans);
    return 0;
}
