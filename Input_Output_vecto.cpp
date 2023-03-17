#include <iostream>
#include <vector>
using namespace std;

void array_output(vector<float> &a){
    for(int i = 0; i < a.size();i ++){
        cout << a[i] << " ";
    }
}

void array_input(vector<float> &a){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int main(){
    vector<float> a;
    array_input(a);
    array_output(a);
}