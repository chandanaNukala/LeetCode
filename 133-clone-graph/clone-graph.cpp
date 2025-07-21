/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*,Node*>map;
        queue<Node*>q;
        q.push(node);
        Node* copy=new Node(node->val);
        map[node]=copy;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();

            for(Node* n:cur->neighbors){
                if(map.find(n)==map.end()){
                    Node* newNode=new Node(n->val);
                    map[n]=newNode;
                    q.push(n);
                }
                map[cur]->neighbors.push_back(map[n]);
            }
        }
        return map[node];

    }
};