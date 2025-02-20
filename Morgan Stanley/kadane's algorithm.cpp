/*
Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-109 ≤ arr[i] ≤ 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        int maxi = -1e9;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
            maxi = max(maxi, arr[i]);
        }
        if(maxi < 0) return maxi;
        return ans;
    }
};