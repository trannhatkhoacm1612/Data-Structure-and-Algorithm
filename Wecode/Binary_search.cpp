#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Binary_Search(int  *a,int l,int r,int x){
    if(r >= l){
        int mid = l + (r - l)/2;
        if(a[mid] == x){
            return 1;
        }
        else if(a[mid] > x){
            return Binary_Search(a,l,mid - 1,x);
        }
        else {
            return Binary_Search(a,mid + 1, r, x);
        }
    return -1;
    }
}

void input_array(int *a, int n){
    for(int i = 0; i < n; i++ ){
        int x;
        cin >> x;
        a.push_back(x);
    }
}


void output_array(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}

int main(){
    vector<int> a,b;
    int N,Q;
    cin >> N >> Q;
    input_array(a,N);
    input_array(b,Q);
    for(int i = 0; i < Q; i++){
        if(Binary_Search(a,0,N - 1,b[i]) == 1){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
