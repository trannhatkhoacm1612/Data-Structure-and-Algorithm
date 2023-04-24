#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;
int num_students, num_changes;

struct LinkedListNode {
    int value;
    LinkedListNode *previous, *next;
    LinkedListNode(int data = 0) {
        value = data;
        previous = NULL, next = NULL;
    }
} *nodes[MAX_N];

struct LinkedList {
    LinkedListNode *head, *tail;
    LinkedList() {
        head = NULL, tail = NULL;
    }
};

int main() {
    int u, v;
    LinkedList* student_list = new LinkedList();
    
    cin >> num_students >> num_changes;
    
    // tạo ll
    for (int i = 0; i < num_students; i++) {
        LinkedListNode *new_node = new LinkedListNode(i);
        nodes[i] = new_node;
        if (student_list->tail == NULL) {
            student_list->head = student_list->tail = new_node;
            continue;
        }
        student_list->tail->next = new_node;
        new_node->previous = student_list->tail;
        student_list->tail = new_node;
        if (i + 1 == num_students)
            student_list->tail->next = student_list->head;
    }
    
    // Khởi tạo thêm con trỏ 'previous' của phần tử đầu tiên trỏ tới phần tử cuối cùng, và ngược lại.
    nodes[0]->previous = student_list->tail;
    
    // Thực hiện thay đổi danh sách sinh viên thỏa mãn yêu cầu.
    while (num_changes--) {
        cin >> u >> v;
        u--, v--;

        nodes[u]->previous->next = nodes[u]->next; // Con trỏ của nút liền trước nút u trỏ tới nút liền sau nút u.
        nodes[u]->next->previous = nodes[u]->previous; // Con trỏ của nút liền sau nút u trỏ tới nút liền trước nút u.
        nodes[u]->previous = nodes[v]; // Con trỏ của nút u được trỏ tới nút v.
        nodes[u]->next = nodes[v]->next; // Con trỏ liền sau nút u trỏ tới nút sau của nút v.
        nodes[v]->next->previous = nodes[u]; // Con trỏ của nút liền sau nút v trỏ tới nút u.
        nodes[v]->next = nodes[u]; // Con trỏ của nút v trỏ tới nút u
    }
    
    // In ra màn hình danh sách sinh viên sau khi thực hiện thay đổi.
    int count = 0;
    for (auto it = student_list->head; count < num_students; it = it->next, count++)
        cout << it->value + 1 << " ";
}