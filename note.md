# vector
1. 

vector<int/float/...> a : khai báo

size(): phương thức trả về độ dài chuỗi

resize(int n): thay đổi kích thước của mảng

push_back(x): Thêm phần tử x vào cuối mảng

pop_back(): xóa phần tử ở cuối mảng

2. cách input khác:
    void input_vector(vector<float> &a){
        int n; 
        while(cin >> n){
            a.push_back(n);
            // Nhập đến khi nào muốn dừng thì Cirl X + enter
        }
    }
