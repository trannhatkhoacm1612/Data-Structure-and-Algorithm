
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

// ///////// * Bài làm

    void preOrder(Node *root) {
    //     stack<Node*> stack; // Tạo một stack
    //     stack.push(root); // Thêm node đầu
    //     bool flag = true; // Check node trái
    //     while(!stack.empty()){ // Lặp đến khi nào stack rỗng
    //         Node* current = stack.top(); // node trỏ tới phần tử trên cùng của stack
    //         if(flag && current->left != NULL){ // Nếu trỏ bên trái của current khác null và đang bên trái
    //             cout << current->data << " "; // cout của current
    //             stack.push(current->left); // thêm trỏ left
    //         }
    //         else if(current->right != NULL){// đã chạy hết left , nếu bên phải khác null
    //             flag = false; // node phải
    //             stack.push(current->right); // thêm vào để đso, đợi nào false thì chạy ở else
    //         } 
    //         else { // Nếu đã không còn thằng nào bên trái
    //             flag = false;
    //             cout << current->data << " "; // cout thằng cuối cùng bên phải
    //             stack.pop(); // xóa thằng current đó đi
    //             if(current->right != NULL){ // Đến node trái kế thằng đã xóa, bên phải nó khác null
    //                 flag = true; // Đổi lại bên trái khi đó if đầu không chạy thì thêm ở else if
    //             }
    //         }
    //     }
    // }
    // }
        stack<Node*> nodeStack; // tạo stack
        nodeStack.push(root); // thêm root đầu
        while (!nodeStack.empty()) { // lặp tới thi nào rỗng
            Node* node = nodeStack.top(); // trỏ tới phần tử vào sau của stack
            nodeStack.pop(); // xóa phần tử đó
            cout << node->data << " "; // cout data node vừa xóa
            if (node->right) { // Nếu phải khác null
                nodeStack.push(node->right);// thêm vào right trước = ra sau
            }
            if (node->left) { // tương tự
                nodeStack.push(node->left); // thêm vào left sau = ra trước
            }
        }
    }

};

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}