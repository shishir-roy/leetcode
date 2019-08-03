#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Bit manipulation
    Time Complexity: O(n*2^n)
    Space Complexity: O(n)
    */
private:
    bool is(int num,int ps)
    {
        return (bool)(num&(1<<ps));
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sub = (1<<n) - 1;
        vector< vector<int> > ans;
        for(int i=0;i<=sub;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(is(i,j))
                {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution2 {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Recursive
    Time Complexity: O(n*2^n)
    Space Complexity: O(n)
    */
private:
    void rec(vector< vector<int> >&ans, vector<int>&temp,vector<int>&nums,int ps)
    {
        if(ps>=nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ps]);
        rec(ans,temp,nums,ps+1);
        temp.pop_back();

        rec(ans,temp, nums,ps+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        vector<int>temp;
        rec(ans,temp,nums,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Iterative
    Time Complexity: O(n*2^n)
    Space Complexity: O(1)
    */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans = {{}};
        for(int x : nums)
        {
            int n = ans.size();
            for(int i=0;i<n;i++)
            {
                ans.push_back(ans[i]);
                ans.back().push_back(x);
            }
        }
        return ans;
    }
};
int main()
{
    Solution t;
    vector<int> temp = {4,1,0};
    vector< vector<int> > ans = t.subsets(temp);
    for(auto x : ans)
    {
        for(int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}