/*
Link: https://www.geeksforgeeks.org/problems/coin-change2448/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 

Examples:

Input: coins[] = [1, 2, 3], sum = 4
Output: 4
Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
Input: coins[] = [2, 5, 3, 6], sum = 10
Output: 5
Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
Input: coins[] = [5, 10], sum = 3
Output: 0
Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.
Constraints:
1 <= sum <= 104
1 <= coins[i] <= 104
1 <= coins.size() <= 103
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1));
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int j=1; j<sum+1; j++){
            dp[0][j] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};