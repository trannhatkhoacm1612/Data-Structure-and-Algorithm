Node* insert(Node* root, int data) {
    Node* temp= new Node(data);
    Node* current, *parent;
    if (root == NULL) {
        return temp;
    } 
    current = root;
    parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            // Nếu data nhỏ hơn giá trị của node current thì sẽ đi tìm trong cây con bên trái
            current = current->left;
        } else {
            // Nếu data lớn hơn hoặc bằng giá trị của node current thì sẽ đi tìm trong cây con bên phải
            current = current->right;
        }
    }
    // Sau khi tìm được node parent chèn temp vào node con của parent để giữ tính chất BST
    if (data < parent->data) {
        // Nếu data nhỏ hơn giá trị của parent, thêm temp vào bên trái
        parent->left = temp;
    } else {
        // Nếu data lớn hơn hoặc bằng giá trị của parent, thêm temp vào bên phải
        parent->right = temp;
    }
    // Trả về node gốc của cây
    return root;
}