//习题2
//用 unordered_map 重写单词转换程序。


#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;
void wordTransformation(){
    std::ifstream ifs_map("in.txt"), ifs_content("in2.txt");
    if (!ifs_map || !ifs_content) {
        std::cerr << "can't find the documents." << std::endl;
        return;
    }
    std::unordered_map<string, string> trans_map;
    for (string key, value; ifs_map >> key && getline(ifs_map, value); )
        if (value.size() > 1) trans_map[key] =
                value.substr(1).substr(0, value.find_last_not_of(' '));
    for (string text, word; getline(ifs_content, text);
                                                std::cout << std::endl)
        for (std::istringstream iss(text); iss >> word; ) {
            auto map_it = trans_map.find(word);
            std::cout << (map_it == trans_map.cend() ?
                                    word : map_it->second) << " ";
        }
}
int main(){
    wordTransformation();
    return 0;
}
