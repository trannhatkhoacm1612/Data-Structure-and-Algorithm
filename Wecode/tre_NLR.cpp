
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data; // data của node
        Node *left; // trỏ tới node trái
        Node *right; // trỏ tới node phải
        Node(int d) { // contructors
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) { // chèn
            if(root == NULL) {
                return new Node(data); // nếu node null thì chèn vào
            } else {
                Node* cur; // khởi tạo trỏ mới
                if(data <= root->data) { // nếu data chèn vào mà bé hơn root
                    cur = insert(root->left, data); // data của cur = data của điểm mới
                    root->left = cur; // địa chỉ của của root = cur
                } else { // tương tự
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
// ////////////* Bài làm
    void preOrder(Node *root) {
        // if(root->left == NULL || root->right == NULL){
        //     cout << root->data << " ";

        // }
        cout << root->data << " "; // cout ra mỗi lần chạy root
        if(root->left != NULL){ // xét trái khác null thì đệ quy
            preOrder(root->left);
        }
        if(root->right != NULL){ // tương tự
            preOrder(root->right);
        }
    }

}; 
// ///////////*


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
    cout << root->data;
    myTree.preOrder(root);

    return 0;
}