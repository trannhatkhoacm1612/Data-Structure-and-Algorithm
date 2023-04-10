#include<iostream>
#include <vector>
using namespace std;

int main(){
   int n,m;
   cin >> n >> m;
   vector<int> arr(n + 1),check(n + 1),add(m + 1);
   for(int i = 1; i <= n;i++){
        arr[i] = i;
        check[i] = 1;
   }
   for(int i = 1; i <= m; i++){
        cin >> add[i];
    }
    for(int i = m; i >= 1; i--){
        if(check[add[i]] == 1){
            cout << add[i] << " ";
            check[add[i]] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        if(check[i] == 1){
            cout << i << " ";
        }
    }

}