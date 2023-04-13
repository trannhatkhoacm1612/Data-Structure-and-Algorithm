// Mảng a gồm n số nguyên dương có tính chất unimodal nếu thỏa điều kiện sau: có thể chia mảng a thành: phần đầu là dãy số tăng dần(nghiêm ngặt), phần sau là dãy số giảm dần(nghiêm ngặt). Tìm phần tử lớn nhất trong mảng.

#include <iostream>
#include <vector>
using namespace std;

int Binary_search(vector<int> arr, int n){
    int from = 0, to = n - 1, mid;
    while(from < to){
        mid = (from + to) / 2;

        if(arr[mid] > arr[mid + 1]){
            to =  mid;
        } 
        else {
            from = mid + 1;
        }
    }
    return arr[from];
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << Binary_search(arr,n);
}