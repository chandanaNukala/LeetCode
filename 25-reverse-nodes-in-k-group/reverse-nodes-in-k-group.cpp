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
     ListNode* getNode(ListNode* ptr,int k){
        while(ptr && k>0){
            ptr=ptr->next;
            k--;
        }
        return ptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* ptr1=dummy;

        while(true){
            ListNode* node_k= getNode(ptr1,k);
            if(node_k==NULL){
                break;
            }

            ListNode* ptr2=node_k->next;
            ListNode* prev=node_k->next;
            ListNode* cur=ptr1->next;
            while(cur!=ptr2){
                ListNode *tmp=cur->next;
                cur->next= prev;
                prev=cur;
                cur=tmp;
            }
            ListNode* rev=ptr1->next;
            ptr1->next=node_k;
            ptr1=rev;
        }
        return dummy->next;
    }
};