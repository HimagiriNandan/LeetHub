/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != nullptr && curr -> next != nullptr){
            ListNode* first = curr;
            ListNode* second = curr -> next;

            prev -> next = second;
            first -> next = second -> next;
            second -> next = first;
            prev = first;
            curr = first -> next;
        }
        ListNode* newHead = dummy -> next;
        delete dummy;
        return newHead;
    }
};