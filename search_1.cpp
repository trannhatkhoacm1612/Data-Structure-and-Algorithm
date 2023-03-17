//Cho mảng a gồm n số nguyên dương. Viết hàm xác định giá trị của phần tử lớn nhất trong mảng a
#include <iostream>
#include <vector>
using namespace std;

int find(int *arr,int n, int x){
    int i = 0;
    arr[n] = x;
    while(arr[i] != x){
        i++;
    }
    if(i < n){
        return 1;
    }
    return -1;
}

int main(){
    int n,x;
    cin >> n;
    int *arr = new int[n + 1];

    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }
    cin >> x;
    cout << find(arr,n,x);
    delete[] arr;
}