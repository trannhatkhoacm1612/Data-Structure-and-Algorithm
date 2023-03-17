// Cho hai dãy số nguyên đã được sắp xếp không giảm a và b lần lượt có n và m phần tử. Hãy ghép chúng thành dãy c được bố trí theo thứ tự không giảm.
#include <iostream>
#include <vector>
using namespace std;

void creat_c_arr(vector<int> a,vector<int> b, vector<int>& c){
    int i = 0, j = 0;
    while(i < a.size() || j < b.size()){
        if(j == b.size()|| (i < a.size() && a[i] <= b[j])){
            c.push_back(a[i]);
            i++;

        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n),b(m),c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m ; i++){
        cin >> b[i];
    }
    creat_c_arr(a,b,c);
    for(auto it: c){
        cout << it << " ";
    }

}