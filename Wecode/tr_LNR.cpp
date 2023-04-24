
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

/* you only have to complete the function given below.  
Node is defined as  

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

*/

    void levelOrder(Node *root) {
    if (root == nullptr) {
        // Nếu cây rỗng, không có gì để in ra. Kết thúc hàm.
        return;
    }
    queue<Node*> q; // Tạo queue để lưu trữ tạm thời các node của cây sau khi duyệt.
    q.push(root); // Thêm node đầu tiên vào queue.
    while (!q.empty()) { // Lặp cho đến khi queue trống.
        int n = q.size();
        // Lặp qua mỗi node trong level hiện tại và thêm node con của chúng vào queue.
        for (int i = 0; i < n; i++) {
            Node* current = q.front(); // Lấy node đầu tiên trong queue.
            q.pop(); // Xóa node đó khỏi queue.
            cout << current->data << " "; // In giá trị của node đó ra màn hình.
            if (current->left != nullptr) { // Nếu node đó có node con bên trái, thêm vào queue.
                q.push(current->left);
            }
            if (current->right != nullptr) { // Nếu node đó có node con bên phải, thêm vào queue.
                q.push(current->right);
            }
        }
    }
}

}; //End of Solution

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
  
    myTree.levelOrder(root);

    return 0;
}