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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return helper(list1,list2);
    }
    
    ListNode* helper(ListNode* l1 , ListNode* l2){
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode;
        ListNode* sorting = dummy;
        if(temp1==NULL) return temp2;
        if(temp2==NULL) return temp1;
        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                sorting->next = temp1;
                sorting = sorting->next;
                temp1 = temp1->next;
            }
            else{
                sorting->next = temp2;
                sorting = sorting->next;
                temp2 = temp2->next;
            }
        }
        while(temp1){
            sorting->next = temp1;
            sorting = sorting->next;
            temp1 = temp1->next;
        }
        while(temp2){
            sorting->next = temp2;
            sorting = sorting->next;
            temp2 = temp2->next;
        }
        return dummy->next;
    }
};