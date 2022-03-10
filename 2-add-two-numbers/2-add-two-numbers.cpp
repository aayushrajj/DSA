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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int sum=0,carry=0;
        while(temp1 && temp2){
            sum = temp1->val + temp2->val;
            sum += carry;
            if(sum<10){
                carry = 0;
                curr->next = new ListNode(sum); 
            }     
            else{
                carry = sum/10;
                sum = sum%10;
                curr->next = new ListNode(sum);
            }
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            sum = carry + temp1->val;
            if(sum<10){
                carry = 0;
                curr->next = new ListNode(sum);
            }
            else{
                carry = sum/10;
                sum = sum%10;
                curr->next = new ListNode(sum);
            }
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2){
            sum = carry + temp2->val;
            if(sum<10){
                carry = 0;
                curr->next = new ListNode(sum);
            }
            else{
                carry = sum/10;
                sum = sum%10;
                curr->next = new ListNode(sum);
            }
            curr = curr->next;
            temp2 = temp2->next;
        }
        if(carry>0)
            curr->next = new ListNode(carry);
        return dummy->next;
    }
};