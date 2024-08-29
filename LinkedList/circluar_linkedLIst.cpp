// NOT DONE THIS ONE


#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
    ~Node() {
        Node* temp = next;
        while (temp != nullptr && temp != this) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void insert(int searchElement, int element) {
        Node* temp = this;
        while (temp->data != searchElement && temp->next != this)
            temp = temp->next;

        if (temp->data == searchElement) {
            Node* newNode = new Node(element);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        cout << "Element not found" << endl;
    }

    void remove(int searchElement) {
        Node* nextElement = this;
        Node* prevElement = nullptr;

        while (nextElement->data != searchElement && nextElement->next != this) {
            prevElement = nextElement;
            nextElement = nextElement->next;
        }

        if (nextElement->data == searchElement) {
            if (prevElement == nullptr) { // first element to be removed
                if (nextElement->next == this) { // if it's the only element
                    delete nextElement;
                    return;
                } else {
                    this->data = nextElement->data; // Copy data from next to this
                    this->next = nextElement->next; // Update next pointer
                    delete nextElement;
                    return;
                }
            } else {
                prevElement->next = nextElement->next;
                delete nextElement;
                return;
            }
        }
        cout << "Element not found" << endl;
    }

  void display() {
    Node* temp = this;
    do {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != this);
    cout << endl;
}

};

int main() {
    // Create a head node
    Node n1;
    Node n2(10);

    // Insert a node after n2
    n2.insert(10, 20);

    // Display the list
    cout << "Linked List after insertion:" << endl;
    n2.display();

    // Remove a node with value 10
    n2.remove(10);

    // Display the list after removal
    cout << "Linked List after removal:" << endl;
    n2.display();

    return 0;
}
