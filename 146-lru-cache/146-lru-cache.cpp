class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int k, int val) {
        key = k;
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* curr) {
        curr->prev = head;
        curr->next = head->next;
        head->next = curr;
        curr->next->prev = curr;
    }
    
    void deleteNode(Node* curr) {
        Node* temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete temp;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        // make it the most recently used key;
        Node* curr = mp[key];
        int val = curr->value;
        Node* newNode = new Node(key, val);
        
        mp.erase(key);
        deleteNode(curr);        
        
        addNode(newNode);
        mp[key] = head->next;       
        
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            // update its address(as it becomes most recently used) and value
            Node* curr = mp[key];
            Node* newNode = new Node(key, value);
            
            deleteNode(curr);
            mp.erase(key);
            
            addNode(newNode);
            mp[key] = head->next;
            return;
        }
        
        // If size breach, remove LRU and then insert
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        // Add the new node
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */