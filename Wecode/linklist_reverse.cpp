
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode { // Class node
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    


};



void insert_node(SinglyLinkedList *A,int x){
    SinglyLinkedListNode *newnode = new SinglyLinkedListNode(x);
    if(A->head == nullptr){
        A->head = newnode;
        A->tail = newnode;
    }
    else{
        A->tail->next = newnode;
        A->tail = newnode;
    }

}

void printLinkedList(SinglyLinkedList *A){
    SinglyLinkedListNode *newnode = A->head;
    while(newnode != nullptr){
        cout << newnode->data << " ";
        newnode = newnode->next;
    }
}



SinglyLinkedListNode* reverseLinkedList(SinglyLinkedList *A){
    SinglyLinkedListNode* current = A->head; // current trỏ tới đầu
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* next_node = nullptr;
    while(current != nullptr){ // duyệt qua các phần tử
        next_node = current->next; // next_node trỏ tới ô kế tiếp của current
        current->next = prev; // next của current trỏ ngược lại về ô trước đó của nexnode
        prev = current;
        current = next_node;
    }
    A->head = prev; // Đưa con trỏ head về cuối list
    return A->head; // Trả về con trỏ vì hàm print cần con trỏ
}


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
