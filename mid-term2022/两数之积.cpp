//[> 有人相爱，有人夜里开车看海，有人leetcode第一题都做不出来。 <]
//两数之积
//Description
//给定一个整数目标值 target，和一个整数数组 nums ,请你在该数组中找出积为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//按坐标自小到大的顺序返回答案。
// map的用法
//测试用例：
//6
//1 2 3
//
//1 2
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        vector<int> two(vector<int>& nums, int target) {
            map<int,int> m;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0&&target==0){
                    return {0,1};//题目规定只有一个正确答案，有0情况下，只能是0，1
                }
                if(nums[i]!=0&&m.count(target/nums[i])>0){
                    return {m[target/nums[i]],i};
                }
                m[nums[i]]=i;
            }
            return {};
        }
};

int main(){

    int target=0;
    vector<int> nums;
    cin>>target;
    int temp;
    while(cin>>temp){nums.push_back(temp);}
    //cout<<"ok:"<<endl;

    Solution s;
    vector<int> ans = s.two(nums,target);
    for(auto i: ans)
        cout<<i<<" ";
    /* for(auto i =ans.begin();i<ans.end();i++) */
    /*     cout<<*i<<" "; */
    // [0, 1]
    return 0;
}



