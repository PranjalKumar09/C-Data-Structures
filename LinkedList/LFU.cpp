#include <bits/stdc++.h>

using namespace std;

/* 
LEAST FREQUENTLY USED CACHE

    get(key) -> gets value pf key of exist
    put(key, value) -> update valiue if key present,if not insert they key ifnot used


    when cache is full, it remove LFU one, 
               if multiple then remove LRU one


        capacity, freq 
*/
class node {
public:
    int key, value, cnt;
    node* next;
    node* prev;

    node(int key, int value) {
        this->key = key;
        this->value = value;
        this->cnt = 1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class List {
public:
    int size;
    node* head;
    node* tail;

    List() {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node* n1) { // this will place n1 in front but after head  => head->n1->rest
        n1->next = head->next;
        n1->prev = head;
        head->next->prev = n1;
        head->next = n1;
        size++;
    }

    void removeNode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache, minFreq, curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = curSize = 0;
    }

    void updateFreqList(node* n1) {
        keyNode.erase(n1->key);
        freqListMap[n1->cnt]->removeNode(n1);

        if (n1->cnt == minFreq && freqListMap[n1->cnt]->size == 0) 
            minFreq++; // if Frequency List is 0 of that size then increase minfrequency
        

        List* nextHigherFreqList = new List();
        if (freqListMap.find(n1->cnt + 1) != freqListMap.end()) 
            nextHigherFreqList = freqListMap[n1->cnt + 1];
        

        n1->cnt += 1;
        nextHigherFreqList->addFront(n1);
        freqListMap[n1->cnt] = nextHigherFreqList;
        keyNode[n1->key] = n1;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            node* n1 = keyNode[key];
            int val = n1->value;
            updateFreqList(n1);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) { // Key already exists
            node* n1 = keyNode[key];
            n1->value = value;
            updateFreqList(n1);
        } else { // Key does not exist
            if (curSize == maxSizeCache) {
                // Cache is full, remove LFU
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1; // New element has to be added with frequency 1
            List* listFreq = new List();


            // checking is any one other htan that have minimum frequency 1
            if (freqListMap.find(minFreq) != freqListMap.end()) 
                listFreq = freqListMap[minFreq];
            

            node* n1 = new node(key, value);
            listFreq->addFront(n1);
            keyNode[key] = n1;
            freqListMap[minFreq] = listFreq;
        }
    }
};


int main() {
    LFUCache cache(2); // Initialize LFUCache with capacity 2

    // Put some values in the cache
    cache.put(1, 1);
    cache.put(2, 2);
    
    // Get value for key 1
    cout << "Get key 1: " << cache.get(1) << endl; // returns 1

    // Put another value in the cache, causing the cache to evict the least frequently used item
    cache.put(3, 3);

    // Since the cache capacity is 2, it should have evicted key 2
    cout << "Get key 2: " << cache.get(2) << endl; // returns -1 (not found)

    // Key 3 should be present
    cout << "Get key 3: " << cache.get(3) << endl; // returns 3

    // Put another value in the cache, causing another eviction
    cache.put(4, 4);

    // Key 1 should have been evicted as it was least frequently used
    cout << "Get key 1: " << cache.get(1) << endl; // returns -1 (not found)

    // Key 3 should still be present
    cout << "Get key 3: " << cache.get(3) << endl; // returns 3

    // Key 4 should be present
    cout << "Get key 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
