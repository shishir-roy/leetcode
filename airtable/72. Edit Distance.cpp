#include<bits/stdc++.h>
using namespace std;

class Solution {
    /*
    Problem Name: 72. Edit Distance
    Problem Link: https://leetcode.com/problems/edit-distance/
    Problem Description: Given two words word1 and word2, find the minimum number of operations 
                        required to convert word1 to word2.
    Idea: https://www.youtube.com/watch?v=XJ6e4BQYJ24&t=789s
    Time Complexity: O(nm)
    Space Complexity: O(nm)
    */
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp [n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                // If first string is empty, the only operation is to insert
                // all the characters of second string into first
                if(i==0)
                    dp[i][j] = j;  
                // If the second string is empty, the only operation is to delete 
                // all the characters of first string.
                else if(j==0)
                    dp[i][j] = i;
                // If last two characters of each string match, nothing to do.
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    // rec(i,j-1) for insert
                    // rec(i-1,j) for delete
                    // rec(i-1,j-1) for replace
                    // take the minimum of them
                    int mn  = min(dp[i][j-1],dp[i-1][j]);
                    dp[i][j] = 1 + min(mn,dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution t;
    string s1 = "horse" , s2 = "ros";
    cout << t.minDistance(s1, s2) << endl;
    return 0;
}