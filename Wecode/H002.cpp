#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long long n,re = 0;
    cin >> n;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),greater<long long>());
   
    for(long long i = 0; i < n - 1; i++){
        re += (n - i - 1) * arr[i];
        re -= (i + 1) * arr[i + 1];
    }
    cout << re;

}