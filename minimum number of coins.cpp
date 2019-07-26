class Solution
{
    /*
    Problem Name: 518. Coin Change 2
    Problem Link: https://leetcode.com/problems/coin-change/
    Problem Description: Minimum number of coins to make a total
    Idea: dp[j] = minimum number of coins to make j
          dp[j] = min(dp[j], dp[j-coins[i]])
    Time Complexity: O(number of coins * amount)
    Space Complexity: O(amount)

    Efficient: Space Complexity: O(amount)
    */
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int>dp(amount+3,amount+10);
        dp[0]=0;
        for(int i=0; i<coins.size(); i++)
        {
            for(int j=coins[i]; j<=amount; j++)
            {
                dp[j] = min(dp[j],1+dp[j-coins[i]]);
            }
        }
        return dp[amount] != amount+10 ? dp[amount] : -1 ;
    }
};
