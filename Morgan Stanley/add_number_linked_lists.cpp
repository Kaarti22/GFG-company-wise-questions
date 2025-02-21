/*
Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=1&company=Morgan%20Stanley&sortBy=submissions

Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
 
Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9
*/

#include <bits/stdc++.h>
using namespace std;

// node for linked list:
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* reverse(Node* head){
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
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node* head = nullptr;
        Node* temp = head;
        Node* temp1 = num1;
        Node* temp2 = num2;
        int carry = 0;
        while(temp1 && temp2){
            int sum = temp1->data + temp2->data + carry;
            carry = sum / 10;
            sum %= 10;
            Node* node = new Node(sum);
            if(temp == nullptr){
                head = node;
                temp = head;
            } else {
                temp->next = node;
                temp = temp->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int sum = temp1->data + carry;
            carry = sum / 10;
            sum %= 10;
            Node* node = new Node(sum);
            if(temp == nullptr){
                head = node;
                temp = head;
            } else {
                temp->next = node;
                temp = temp->next;
            }
            temp1 = temp1->next;
        }
        while(temp2){
            int sum = temp2->data + carry;
            carry = sum / 10;
            sum %= 10;
            Node* node = new Node(sum);
            if(temp == nullptr){
                head = node;
                temp = head;
            } else {
                temp->next = node;
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        if(carry == 1){
            Node* node = new Node(carry);
            temp->next = node;
        }
        head = reverse(head);
        while(head && head->data == 0){
            head = head->next;
        }
        return head;
    }
};