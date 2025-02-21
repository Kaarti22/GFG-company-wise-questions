/*
Link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given an array arr[]. The task is to find the largest element and return it.

Examples:

Input: arr[] = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
Input: arr[] = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.
Input: arr[] = [10]
Output: 10
Explanation: There is only one element which is the largest.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        return *max_element(arr.begin(),arr.end());
    }
};