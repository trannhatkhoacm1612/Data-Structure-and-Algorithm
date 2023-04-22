
#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

struct SinglyLinkedList {
	SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
		this->head = nullptr;
        this->tail = nullptr;
    }

	void insert_node(int node_data);
};

void SinglyLinkedList::insert_node(int node_data)
{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
}



void print_singly_linked_list(SinglyLinkedListNode* node,char sep=' ') {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << '\n';
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){
    SinglyLinkedListNode *fake = new SinglyLinkedListNode(0);
    SinglyLinkedListNode *manage = fake; // Trỏ tới fake
    while(true){
        if(head_list1 == nullptr){ // Nếu list 1 rỗng
            manage->next = head_list2 ;// next của manange
            break;
        }
        if(head_list2 == nullptr){ // Tương tự như trên
            manage->next = head_list1;
            break;
        }

        if(head_list1->data <= head_list2->data){ // Nếu số của list 1  <= số list2
            manage->next = head_list1; // trỏ next của manage sẽ trỏ tới 
            head_list1 = head_list1->next; // Xét tiếp node kế của list 1
        }
        else { // tương tự
            manage->next = head_list2;
            head_list2 = head_list2->next;
        }
        manage = manage->next; // chạy tiếp node kếs
    }
    fake = fake->next; // bỏ qua node giả
    return fake; // trả về kết quả đã bỏ qua node giả
    

}




int main (){
    cin.tie(0); std::ios::sync_with_stdio(false);
    
    int tests;
    cin >> tests;
    
    
    
    
    for (int t = 0; t < tests; t++){
		int llist1_num, llist2_num;
		cin >> llist1_num >> llist2_num;
		
		SinglyLinkedList* llist1 = new SinglyLinkedList();
		
		
		for (int i = 0; i < llist1_num; i++){
			int llist1_item;
			cin >> llist1_item;
			
			llist1->insert_node(llist1_item);
		}
		
		SinglyLinkedList* llist2 = new SinglyLinkedList();

		
		for (int i = 0; i < llist2_num; i++){
			int llist2_item;
			cin >> llist2_item;
			
			llist2->insert_node(llist2_item);
		}
		
		SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
		
		print_singly_linked_list(llist3);
		
		free_singly_linked_list(llist3);
		
		
	}
}
