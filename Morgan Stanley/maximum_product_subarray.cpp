/*
Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int ans = *max_element(arr.begin(), arr.end());
        int currMin = 1, currMax = 1;
        for(auto it: arr){
            if(it == 0){
                currMin = 1, currMax = 1;
                continue;
            }
            int temp = currMax * it;
            currMax = max({temp, currMin * it, it});
            currMin = min({temp, currMin * it, it});
            ans = max(ans, currMax);
        }
        return ans;
    }
};