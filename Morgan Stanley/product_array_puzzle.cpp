/*
Link: https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.

Examples:

Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.
Input: arr[] = [12, 0]
Output: [0, 12]
Explanation: For i = 0, res[i] is 0.
For i = 1, res[i] is 12.
Constraints:
2 <= arr.size() <= 105
-100 <= arr[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        int zero = 0, prod = 1;
        for(auto it: arr){
            if(it == 0) zero++;
            else prod *= it;
        }
        vector<int>ans(n);
        if(zero >= 2){
            ans.resize(n, 0);
            return ans;
        }
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                ans[i] = prod;
            } else {
                if(zero == 1) ans[i] = 0;
                else ans[i] = prod / arr[i];
            }
        }
        return ans;
    }
};