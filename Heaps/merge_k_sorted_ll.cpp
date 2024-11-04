#include <bits/stdc++.h>
using namespace std;

/* 
Merge k sorted LL
=================

    TC = O(k log k) + O(n*k log k)
    SC = O(k)
*/

vector<int> solve1(vector<vector<int>> &arr){
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) 
        for (int j = 0; j < arr[i].size(); j++) 
            ans.push_back(arr[i][j]);
    sort(ans.begin(), ans.end());
    return ans;
}


class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class  Compare{
public: 
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

vector<int> solve(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    vector<int> result;

    // Initialize the heap with the head of each list
    for (Node* list : lists) 
        if (list)     minHeap.push(list);

    // Process the heap
    while (!minHeap.empty()) {
        Node* node = minHeap.top();
        minHeap.pop();
        result.push_back(node->data);
        
        if (node->next)     minHeap.push(node->next);        
    }

    return result;
}


Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<Node*> lists;

    // Create test linked lists
    lists.push_back(createLinkedList({1, 4, 5}));
    lists.push_back(createLinkedList({1, 3, 4}));
    lists.push_back(createLinkedList({2, 6}));

    // Merge the linked lists
    vector<int> result = solve(lists);

    // Print the result
    cout << "Merged Linked List: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}