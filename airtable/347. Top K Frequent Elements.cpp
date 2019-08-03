#include<bits/stdc++.h>
using namespace std;
class Solution {
    /*
    Problem Name: 347. Top K Frequent Elements
    Problem Link: https://leetcode.com/problems/top-k-frequent-elements/
    Problem Description: k most frequent elements.
    Idea: Simple
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int x : nums)
        {
            mp[x]++;
        }

        vector<int>vt;
        set< pair<int,int> > st;
        for(auto x : mp)
        {
            st.insert({x.second, x.first});
        }
        for(auto it = st.rbegin(); it != st.rend() && k>0;k--,it++)
        {
            vt.push_back(it->second);
        }
        return vt;
    }
};

int main()
{
    Solution t;
    vector<int> temp = {-1,-1,5,7,7};
    temp = t.topKFrequent(temp, 2);
    for(int x : temp) cout << x << " ";
    return 0;
}