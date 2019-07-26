/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
    Problem Name: 206. Reverse Linked List
    Problem Link: https://leetcode.com/problems/reverse-linked-list/
    Problem Description: Reverse a singly linked list..
    Idea: Tusar Roy

    Time Complexity: O(n)
    Space Complexity: O(1)
    */
public:
    ListNode* reverseList(ListNode* head) {
        // recursive solution
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        // iterative solution
        ListNode* prev = NULL;
        while(head)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};