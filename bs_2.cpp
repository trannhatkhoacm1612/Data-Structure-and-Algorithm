// Cho mảng a gồm n số nguyên được sắp xếp theo thứ tự tăng dần. Ta cần chèn một số nguyên x vào mảng a sao cho vẫn đảm bảo tính chất các phần tử trong a là tăng dần

#include <iostream>
#include <vector>
using namespace std;

int Binary_search(vector<int> a, int x,int n){
    int from = 0, to = n - 1,mid;
    while(from  < to - 1){
        mid = (from + to) / 2;
        if(a[mid] > x){
            to = mid - 1;
        }
        else {
            from = mid;
        }
    }
    if(a[from] <= x){
        if(a[from + 1] > x){
            return from + 1;
        }
        else {
            return from + 2;
        }
    }
    else {
        return from;
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
    int ind = Binary_search(a,x,n);
    cout << ind;
    a.insert(a.begin() + ind, x);
    for(auto i : a){
        cout << i << " ";
    }
}