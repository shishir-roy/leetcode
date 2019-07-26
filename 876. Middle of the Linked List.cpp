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
    Problem Name: 876. Middle of the Linked List
    Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
    Problem Description: return a middle node of linked list.
    Idea: Tusar Roy

    Time Complexity: O(n)
    Space Complexity: O(1)
    */
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* temp = head;
        int t = 1;
        while(temp != NULL)
        {
            temp = temp->next;
            t++;
        }
        t-=1; // As the loops goes to next of last node so #node increases by one
        t/=2;
        t+=1;
        int tt = 1;
        temp = head;
        while(tt<t) // because when we are at tt<t then we have the address of t th node
        {
            temp = temp->next;
            tt++;
        }
        return temp;
    }
};