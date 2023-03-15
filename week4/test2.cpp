/*算数转换。如dval+ival是什么类型*/
#include <iostream>
using std:: cout;
using std:: endl;
#include <vector>
using std:: vector;
#include <string>
using std:: string;
int main()
{
        bool flag;
        char cval;
        short sval;
        unsigned short usval;
        int ival;
        unsigned int uival;
        long lval;
        unsigned long ulval;
        float fval;
        double dval;
        3.1415926L + 'a';       //'a'提升成int，然后int转成long double
        dval + ival;            //ival->double
        dval + fval;            //fval->double
        ival = dval;            //dval->int,⼩数部分丢弃
        flag = dval;            //如果dval⾮0则真
        cval + fval;            //cval提升为int，int转float
        sval + cval;            //sval cval ->int
        cval + lval;            //cval -> long
        ival + ulval;           //ival->unsigned int
        usval + ival;           //根据unsigned short 和 int 所占空间进⾏提升
        uival + lval;           //根据unsigned int   和 long所占空间⼤⼩进⾏转换
        cout<<"3.1415926L + 'a'"<<"\t"<<typeid(3.1415926L + 'a').name()<<endl;       //'a'提升成int，然后int转成long double
        cout<<"dval+ival"<<"\t"<<typeid( dval + ival).name()<<endl;           //ival->double
        cout<<" dval + fval"<<"\t"<<typeid(dval + fval).name()<<endl;                   //fval->double
        cout<<" ival = dval"<<"\t"<<typeid( ival = dval).name()<<endl;                  //dval->int,⼩数部分丢弃
        cout<<" flag = dval"<<"\t"<<typeid(flag = dval).name()<<endl;                 //如果dval⾮0则真
        cout<<" cval + fval"<<"\t"<<typeid( cval + fval).name()<<endl;                  //cval提升为int，int转float
        cout<<" sval + cval"<<"\t"<<typeid(sval + cval).name()<<endl;                   //sval cval ->int
        cout<<" cval + lval;"<<"\t"<<typeid( cval + lval).name()<<endl;                  //cval -> long
        cout<<" ival + ulval"<<"\t"<<typeid(ival + ulval).name()<<endl;                  //ival->unsigned int
        cout<<" usval + ival"<<"\t"<<typeid(usval + ival).name()<<endl;                  //根据unsigned short 和 int 所占空间进⾏提升
        cout<<" uival + lval"<<"\t"<<typeid(uival + lval).name()<<endl;                  //根据unsigned int   和 long所占空间⼤⼩进⾏转换
        return 0;
}
/*
 *
 *
 *  bool: b
　　char: c
　　signed char: a
　　unsigned char: h
　　(signed) short (int): s
　　unsigned short (int): t
　　(signed) (int): i
　　unsigned (int): j
　　(signed) long (int): l
　　unsigned long (int): m
　　(signed) long long (int): x
　　unsigned long long (int): y
　　float: f
　　double: d
　　long double: e
 *
 *
 */
