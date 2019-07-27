#include<bits/stdc++.h>
using namespace std;

class Solution {
    /*
    Problem Name: 32. Longest Valid Parentheses
    Problem Link: https://leetcode.com/problems/longest-valid-parentheses/
    Problem Description: find the length of the longest valid (well-formed) parentheses substring.
    Idea: Insert into stack the index of '(' and while ')' found pop '(' because this is one of the valid
            parentheses.
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int mx = 0, temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() and s[st.top()]=='(')
                {
                    st.pop();
                    if(st.empty()) mx = max(mx,i+1);
                    else mx = max(mx,i-st.top());
                }
                else
                {
                    st.push(i);
                }
                
            }
        }
        return mx;
    }
};

int main()
{
    Solution t;
    cout << t.longestValidParentheses("(()");
    return 0;
}