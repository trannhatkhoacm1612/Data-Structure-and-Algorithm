#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

long long combination(long long n, long long k) {
    long long numerator = 1;
    long long denominator = 1;

    for (long long i = 0; i < k; i++) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    return numerator / denominator;
}
int main(){
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for(long long i = 0; i < n; i ++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    arr.push_back(-1);
    long long re = 0,j = 0;
    for(long long i = 0; i < n; i ++){
        if(arr[i] == arr[i + 1]){
            long long k = 1;
            while(arr[i + 1] == arr[i]){
                k ++;
                i ++;
            }
            while(arr[j + 1] < 2 * arr[i] && j + 1 < n){
                j ++;
            }
            re += combination(k,3) + combination(k,2) * (j + 1 - k);
            //cout<<k<<" "<<j<<" "<<kq<<endl;
        }
    }
    cout << re;
    return 0;
}