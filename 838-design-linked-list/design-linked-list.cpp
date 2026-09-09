class MyLinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int value) {
            val = value;
            next = NULL;
        }
    };

    Node* head;
    int size;
public:
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size){
            return -1;
        }
        int count=0;
        Node* temp=head;
        while(count!=index){
            temp=temp->next;
            count++;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next=head;
        head=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        int count=0;
        Node* temp=head;
        while(count!=index-1){
            temp=temp->next;
            count++;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next=newNode;
        size++;

    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        int count=0;
        if(index==0){
            Node* del = head;
            head = head->next;
            delete del;
        }
        else{
            Node* temp=head;
            while(count!=index-1){
                temp=temp->next;
                count++;
            }
            Node* del = temp->next;
            temp->next=del->next;
            delete del;
        }
        size--;
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