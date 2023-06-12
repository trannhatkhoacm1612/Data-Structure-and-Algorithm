#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
    long long n,cur = 0;
    cin >> n;
    vector<long long> arr(n),re;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    re.push_back(0);
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        if(arr[i] != re[cur]){
            re.push_back(arr[i]);
            cur ++;
        }
    }
    cout << re.size() - 1 << "\n";;
    for(auto item: re){
        if(item != 0){
            cout << item << " ";
        }
    }
}