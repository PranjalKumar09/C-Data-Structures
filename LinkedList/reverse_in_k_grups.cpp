    #include <iostream>
    using namespace std;

    struct Node{
        int data;
        Node *next , *prev;

        Node(){
            data = -1;
            next = NULL;
            prev = NULL;
        }
        Node(int x){
            data = x;
            next = NULL;
            prev = NULL;
        }
    };
    class DoubleLinkedList{
        public:    
        Node *head , *tail;
        DoubleLinkedList(){
            head = nullptr;
            tail = nullptr;
        }
        ~DoubleLinkedList(){
            Node *temp = head;
            while(temp!= nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void insertAtHead(int data){
            Node *newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        void insertAtTail(int data){
            Node *newNode = new Node(data);
            if (tail == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        void insertAtPosition(int data, int position) {
            if (position == 0)  insertAtHead(data);
            else {
            Node* newNode = new Node(data);
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Invalid position" << endl;
                delete newNode; // Clean up the memory allocated for the new node
                return;
            }

            newNode->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }}
        void PrintDLL(){
            if (head == nullptr) cout << "Invalid head" << endl;
            Node *temp = head;
            while(temp!= nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void Delete_Node(int data){
            Node *temp = head;
            while(temp!= nullptr && temp->data!= data)
                temp = temp->next;
            
            if(temp == nullptr){
                cout << "Node not found" << endl;
                return;}
            
            if(temp == head)
                head = head->next;
            
            if(temp == tail)
                tail = tail->prev;
            
            if(temp->prev!= nullptr)
                temp->prev->next = temp->next;
            
            if(temp->next!= nullptr)
                temp->next->prev = temp->prev;
            
            delete temp;
        }
        void Reverse(){
            if (head == nullptr || head->next == nullptr)
                return;

            Node* current = head;
            Node* temp = nullptr;
            while (current != nullptr){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
            head = temp->prev;
            head->prev = nullptr;
    }
        int  getLength(){
            Node *temp = head;
            int count = 0;
            while(temp!= nullptr && temp->next && temp->next != head){
                count++;
                temp = temp->next;
            }
            if (temp->next == head) return -1;
            return count;
        }
    };

    Node* inner_function(Node* &ip , int k){
        // TC = O(N)      SC = O(N/K)
        if (ip == nullptr || ip->next == nullptr ) return ip;

        Node* curr = ip, *forward = nullptr , *backward = nullptr;

        int cnt = 0; 
        while (curr  && cnt < k) { // reversing first k node of element 
            forward = curr->next;    // just for iterating the loop
            curr->next = backward;      // main work
            backward = curr;        
            curr = forward ;  // just for iterating the loop 
            cnt++;
        }

        if (forward ) ip->next = inner_function(forward , k); // next pointing to k+1
        return backward;
        // as it is like train     after reverse -> | backward | ip | null 
    }


    void K_Reverse(DoubleLinkedList& ip , int k){

        if (ip.getLength() == -1 || k <= 0) return;


    ip.head  = inner_function(ip.head , k);

    }




  void optimized_K_Reverse(DoubleLinkedList& ip, int k) {
//     Time Complexity: O(2N) reversing segments of K and finding the Kth node which operates in linear time. Thus,O(N) + O(N) = O(2N), which simplifies to O(N).
// Space Complexity: O(1) 

    Node* input = ip.head;
    if (!input || !input->next) return;

    int len1 = ip.getLength();
    Node* dummy = new Node(); // Allocate memory for dummy node
    dummy->next = ip.head;
    Node *backward = dummy, *forward, *curr = dummy->next;

    while (len1 >= k) {
        forward = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = forward->next;  // first setting the current next  to forward next 
            forward->next = backward->next; // the forward next to backward next  (basically in loop we are circling type of)
            backward->next = forward;  // to iterate throguh out we changed the backward next
            forward = curr->next; // then we set up forward to current next 
        }
        backward = curr;
        curr = curr->next; // Move curr to the next group
        len1 -= k;
    }
    /* 
    for loop iteraition->
    cur   nex   (new nex)
    
                ---------------------->
    0    ->    1    ->     2    ->     3         =>   0    ->    2   ->     1    ->    3
                <-----------     
     ---------------------->
    dummy     curr      forward    new forward       dummy     curr      forward    new forward        
    backward                                       (backward)


in k times it will be reversed successfully



     */

    ip.head = dummy->next; // Update ip.head to point to the new head of the reversed list
    delete dummy; // Deallocate memory for dummy node
}



    int main(){
        DoubleLinkedList dll;
        dll.insertAtHead(1);
        dll.insertAtHead(2);
        dll.insertAtHead(3);
        dll.insertAtTail(4);
        dll.insertAtTail(5);
        dll.insertAtTail(6);
        dll.insertAtPosition(7, 2);
        dll.insertAtPosition(8, 4);
        dll.Delete_Node(3);
        dll.PrintDLL();


        int k = 2;
        optimized_K_Reverse(dll, k);
        
        dll.PrintDLL();


        return 0;
    }  