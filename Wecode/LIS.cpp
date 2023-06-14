#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n), re(n,1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                re[i] = max(re[j] + 1, re[i]);
            }
        }
    }
    auto ma = max_element(re.begin(),re.end());
    cout << *ma << "\n";
    vector<long long> d(*ma); // truy vết
    int j;
    for(j = 0; j < n; j++)
    if(re[j] == *ma){
        d[*ma - 1] = arr[j];
        break;
    }
    int h = *ma - 1;
    while(h>0){
        while(re[j] != h || arr[j] > d[h]){
            j--;
        } 
        d[h - 1] = arr[j];
        h--;
    }
    cout << *ma << endl;
    for(int i = 0 ;i < *ma; i++) {
        cout << d[i] <<" ";
    }
}