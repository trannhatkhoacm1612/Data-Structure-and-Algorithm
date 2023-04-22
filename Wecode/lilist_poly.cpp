#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{ // Don thuc
	int somu; // Gom so mu
	double heso; // va he so
	
	DONTHUC(double _heso = 0,int _somu=0){ // contructor
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{ // Node
	DONTHUC* data; // Bao gom don thuc data
	Node* next; // Va con tro next
	
	Node(DONTHUC* _data = nullptr){ // contructor
		this->data = _data;
		this->next = nullptr;
	}
	
};



struct DATHUC{ // da thuc
	Node* head; // node dau
	Node* tail; // node cuoi
	DATHUC(){ // contructor
		this->head = nullptr; 
		this->tail = nullptr;
	}
};


// /////////////////* Bài làm
void Nhap(DATHUC &B, double heso,int  somu){ // Nhập dathuc
	DONTHUC * donthuc = new DONTHUC(heso, somu); // Tạo một con trỏ donthuc với heso, somu
	if(B.head == nullptr){ // Nếu trỏ head = null
		B.head = new Node(donthuc); // b.head  trỏ đến Node(donthuc)
		B.tail = B.head; // Sao chép data
	}
	else { // Khác null
		Node* tmp = new Node(donthuc);  // tạo một trỏ trỏ tới Node(donthuc)
		B.tail->next = tmp; // Tail.next trỏ tới tmp
		B.tail = tmp; // sao chép data
	}
}

void Xuat(DATHUC& B) { // in đa thức
    Node* tmp = B.head; // Tạo một con trỏ tới B.head
    bool is_first = true; // Kiểm tra số hạng đầu

    while (tmp != nullptr) { // Duyệt tới cuối linklist
        DONTHUC* dt = tmp->data; // tạo trỏ tới tmp->data
        if (dt->heso == 0) {
            // Nếu hệ số bằng 0, không xuất đơn thức
        }
        else if (dt->somu == 0) {
            // Nếu số mũ bằng 0, chỉ xuất hệ số
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso;
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso;
                }
            }
            else {
                cout << dt->heso;
                is_first = false;
            }
        }
        else if (dt->somu == 1) {
            // Nếu số mũ bằng 1, chỉ xuất x
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso << "x";
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso << "x";
                }
            }
            else {
                cout << "-" << -dt->heso << "x";
                is_first = false;
            }
        }
        else if (dt->heso == 1 && dt->somu != 1) {
            // Nếu hệ số bằng 1 và không có số mũ,
            // không xuất số 1
            if (is_first) {
                cout << "x^" << dt->somu;
                is_first = false;
            }
            else {
                cout << "+" << "x^" << dt->somu;
            }
        }
        else if (dt->heso == -1 && dt->somu != 1) {
            // Nếu hệ số bằng -1 và không có số mũ,
            // không xuất số 1, xuất hệ số âm
            if (is_first) {
                cout << "-" << "x^" << dt->somu;
                is_first = false;
            }
            else {
                cout << "-" << "x^" << dt->somu;
            }
        }
        else {
            // Trường hợp còn lại
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso << "x^" << dt->somu;
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso << "x^" << dt->somu;
                }
            }
            else {
                cout << "-" << -dt->heso << "x^" << dt->somu;
                is_first = false;
            }
        }
        tmp = tmp->next;  // Cập nhật tiếp
    }
    if (is_first) {// Nếu is_first chưa đổi thì đa thức 0
        cout << "0";
    }
}

double TinhDaThuc(DATHUC &B, double x){ // Tính f(x)
	double re = 0;
	Node *tmp = B.head; // Trỏ tmp tới B.head
	while(tmp != nullptr){ // Duyệt hết linklist
		re += tmp->data->heso * pow(x,tmp->data->somu);
		tmp = tmp->next; // Cập nhật tiếp
	}
	return re;

}
// //////////////*


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
