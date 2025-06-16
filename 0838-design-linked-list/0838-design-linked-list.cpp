class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        this->head = nullptr;
    }
    
    int get(int index) {
        int c = 0;
        Node* curr = head;
        while(curr != nullptr){
            if(c == index){
                return curr -> val;
            }
            curr = curr -> next;
            c++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp -> next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(head == nullptr){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr -> next != nullptr){
            curr = curr -> next;
        }
        curr -> next = temp;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        int c = 0;
        Node* temp = new Node(val);
        Node* curr = head;
        while(curr != nullptr && c < index - 1){
            curr = curr -> next;
            c++;
        }
        if(curr == nullptr) return;
        Node* t = curr -> next;
        temp -> next = t;
        curr -> next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(head == nullptr) return;
        if(index == 0){
            Node* temp = head;
            head = temp -> next;
            temp -> next = nullptr;
            delete temp;
        }
        int c = 0;
        Node* curr = head;
        while(curr != nullptr && c < index - 1){
            curr = curr -> next;
            c++;
        }
        if(curr == nullptr || curr -> next == nullptr) return;
        Node* t = curr -> next;
        curr -> next = curr -> next -> next;
        t -> next = nullptr;
        delete t;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */