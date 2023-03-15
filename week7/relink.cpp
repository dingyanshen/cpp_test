//反转 链表 【简单】
//输入一个长度为 n 链表，反转链表后，输出新链表。
//例如：链表 1 为 9->3->7 ，反转后，链表为 7->3->9
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
int main()
{

    Node* p = buildLink();
    printLink(p);
    Node* q = reLink(p);
    printLink(q);
    deleteLink(q);
    return 0;
}
