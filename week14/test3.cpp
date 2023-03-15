//习题3
//编写程序，定义一个作者及其作品的multimap。
//使用find在multimap中查找一个元素并用erase删除它。
//按字典序打印作者列表和他们的作品。
#include <map>
#include <set>
#include <string>
#include <iostream>
using std::string;
int main(){
    std::multimap<string, string> authors{
        { "William Shakespeare", "Romeo and Juliet" },
        { "William Shakespeare", "Much Ado About Nothing" },
        { "William Shakespeare", "King Lear" },
        { "Mao Zedong", "Selected Works of Mao Zedong" } };
    string author = "William Shakespeare";
    string work = "Romeo and Juliet";
    auto found = authors.find(author);
    auto count = authors.count(author);

    while (count){
        if (found->second == work){
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }
    //for (const auto &author : authors)
        //std::cout << author.first << " " << author.second << std::endl;


    std::map<string, std::multiset<string>> order_authors;
    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);
    for (const auto &author : order_authors){
        std::cout << author.first << ": ";
        for (const auto &work : author.second)
            std::cout <<"《"<< work<<"》" << ", ";
        std::cout << std::endl;
    }

    return 0;
}

