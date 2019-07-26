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
    Problem Name: 445. Add Two Numbers II
    Problem Link: https://leetcode.com/problems/add-two-numbers-ii/
    Problem Description: Add two numbers
    Idea: Take two numbers in two stack so that we can add the number from the right while poping
          from the stack.
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>num1,num2;
        while(l1)
        {
            num1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            num2.push(l2->val);
            l2 = l2->next;
        }
        int carry=0, n1=0, n2=0;
        ListNode* dummy = new ListNode(0);
        while(!num1.empty() || !num2.empty() || carry)
        {
            if(!num1.empty())
            {
                n1 = num1.top();
                num1.pop();
            }
            else n1 = 0;
            
            if(!num2.empty())
            {
                n2 = num2.top();
                num2.pop();
            }
            else n2 = 0;
            
            int num = n1 + n2 + carry;
            carry = num/10;
            num%=10;
            
            ListNode* newNode = new ListNode(num);
            newNode->next = dummy->next;
            dummy-> next = newNode;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

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

#include<bits/stdc++.h>
using namespace std;
class Solution1 {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Bit manipulation
    Time Complexity: O(n*2^n)
    Space Complexity: O(n)
    */
private:
    bool is(int num,int ps)
    {
        return (bool)(num&(1<<ps));
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sub = (1<<n) - 1;
        vector< vector<int> > ans;
        for(int i=0;i<=sub;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(is(i,j))
                {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution2 {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Recursive
    Time Complexity: O(n*2^n)
    Space Complexity: O(n)
    */
private:
    void rec(vector< vector<int> >&ans, vector<int>&temp,vector<int>&nums,int ps)
    {
        if(ps>=nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ps]);
        rec(ans,temp,nums,ps+1);
        temp.pop_back();

        rec(ans,temp, nums,ps+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        vector<int>temp;
        rec(ans,temp,nums,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
    /*
    Problem Name: 78. Subsets
    Problem Link: https://leetcode.com/problems/subsets/
    Problem Description: Subset of a set
    Idea: Iterative
    Time Complexity: O(n*2^n)
    Space Complexity: O(1)
    */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans = {{}};
        for(int x : nums)
        {
            int n = ans.size();
            for(int i=0;i<n;i++)
            {
                ans.push_back(ans[i]);
                ans.back().push_back(x);
            }
        }
        return ans;
    }
};