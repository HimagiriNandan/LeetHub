/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* curr = headB;
        // while(curr != nullptr){
        //     ListNode* temp = headA;
        //     while(temp != nullptr){
        //         if(temp == curr){
        //             return curr;
        //         }
        //         temp = temp -> next;
        //     }
        //     curr = curr -> next;
        // }
        // return nullptr;

        //--------- Approach 2 ----------------------

        // unordered_map<ListNode*, ListNode*> mp;
        // ListNode* curr = headA;
        // while(curr != nullptr){
        //     mp[curr] = curr;
        //     curr = curr -> next;
        // }
        // ListNode* curr1 = headB;
        // while(curr1 != nullptr){
        //     if(mp.find(curr1) != mp.end()){
        //         return mp[curr1];
        //     }
        //     curr1 = curr1 -> next;
        // }
        // return nullptr;

        // -----------------Approach 3 ------------------
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        while(d1 != d2){
            d1 = (d1 == nullptr) ? headA : d1 -> next;
            d2 = (d2 == nullptr) ? headB : d2 -> next;
        }
        return d1;
    }
};