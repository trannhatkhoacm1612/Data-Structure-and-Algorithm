#include <iostream>
#include <vector>
using namespace std;

void dec_to_bin(int x){
    vector<int> re;
    while(x > 0){
        re.push_back(x % 2);
        x /= 2;
    }
    for(int i = re.size() - 1;i >= 0; i-- ){
        cout << re[i];
    }
}

int main(){
    int x;
    cin >> x;
    dec_to_bin(x);
}