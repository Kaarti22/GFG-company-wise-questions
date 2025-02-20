/*
Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?page=1&company=Morgan%20Stanley&sortBy=submissions

You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in the knapsack. Each item is available in only one quantity.

In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively. You are also given an integer capacity, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to capacity. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

Examples :

Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3] 
Output: 50
Explanation: Choose the last item (value 50, weight 3) for a total value of 50.
Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ capacity ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n+1, vector<int>(capacity+1));
        for(int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<capacity+1; j++){
            dp[0][j] = 0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<capacity+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][capacity];
    }
};