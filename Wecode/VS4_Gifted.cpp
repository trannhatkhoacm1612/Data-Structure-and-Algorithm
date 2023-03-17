#include <iostream>
#include <vector>
using namespace std;
int find(vector<int> arr,int n,int x){
    int max = arr[0] + arr[1];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] <= x && arr[i] + arr[j] > max){
                max = arr[i] + arr[j];
            }
        }
    }
    return max;
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << find(arr,n,x);

}