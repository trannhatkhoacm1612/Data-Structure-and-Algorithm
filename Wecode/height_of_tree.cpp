if(root == NULL){ // Đảm bảo nếu không có node thì bậc của node của root = 0 khi return ở bên dưới
            return -1;
        }
        int left_height = height(root->left); // đếm chiều cao cây con phải
        int right_height = height(root->right); // tương tự cây con trái
        return max(left_height,right_height) + 1; // cộng 1