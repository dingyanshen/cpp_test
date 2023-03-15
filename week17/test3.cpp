/* 习题
习题3
定义一个int型元素的线性表类LinearList，可以返回元素个数，
查找元素返回位置，在指定位置插入、删除元素。
再利用LinearList通过组合或继承，定义一个队列类，提供入队和出队功能。

*/
#include<iostream>
using namespace std;
struct Node{
    int num;
    Node* next;
};
class LinearList{
    Node * p;
public:
    LinearList(){p=nullptr;}
    int getLen(){
        if(p==nullptr)
            return 0;
        Node* p1=p;
        int len=0;
        while(p1!=nullptr){
            p1=p1->next;
            len++;
        }

        return len;}
    int search(int i){
        if(p==nullptr)
            return -1;
        Node* p1=p;
        int count=0;
        while(p1!=nullptr){
            if(p1->num==i){
                return count;
            }
            count++;
        }
        if(p1==nullptr)
            return -1;


    }
    void get(int n1){
        if(p==nullptr){
            p=new Node;
            p->num=n1;
            p->next=nullptr;
            return;
        }
        Node* p1=p;
        while (p1->next!=nullptr){
            p1=p1->next;
        }
        p1->next=new Node;
        p1=p1->next;
        p1->num=n1;
        p1->next=nullptr;
    }
    int insert(int index,int num){
        int len=getLen();
        //cout<<"len="<<len;
        if(index>len){
            cout<<"error";
            return -1;
        }
        if(len==0){
            if(index==0){
                get(num);
                return index;
            }
            cout<<"error";
            return -1;
        }
        if(index==0){
            Node*p1=new Node;
            p1->num=num;
            p1->next=p;
            p=p1;
            return 0;
        }
        int count=0;
        Node* p1=p;
        while(count<index-1){
            p1=p1->next;
            count++;
        }
        Node * p2=new Node;
        p2->num=num;
        p2->next=p1->next;
        p1->next=p2;
        return 0;
    }
    int del(int index){
        int len=getLen();
        if(index>=len){
            cout<<"error";
            return -1;

        }
        if(index==0){
            Node *p1=p;
            p=p->next;
            int ans=p1->num;
            delete p1;
            return ans;
        }
        int count=0;
        Node*p1 = p;
        while(count<index-1){
            p1=p1->next;
            count++;
        }
        Node*p2 =p1->next;
        p1->next=p2->next;
        int ans = p2->num;
        delete p2;
        return ans;


    }
    void display() {
        Node* p1=p;
        while(p1!=nullptr){
            cout<<p1->num<<" ";
            p1=p1->next;
        }
        cout<<endl;
    }

};
class Queue:public LinearList{
public:
    Queue(){}
    int enqueue(int n1){
        //int last = getLen();
        //int ans= insert(last,n1);
        //cout<<"enqueue"<<endl;
        //display();
        int ans = insert(0,n1);
        cout<<"enqueue"<<endl;
        display();
       return ans;
    }
    int dequeue(int & n1){
        if(getLen()==0){
            cout<<"error";
            return -1;
        }
        return n1=del(getLen()-1);
    }
    int dequeue(){
        if(getLen()==0){
            cout<<"error";
            return -1;
        }
        int ans = del(getLen()-1);

        cout<<"dequeue"<<endl;
        display();
        return ans;
    }
};
int main(){
    Queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.dequeue();
    return 0;
}
