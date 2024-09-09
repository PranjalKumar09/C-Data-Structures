#include <bits/stdc++.h>

using namespace std;

/* 
LRU Cache   [Least Recently Used]

    get(key) -> value        (if present)
                -1           (otherwise)

    put(key, value)  -> if full -> remove LRU then insert

 */
class node {
public:
    int key;
    int val;
    node* prev;
    node* next;
    
    // Constructor to initialize a node with key and value
    node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};



class LRUCache {
public:
    node *head = new node(-1 , -1);
    node *tail = new node(-1 , -1);
    int cap;
    unordered_map<int, node * > m;
    LRUCache(int capacity) {
        this->cap = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    void add_node(node *newnode) {
        newnode->next = head->next ;
        newnode->prev = head ;
        head->next->prev = newnode ;
        head->next = newnode ;
    }
    void delete_node(node *delnode){
        node* delprev = delnode->prev ;
        node* delnext = delnode->next ;
        delprev->next = delnext ;
        delnext->prev = delprev ;
    }
    int get(int key) {
        if (m.find(key) != m.end()){
            node *temp = m[key] ;
            int res = temp->val;
            m.erase(key);
            delete_node(temp) ;
            add_node(temp) ;
            m[key]=head->next;
            return res ;
        }
        return -1 ;
    }
    
    void put(int key, int value){
        if (m.find(key)!= m.end()){
            node *existing_node = m[key];
            m.erase(key);
            delete_node(existing_node);
        }
        if (m.size() == cap){
            m.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new node(key , value));
        m[key] = head->next ;
    }
};



int main() {
    // Create an LRU cache with a capacity of 2
    LRUCache cache(2);

    // Put key-value pairs into the cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Retrieve and print the value associated with key 1
    cout << "Value for key 1: " << cache.get(1) << endl; // Output: 1

    // Put a new key-value pair into the cache, which will evict key 2 (least recently used)
    cache.put(3, 3);

    // Retrieve and print the value associated with key 2 (should return -1 as it was evicted)
    cout << "Value for key 2: " << cache.get(2) << endl; // Output: -1

    // Put a new key-value pair into the cache
    cache.put(4, 4);

    // Retrieve and print the value associated with key 1
    cout << "Value for key 1: " << cache.get(1) << endl; // Output: 1

    // Retrieve and print the value associated with key 3
    cout << "Value for key 3: " << cache.get(3) << endl; // Output: 3

    // Retrieve and print the value associated with key 4
    cout << "Value for key 4: " << cache.get(4) << endl; // Output: 4

    return 0;
}
