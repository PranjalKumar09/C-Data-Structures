#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* n1) : data(data), next(n1) {}

    ~Node() {
        cout << "Deleting Node with data: " << data << endl;
        delete next;
    }

    void insertAtTail(Node*& tail, int d) {
        Node* temp = new Node(d);
        if (!tail)
            tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtHead(Node*& head, int d) {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtPostion(Node*& head, int postion, int data) {
        if (postion <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (postion == 1) {
            insertAtHead(head, data);
            return;
        }

        Node* temp = head;
        int cnt = 1;
        while (cnt < postion - 1 && temp->next) {
            temp = temp->next;
            cnt++;
        }
        Node* NodeToInsert = new Node(data);
        NodeToInsert->next = temp->next;
        temp->next = NodeToInsert;

        if (!NodeToInsert->next) // Update tail if necessary
            tail = NodeToInsert;
    }

    void deleteNode(int position, Node*& head) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr; // Remove the connection to avoid deletion of subsequent nodes
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;
        while (cnt < position && curr) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (!curr) {
            cout << "Position exceeds list length!" << endl;
            return;
        }

        prev->next = curr->next;
        curr->next = nullptr; // Remove the connection to avoid deletion of subsequent nodes
        delete curr;
    }

    int getLength(Node* node) {
        int len = 0;
        Node* temp = node;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void printList(Node* node) {
        Node* temp = node;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* tail = nullptr; // Added to keep track of tail
};

int main() {
    Node* head = new Node(10);

    head->insertAtTail(head->tail, 20);
    head->insertAtTail(head->tail, 30);
    head->insertAtHead(head, 5);
    head->insertAtPostion(head, 2, 15);

    cout << "Linked List: ";
    head->printList(head);

    head->deleteNode(3, head);

    cout << "Linked List after deletion: ";
    head->printList(head);

    cout << "Length of Linked List: " << head->getLength(head) << endl;

    delete head;

    return 0;
}
