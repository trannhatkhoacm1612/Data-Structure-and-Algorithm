// Cho mảng a gồm n số nguyên n > 0. Xác định vị trí đầu tiên của số chính phương nhỏ nhất trong mảng a hoặc trà về -1 nếu không tìm thấy phần tử nào thỏa mãn
#include <iostream>
#include <math.h>
using namespace std;

bool is_square_number(int number){
    int i = int(sqrt(float(number)));
    return i*i == number;
}


int index_of_smallest_square_number(int *arr,int n){
    int index = -1;
    int min_square = 0;
    for(int i = 0; i < n;i++){
        if(is_square_number(arr[i]) && (index == -1  || arr[i] < min_square)){
            index = i;
            min_square = arr[i];
        }
    }
    return index;
}


int main(){
    int n;
    cin >> n;
    int * arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << index_of_smallest_square_number(arr,n);
    delete[] arr;
}