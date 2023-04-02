// cho mảng a gồm n số nguyên dương(n >= 0) được sắp xếp theo thứ tự giảm dần, hãy xác định giá trị của phần tử lớn nhất trong mảng a không quá số nguyên dương x cho trước. nếu không tìm được phần tử nào thì trả về 0

#include <iostream>
#include <vector>
using namespace std;

int Binary_search(vector<int> a, int x,int n){
    int from = 0, to = n - 1;
    int mid;
    while(from < to){
        mid = (from + to) / 2;
        if(a[mid] > x){
            from = mid + 1;
        }
        else {
            to = mid;
        }
    }
    if(a[from] <= x){
        return a[from];
    }
    return 0;
}


int main(){
    int n,x;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;

    cout << Binary_search(a,x,n);

}