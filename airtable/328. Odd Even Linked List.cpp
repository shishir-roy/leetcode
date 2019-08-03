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
    Problem Name: 328. Odd Even Linked List
    Problem Link: https://leetcode.com/problems/odd-even-linked-list/
    Problem Description: group all odd nodes together followed by the even nodes.
    Idea: 
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* odd = head, *even = head->next;
        ListNode* headEven = even;
        while(even!= NULL && even->next!= NULL)
        {
            odd->next = even->next;  odd = odd->next;
            even->next = odd->next; even = even->next;
        }
        odd->next = headEven;
        return head;
    }
};