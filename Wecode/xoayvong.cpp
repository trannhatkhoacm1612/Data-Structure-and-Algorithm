#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &arr, int k){
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    k = k % n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rotate(arr,k);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}