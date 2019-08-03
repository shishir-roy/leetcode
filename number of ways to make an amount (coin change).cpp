class Solution
{
    /*
    Problem Name: 518. Coin Change 2
    Problem Link: https://leetcode.com/problems/coin-change-2/
    Problem Description: Number of ways to make a total
    Idea: dp[i][j] = ways to make j using upto i th coin
          dp[i][j] = dp[i-1][j](without using i the coin) + dp[i][j-coin[i]] (using i th coin)

    Time Complexity: O(number of coins * amount)
    Space Complexity: O(number of coins * amount)

    Efficient: Space Complexity: O(amount)
    */
public:
    int change(int amount, vector<int>& coins)
    {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for(int x : coins)
        {
            for(int j = 1; j<=amount; j++)
            {
                if(j>=x)
                    dp[j]+=dp[j-x];
            }
        }
        return dp[amount];
    }
};
