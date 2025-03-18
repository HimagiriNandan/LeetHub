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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* current = head;
        ListNode* beg = nullptr;
        ListNode* end = nullptr;
        int length = 0;
        while(current){
            length++;
            current = current -> next;
        }
        if(length < k){
            return head;
        }
        int endIndex = length - k + 1;
        current = head;
        for(int i = 1; i <= length; i++){
            if(i == k){
                beg = current;
            }
            if(i == endIndex){
                end = current;
            }
            current = current -> next;
        }
        int temp = beg -> val;
        beg -> val = end -> val;
        end -> val = temp;
        return head;
    }
};