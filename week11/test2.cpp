//习题2
//设计一个类，它有三个unsigned成员，分别表示年、月和日。
//为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能
//处理不同的数据格式，如1月1日1990年、January 1,1900、1/1/1990、Jan 1 1900 等。


#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>
using namespace std;

// convert string to wstring
inline std::wstring s2ws(const std::string& input)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t> > converter;
    return converter.from_bytes(input);
}
// convert wstring to string
inline std::string ws2s(const std::wstring& input)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t> > converter;
    return converter.to_bytes(input);
}


class My_date{
private:
    unsigned year, month, day;
public:
    My_date(const wstring &s){
        wdate(s);
    }
    void wdate(const wstring &s){
        //1月1日1990年
        //cout<<ws2s(s)<<endl;
        this->day = stoi(s.substr(s.find_first_of(L"月")+1, s.find_first_of(L"日")-s.find_first_of(L"月")));
        this->month = stoi(s.substr(0, s.find_first_of(L"月")));
        this->year = stoi(s.substr(s.find_last_of(L"日") + 1, 4));
        //cout<<"day="<<day<<" month="<<month<<" year="<<year<<endl;
    }

    My_date(const string &s){

        unsigned tag;
        unsigned format;
        format = tag = 0;

        //1月1日1990年
        if(s.find_first_of("年")!= string::npos){
            format = 0x00;
        }
       // 1/1/1900
        if(s.find_first_of("/")!= string :: npos)
        {
            format = 0x01;
        }

        // January 1, 1900 or Jan 1, 1900
        if((s.find_first_of(',') >= 4)
                && s.find_first_of(',')!= string :: npos){
            format = 0x10;
        }
        else{ // Jan 1 1900
            if(s.find_first_of(' ') >= 3
                && s.find_first_of(' ')!= string :: npos){
                format = 0x10;
                tag = 1;
            }
        }
       switch(format){

        //1月1日1990年
        case 0x00:
            wdate(s2ws(s));
            break;

       // 1/1/1900
        case 0x01:
            day = stoi(s.substr(0, s.find_first_of("/")));
            month = stoi(s.substr(s.find_first_of("/")
                    + 1, s.find_last_of("/")- s.find_first_of("/")));
            year = stoi(s.substr(s.find_last_of("/") + 1, 4));

        break;
       case 0x10:
            if( s.find("Jan") < s.size() )  month = 1;
            if( s.find("Feb") < s.size() )  month = 2;
            if( s.find("Mar") < s.size() )  month = 3;
            if( s.find("Apr") < s.size() )  month = 4;
            if( s.find("May") < s.size() )  month = 5;
            if( s.find("Jun") < s.size() )  month = 6;
            if( s.find("Jul") < s.size() )  month = 7;
            if( s.find("Aug") < s.size() )  month = 8;
            if( s.find("Sep") < s.size() )  month = 9;
            if( s.find("Oct") < s.size() )  month =10;
            if( s.find("Nov") < s.size() )  month =11;
            if( s.find("Dec") < s.size() )  month =12;
            char chr = ',';
            if(tag == 1){
                chr = ' ';
            }
            day = stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(chr) - s.find_first_of("123456789")));
            year = stoi(s.substr(s.find_last_of(' ') + 1, 4));
            break;
        }

            //cout<<"day="<<day<<" month="<<month<<" year="<<year<<endl;
    }


    void print(){
        cout << "day:" << day << " " << "month: " << month << " " << "year: " << this->year;
    }
};
int main()
{
    //wstring s=L"1月1日1990年";
    //cout<<s.find_first_of(L"今天");
    //My_date d("Jan 1 1900");
    //My_date d(L"1月1日1990年");
    My_date d("1月1日1990年");
    d.print();
    return 0;
}


