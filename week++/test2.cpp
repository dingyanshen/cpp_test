//习题
//用类模板定义一个类属的队列类
#include<iostream>
using namespace std;
template<typename T,int size>
class Queue{
private:
    T a[size+1];
    int count;
public:
    Queue(){
        for(int i=0;i<size;i++){
            a[i]=0;
        }
        count=0;
    }
    void enqueue(T data){
        if(count<=size){
            a[count++]=data;
        }
    }
    T dequeue(){
        T temp=a[0];
        for(int i=1;i<count;i++){
            a[i-1]=a[i];
        }
        count--;
        return temp;
    }
    T getHeadElem(){
        return a[0];
    }
    bool isfull(){
        if(count==size){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(count==0){
            return true;
        }
        return false;
    }
    void show(){
        if(count!=0){
            for(int i=0;i<count;i++){
            cout<<a[i]<<" ";
           }
        }
    }//队列没元素时，不打印任何
};
int main(){
    Queue<int,3> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.show();
    cout<<(q.dequeue());
    cout<<(q.dequeue());
    q.show();
    return 0;
}
