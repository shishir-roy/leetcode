class Solution
{
    /*
    Problem Name: 188. Best Time to Buy and Sell Stock IV
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    Problem Description: Given stockc prices for certain days and at most k transactions how to buy and sell to maximize profit.
    Idea: Tusar Roy

    Time Complexity: O(days^2)
    Space Complexity: O(days)
    */
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int days = prices.size();
        if(days<2) return 0;

        k = min(k, days);

        if (k > days / 2)   // simple case
        {
            int result = 0;
            for (int i = 1; i < prices.size(); ++i)
            {
                result += max(prices[i] - prices[i - 1], 0);
            }
            return result;
        }

        vector< vector<int> >dp(2, vector<int>(days+1,0));
        for(int i=1; i<=k; i++)
        {
            int mx = INT_MIN;
            for(int j=1; j<days; j++)
            {
                mx = max(mx, dp[(i&1)^1][j-1] - prices[j-1]);
                dp[i&1][j] = max(dp[i&1][j-1], prices[j]+mx);
            }
        }
        return dp[k&1][days-1];
    }

};
