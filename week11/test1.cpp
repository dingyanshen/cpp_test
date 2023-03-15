//习题1
//输入文件是 "上证指数2021-日期-时间-开-高-低-收-成交量-成交额.csv"
//下载方式 git clone https://gitee.com/cpp-njuer-org/book
//数据文件位于~/book/test/week11/上证指数2021-日期-时间-开-高-低-收-成交量-成交额.csv"
//数据样例：
//2021-01-06 15:00 3549.38 3550.91 3549.38 3550.88 4617728 6464176128
//各数据项分别代表上证指数关于日期-时间-开-高-低-收-成交量-成交额的数据。
//编程计算,仅从2021年每日收盘指数看，连续上涨时间最长的区间是从哪天到哪天？
//编程计算,仅从2021年每日收盘指数看，连续下跌时间最长的区间是从哪天到哪天？
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
struct Point{
    string timeDate;
    double p;
    Point(string d1, double p1):timeDate(d1),p(p1){}
};
int readData(const char * filename,vector<Point>& data){
    ifstream ifs(filename);
    if(!ifs){
        cout<<"file error"<<endl;
        return -1;
    }
    string date,time;
    double d[6];
    while(ifs>>date){
        ifs>>time;
        for(int i=0;i<6;i++) ifs>>d[i];
        if(time=="15:00"){
            data.push_back(Point(date,d[3]));
        }

    }
    return 0;
}
int max(int a,int b){
    return a>b?a:b;
}
int computeData(vector<Point>& data,vector<Point>& ansUp,vector<Point>& ansDown){
    int upIndex1=0;
    int upIndex2=0;
    int tempUpIndex1=0;
    int downIndex1=0;
    int downIndex2=0;
    int tempDownIndex1=0;
    if(data.size()==0)
        return -1;
    double lastUpPoint=data[0].p;
    double lastDownPoint=data[0].p;
    int upLen=1;
    int downLen=1;
    for(int i=1;i<data.size();i++){
        while(i<data.size()&&data[i].p>=data[i-1].p){
            i++;
        }
        int tempUpLen=i-tempUpIndex1;
        if(upLen<tempUpLen){
            upIndex1=tempUpIndex1;
            upIndex2=i-1;
            upLen=tempUpLen;
        }
        tempUpIndex1=i;
    }
    for(int i=1;i<data.size();i++){
        while(i<data.size()&&data[i].p<=data[i-1].p){
            i++;
        }
        int tempDownLen=i-tempDownIndex1;
        if(downLen<tempDownLen){
            downIndex1=tempDownIndex1;
            downIndex2=i-1;
            downLen=tempDownLen;
        }
        tempDownIndex1=i;
    }
    for(int i=upIndex1;i<=upIndex2;i++)
        ansUp.push_back(data[i]);
    for(int i=downIndex1;i<=downIndex2;i++)
        ansDown.push_back(data[i]);
    return 0;
}
int main(){
    vector<Point> data;
    vector<Point> ansUp;
    vector<Point> ansDown;
    if(readData("上证指数2021-日期-时间-开-高-低-收-成交量-成交额.csv",data)!=0)
        return -1;
    //for(int i=0;i<data.size();i++){
        //cout<<data[i].timeDate<<","<<data[i].p<<endl;
    //}

    computeData(data,ansUp,ansDown);
    cout<<"连续上涨区间最长天数="<<ansUp.size()<<endl;
    cout<<"连续下跌区间最长天数="<<ansDown.size()<<endl;
    for(int i=0;i<ansUp.size();i++){
        cout<<ansUp[i].timeDate<<","<<ansUp[i].p<<",";//<<endl;
    }
    cout<<endl;
    for(int i=0;i<ansDown.size();i++){
        cout<<ansDown[i].timeDate<<","<<ansDown[i].p<<",";//<<endl;
    }
    cout<<endl;
    return 0;
}

