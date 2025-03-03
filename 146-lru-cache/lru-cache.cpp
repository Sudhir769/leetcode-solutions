class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int length;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        head->next = tail;
        tail->prev = head;
    }

    void insertAtHead(Node* node){
        node->next = head->next;
        head->next = node;

        node->prev = head;
        node->next->prev = node;

        mp[node->key] = node;
        length++;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
        length--;
    }

    void deleteNode(Node* node, bool flag){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
        delete(node);
        length--;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int a = mp[key]->val;
            Node* node = mp[key];
            deleteNode(node);
            insertAtHead(node);
            return a;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* prevNode = mp[key];
            deleteNode(prevNode);
            insertAtHead(prevNode);
            prevNode->val = value;
            return;
        }

        Node* newNode = new Node(key, value);
        if(length >= capacity){
            deleteNode(tail->prev, true);
        }
        insertAtHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */