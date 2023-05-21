
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

    void postOrder(Node *root) {
        stack<Node*> stk;
        Node* curr = root;
    
        while (curr != NULL || !stk.empty()) {
            if (curr != NULL) {
                stk.push(curr); // Push nút hiện tại vào stack.
                curr = curr->left; // Xét tráu
            } else {
                Node* temp = stk.top()->right; // xét top stack phải
                if (temp == NULL) {
                    temp = stk.top(); // lấy top
                    stk.pop(); // xóa tóp
                    cout << temp->data << " "; //thăm
                    while (!stk.empty() && temp == stk.top()->right) {
                        temp = stk.top(); // lấy top tack
                        stk.pop(); // xóa
                        cout << temp->data << " "; // thăm
                    }
                } else { // nếu có phải push vào
                    curr = temp;
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
  
    myTree.inOrder(root);

    return 0;
}