//习题1
//用 unordered_map 重写单词计数程序,
//同时忽略大小写和标点。
//例如，"example."、"example,"和"example"应该递增相同的计数器。

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
void word_count_pro(std::unordered_map<std::string, int>& m){
    std::string word;
    while (std::cin >> word){
        for (auto& ch : word)
            ch = tolower(ch);
//要删除的元素移到容器末尾并返回要被删除元素的迭代器，
//然后通过erase成员函数来真正删除。一般remove_if和erase函数是成对出现的。
        word.erase(std::remove_if(word.begin(),word.end(),ispunct),word.end());
        ++m[word];
    }
    for (const auto& e : m) std::cout << e.first << " : " << e.second << "\n";
}
int main(){
    std::unordered_map<std::string, int> m;
    word_count_pro(m);
    return 0;
}

