#include <iostream>
using namespace std;

class Node {
public:
    int data; // self data
    Node* next; // address of the next node

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if (this->next) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory cleared for node with data: " << data << endl;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~LinkedList() {
        // Deallocate all nodes
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtTail(int d) {
        Node* temp = new Node(d);
        if (!tail) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtHead(int d) {
        Node* temp = new Node(d);
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insertAtPosition(int position, int data) {
        if (position == 1) {
            insertAtHead(data);
            return;
        }

        Node* temp = head;
        int cnt = 1;
        while (cnt < position - 1 && temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (temp->next == NULL) {
            insertAtTail(data);
            return;
        }

        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    void deleteNode(int position) {
        if (position == 1) {
            Node* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = temp->next;
            }
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        if (curr == tail) {
            tail = prev;
            if (tail) {
                tail->next = NULL;
            }
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }

    int getLength() {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPosition(2, 15);

    cout << "Linked List: ";
    list.printList(); // Should print 10 15 20 30

    cout << "Length of list: " << list.getLength() << endl; // Should print 4

    list.deleteNode(2);
    cout << "Linked List after deletion: ";
    list.printList(); // Should print 10 20 30

    return 0;
}
