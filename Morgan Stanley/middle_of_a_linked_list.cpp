/*
Link: https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

Examples:

Input: Linked list: 1->2->3->4->5
Output: 3

Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: Linked list: 2->4->6->7->5->1
Output: 7 

Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 105
*/

#include <bits/stdc++.h>
using namespace std;

// Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        int total = 0;
        Node* temp = head;
        while(temp){
            total++;
            temp = temp->next;
        }
        int middle = total/2 + 1;
        int c = 1;
        temp = head;
        while(c != middle){
            c++;
            temp = temp->next;
        }
        return temp->data;
    }
};