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
        ListNode* result=new ListNode(0);
        ListNode* cur=result;
        ListNode* l1=list1;
        ListNode* l2=list2;
        while(l1!=NULL && l2!=NULL){
          
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
               
            }
            else{
                cur->next=l2;
                 l2=l2->next;
            }
             cur=cur->next;
             


        }
        cur->next=l1?l1:l2;

        return result->next;
    }
};