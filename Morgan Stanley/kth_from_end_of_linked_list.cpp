/*
Link: https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
1 <= node->data , x <= 106
1 <= k <= 106
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to find the data of kth node from the end of a linked list.
class Solution {
  private:
    Node* reverse(Node* head){
        if(!head) return nullptr;
        Node* prev = nullptr;
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
  public:
    int getKthFromLast(Node *head, int k) {
        head = reverse(head);
        int c = 0;
        Node* temp = head;
        while(temp){
            c++;
            if(c == k) return temp->data;
            temp = temp->next;
        }
        return -1;
    }
};