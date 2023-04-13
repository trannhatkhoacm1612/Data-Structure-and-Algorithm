#include<iostream>
#include<algorithm>

using namespace std;

string findKey(string slock){
    int sumOfDigits = 0;
    for (int i = 0; i < slock.size(); i++){
        sumOfDigits += (slock[i] - '0');
    }
    
    if (sumOfDigits % 3 == 1){
        for (int i = slock.size() - 1; i >= 0; i--){
            if (slock[i] % 3 == 1){
                slock.erase(slock.begin() + i);
                return slock;
            }
        }
        int count = 0;
        for (int i = slock.size() - 1; i >= 0; i--){
            if (slock[i] % 3 == 2){
                slock.erase(slock.begin() + i);
                count++;
            }
            if (count == 2) return slock;
        }
    } else if (sumOfDigits % 3 == 2) {
        for (int i = slock.size() - 1; i >= 0; i--){
            if (slock[i] % 3 == 2){
                slock.erase(slock.begin() + i);
                return slock;
            }
        }
        int count = 0;
        for (int i = slock.size() - 1; i >= 0; i--){
            if (slock[i] % 3 == 1){
                slock.erase(slock.begin() + i);
                count++;
            }
            if (count == 2) return slock;
        }
    }
    return slock;
}

int main(){
    string slock;
    cin >> slock;
    int sumOfDigits = 0;

    sort(slock.begin(), slock.end(), greater<char>());    
    //cout << slock << '\n';
    cout << findKey(slock);
    return 0;
}