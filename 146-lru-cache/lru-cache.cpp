class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> map;
    Node* left;
    Node* right;
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        map.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            remove(map[key]);
        }
        Node* newNode = new Node(key, value);
        map[key] = newNode;
        insert(newNode);

        if (map.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
    }
};
