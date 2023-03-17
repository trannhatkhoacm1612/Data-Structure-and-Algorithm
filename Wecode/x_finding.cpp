#include <iostream>
#include <vector>
using namespace std;

void find(int *arr,vector<int> &s,int x,int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            s.push_back(i + 1);
        }
    }
}


int main(){
    int n,x;
    vector<int> s;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    find(arr,s,x,n);
    if(s.size() == 0){
        cout << "NO";
    }
    else {
        for(int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
    }
    return 0;
}