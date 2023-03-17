#include <iostream>
#include <vector>
using namespace std;

void input_vecto_array(vector<float> &a){
    float x;
    while(cin >> x){
        a.push_back(x);
    }
}

void output_vecto_array(vector<float> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
}


int main(){
    vector<float> a;
    input_vecto_array(a);
    output_vecto_array(a);
    return 0;
}