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
    Problem Name: 1019. Next Greater Node In Linked List
    Problem Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
    Problem Description: next larger value in linked list
    Idea: 
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>vt;
        while(head)
        {
            vt.push_back(head->val);
            head = head->next;
        }
        vector<int>ans(vt.size());
        stack<int>st;
        st.push(0);
        for(int i = 1;i<vt.size();i++)
        {
            while(!st.empty() && vt[st.top()] < vt[i])
            {
                ans[st.top()] = vt[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};