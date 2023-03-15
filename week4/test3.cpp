////仿照课本例题，使⽤sizeof，以字节为单位，计算常⻅类型所占内存空间⼤⼩。
#include <iostream>
using std:: cout;
using std:: endl;
#include <vector>
using std:: vector;
#include <string>
using std:: string;
int main()
{
        bool flag = 1;
        char cval = 1;
        short sval = 1;
        unsigned short usval = 1;
        int ival = 1;
        unsigned int uival = 1;
        long lval = 1;
        unsigned long ulval = 1;
        float fval = 1.0;
        double dval = 1.0;
        int ilst[10];
        char strc[] = "hello";
        string strcpp = "hello";
        vector< int > ivec(10);
        cout<<"bool:                    "<<sizeof(bool)<<" bytes"<<endl;
        cout<<"char:                    "<<sizeof(char)<<" bytes"<<endl;
        cout<<"short:                   "<<sizeof(short)<<" bytes"<<endl;
        cout<<"unsigned short:          "<<sizeof(usval)<<" bytes"<<endl;
        cout<<"int:                     "<<sizeof(int)<<" bytes"<<endl;
        cout<<"unsigned int:            "<<sizeof(uival)<<" bytes"<<endl;
        cout<<"long:                    "<<sizeof(long)<<" bytes"<<endl;
        cout<<"unsigned long:           "<<sizeof(ulval)<<" bytes"<<endl;
        cout<<"float:                   "<<sizeof(fval)<<" bytes"<<endl;
        cout<<"double:                  "<<sizeof(double)<<" bytes"<<endl;
        cout<<"int[10]:         "<<sizeof(ilst)<<" bytes"<<endl;
        cout<<"vector<int> (10)：       "<<sizeof(ivec)<<" bytes"<<endl;
        cout<<"char[] \"hello\":                "<<sizeof(strc)<<" bytes"<<endl;
        cout<<"string \"hello\":        "<<sizeof(strcpp)<<" bytes"<<endl;
        return 0;
}
