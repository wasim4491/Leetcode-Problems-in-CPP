class node{
    public:
    int data;
    node* next;
    node(int key){
        this->data=key;
        this->next=NULL;
    }
};
class MyHashSet {
public:
    node* head = NULL;
    MyHashSet() {
        head = NULL;
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        node* newnode = new node(key);
        if(head == NULL){
            head=newnode;
            return;
        }
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        if(head->data==key){
            node* dup = head;
            head = head->next;
            dup->next=NULL;
            delete dup;
            return;
        }
        node* prev = head;
        node* cur = head;
        while(cur->data != key){
            prev = cur;
            cur = cur -> next;
        }
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
    }
    
    bool contains(int key) {
        node* temp = head;
        while(temp!=NULL){
            if(temp->data == key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */