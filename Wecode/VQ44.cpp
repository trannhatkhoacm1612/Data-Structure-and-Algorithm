#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    vector<bool> check(n, false);
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    int count = 0;
    cout << num[0] << ' ';
    count++;
    for (int i = 1; i < n; i++){
        if (count >= k) break;
        if (num[i] != num[i - 1]){
            cout << num[i] << ' ';
            check[i] = true;
            count++;
        }
    }
    for (int i = 1; i < n; i++){
        if (count >= k) break;
        if (!check[i]){
            cout << num[i] << ' ';
            check[i] = true;
            count++;
        }
    }
    return 0;
}