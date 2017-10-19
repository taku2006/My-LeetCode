/*
https://leetcode.com/problems/reverse-nodes-in-k-group/description/
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 1: My Solution, 36ms
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* cur=new_head;
        while(cur != nullptr)
            cur = _seg_revKGroup(cur, k);
        return new_head->next;
    }
    ListNode* _seg_revKGroup(ListNode* cur,int k){
        //only reverse the first K Nodes started from cur->next
        if(cur == nullptr) return cur;
        ListNode* tail = cur->next;
        ListNode *next,*head;
        int i=0;
        //check whether the remain Nodes number is greater than k
        while(tail != nullptr){
            tail = tail->next;
            ++i;
            if(i==k) break;
        }
        if(i<k) return nullptr;
        head = tail = cur->next;
        i=1;
        while(tail != nullptr && i<k){
            next = tail->next;
            cur->next = next;
            tail->next = next->next;
            next->next = head;
            head = next;
            ++i;
        }
        return tail;
    }
};
//Solution 2: code from Leetcode,19ms
class Solution {
    //nice code to reverse the List
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        if (head == NULL) return {NULL, NULL};
        ListNode *next = head->next;
        head->next = NULL; // disconnect head with its next
        pair<ListNode*, ListNode*> p = reverse(next);
        if (p.second == NULL) return {head, head}; // returned an empty list
        p.second->next = head;
        p.second = head;
        return p;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *prev = NULL, *curr = head;
        int cnt = k;
        while ((cnt--) > 0) {
            if (curr == NULL) return head; // less than k nodes in list
            prev = curr;
            curr = curr->next;
        } // curr is the head of next group, prev is the end of this group
        prev->next = NULL;
        ListNode *next_group = reverseKGroup(curr, k);
        pair<ListNode*, ListNode*> p = reverse(head); // head is not NULL
        p.second->next = next_group;
        return p.first;
    }
};