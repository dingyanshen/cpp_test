//习题3
//使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。
//当你在一个左括号之后看到一个右括号，
//从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。
//然后将一个值（括号内的运算结果）push到栈中，
//表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。
//计算字符串"5 * ( 3 + 4 )" 的值

//双栈解法
//我们可以使用两个栈 num 和 ops 。

//num ： 存放所有的数字
//ops ：存放所有的数字以外的操作，+/- 也看做是一种操作
//然后从前往后做，对遍历到的字符做分情况讨论：

//空格 : 跳过
//( : 直接加入 ops 中，等待与之匹配的 )
//) : 使用现有的 num 和 ops 进行计算，直到遇到左边最近的一个左括号为止，计算结果放到 num
//数字 : 从当前位置开始继续往后取，将整一个连续数字整体取出，加入 num
//+-*/ : 需要将操作放入 ops 中。在放入之前根据优先级，先把栈顶高优先级操作可以算的都算掉，
//          使用现有的 num 和 ops 进行计算，直到没有操作或者遇到左括号，计算结果放到 num
//小技巧:使用map维护一个符号优先级

#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    stack<long> num;
    stack<int> ops;
    int calculate(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        m.insert(make_pair('+',1));
        m.insert(make_pair('-',1));
        m.insert(make_pair('*',2));
        m.insert(make_pair('/',2));
        //边界情况:
        //由于第一个数可能是负数，为了减少边界判断。一个小技巧是先往 num 添加一个 0
        num.push(0);
        //为防止 () 内出现的首个字符为运算符，将所有的空格去掉，并将 (- 替换为 (0-，(+ 替换为 (0+（当然也可以不进行这样的预处理，将这个处理逻辑放到循环里去做）
        while(s.find("(-")!=-1){
            s.replace(s.find("(-"),2,"(0-");
        }
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                ops.push('(');
                i++;
            }else if(s[i]==')'){
                while(ops.top()!='('){
                    cal();
                }
                ops.pop();
                i++;
            }else if(isdigit(s[i])){
                long d = s[i]-'0';
                int t = i+1;
                while(isdigit(s[t])){
                    d = d*10+s[t]-'0';
                    t++;
                }
                num.push(d);
                i = t;
            }else if(s[i]==' '){
                i++;
                continue;
            }else{
                while(!ops.empty() && m[ops.top()] >= m[s[i]]){
                    cal();
                }
                ops.push(s[i]);
                i++;
            }
        }
        while(!ops.empty()){
            cal();
        }
        return num.top();
    }
    void cal(){
        char c = ops.top();
        ops.pop();
        long a = num.top();
        num.pop();
        long b = num.top();
        num.pop();
        switch(c){
            case '+':
                num.push(a+b);
                break;
            case '-':
                num.push(b-a);
                break;
            case '*':
                num.push(a*b);
                break;
            case '/':
                num.push(b/a);
                break;
        }
    }
};

int main(){
    string s="(5-1)*(3+4/2)";
    int ret;
    Solution a;
    cout<<s<<"="<<a.calculate(s)<<endl;
    s="5 * ( 3 + 4 )";
    cout<<s<<"="<<a.calculate(s)<<endl;
    return 0;
}

