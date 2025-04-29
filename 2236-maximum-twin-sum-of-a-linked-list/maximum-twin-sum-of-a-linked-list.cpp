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
    int pairSum(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        ListNode* p=head;
        int sum=INT_MIN;

        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* prev=NULL;
        ListNode* cur=s;
        while(cur){
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        cout<<prev;
        while(prev && p){
            sum=max(sum,prev->val+p->val);
            prev=prev->next;
            p=p->next;
        }
        return sum;


    }
};