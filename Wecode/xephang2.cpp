#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> arr(n + m + 1),indx(n + 1);
    for(int i = m + 1; i <= m + n; i++){
        arr[i] = i - m; 
        indx[i - m] = i;
    }
    for(int i = m; i >= 1; i--){
        cin >> x;
        arr[i] = x;
        arr[indx[x]] = 0;
        indx[x] = i;
        for(int j = m + n; j >= 1; j--){
            if(arr[j] != 0){
                cout << arr[j];
                break;
            }
        }
    }
}