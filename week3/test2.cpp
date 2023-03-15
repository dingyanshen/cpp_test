//2.使用迭代器编写二分查找算法
//biSearch2.cpp
#include<iostream>
#include<vector>
#include<string>
using std::string;using std::iterator;
using std::vector;
using std::cout;using std::endl;
int main(){
    vector<string> text{"a","ab","abc","abcd","abcdefghi"};
    for(auto s:text)
        cout<<s<<endl;



    auto beg = text.begin(),end=text.end();
    auto mid = beg+(end-beg)/2;
    string sought = "abc";

    while(mid!=end&&*mid!=sought){
        if(sought<*mid)
            end=mid;
        else
            beg=mid+1;
        mid=beg+(end-beg)/2;
    }

    if(*mid==sought){
        cout<<"found:"<<*mid<<"@"<<mid-text.begin()<<endl;
    }
    return 0;
}
//a
//ab
//abc
//abcd
//abcdefghi
//found:abc@2
