/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* cur=head;
        unordered_map<Node*, Node*> map;
        map[NULL]=NULL;
        while(cur!=NULL){
            Node* newList=new Node(cur->val);
         
            map[cur]=newList;
            cur=cur->next;

        }

        cur=head;
        while(cur!=NULL){
            Node* newList=map[cur];
            newList->next=map[cur->next];
            newList->random=map[cur->random];
            cur=cur->next;
        }

        return map[head];
    }
};