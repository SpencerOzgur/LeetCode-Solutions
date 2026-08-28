class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {

public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        this->cap = capacity;
        this->left = new Node(0, 0); 
        this->right = new Node(0, 0);
        this->left->next = this->right;
        this->right->prev = this->left;
    }
    
    int get(int key) {
        if (this->cache.contains(key)){
            evict(this->cache[key]);
            insert(this->cache[key]);
            return this->cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->cache.contains(key)){
            evict(this->cache[key]);
        }
        this->cache[key] = new Node(key, value);
        insert(this->cache[key]);

        if (this->cache.size() > this->cap){
            Node* lru = this->left->next;
            evict(lru);
            this->cache.erase(lru->key);
        }
    }

    void insert(Node* node){
        node->next = this->right;
        node->prev = this->right->prev;

        node->next->prev = node;
        node->prev->next = node;
    }

    void evict(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
