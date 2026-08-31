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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prevind = -1;
        ListNode* prev = head;
        ListNode* curr = head -> next;
        ListNode* nxt = curr -> next ? curr -> next : nullptr;
        int ind = 1;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        while(nxt) {
            if((curr -> val > prev -> val) && (curr -> val > nxt -> val)) {
                if (first == -1) {
                    first = ind;
                    prevind = ind;
                }
                else {
                    minDist = min(minDist, ind - prevind);
                    prevind = ind;
                }
            } else if((curr -> val < prev -> val) && (curr -> val < nxt -> val)) {
                if (first == -1) {
                    first = ind;
                    prevind = ind;
                }
                else {
                    minDist = min(minDist, ind - prevind);
                    prevind = ind;
                }
            }
            prev = curr;
            curr = nxt;
            nxt = nxt -> next;
            ind++;
        }
        if(minDist == INT_MAX) {
            minDist = -1;
        }
        maxDist = max(prevind - first, maxDist);
        if(maxDist == 0 || maxDist == INT_MIN) {
            maxDist = -1;
        }
        return {minDist, maxDist};
    }
};