#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) { // Constructors
            this->data = node_data; // node - content
            this->next = nullptr; // point nulls
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head; // node đầu
        SinglyLinkedListNode *tail; // node cuối

        SinglyLinkedList() { // Contructors
            this->head = nullptr; // point nulls
            this->tail = nullptr; 
        }

        void insert_node(int node_data) { // insert node
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data); // create new node with node_data content

            if (!this->head) { // if head là nulls
                this->head = node; // node đầu = node insert
            } else { // if head không là null
                this->tail->next = node; //node cuối = node
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) { // Giải phóng bộ nhớ
    
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) { // in ra dữ liệu
    while (head != NULL){
        cout<< head->data << ' ';
        head = head->next;
    }
}



SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
    SinglyLinkedListNode *newnode = new SinglyLinkedListNode(x); // Con trỏ mới trỏ tới Node mới
    SinglyLinkedListNode *current = head; // Con trỏ current tới head
    if(head == nullptr || head->data >= x){ // Nếu ngay node đầu thỏa
        newnode->next = head; // newnod trỏ tới head
        head = newnode; // sao chép dataa
        return head;
    }
    while(current->next != nullptr && current->next->data < x){ // Duyệt hết mảng đến khi nào có số >= x
        current = current->next; // current trỏ tới next để đánh dấu
    }

    newnode->next = current->next;  // newnode trỏ tới current->next
    current->next = newnode; // current trỏ tới newnode đê swap
    return head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}
