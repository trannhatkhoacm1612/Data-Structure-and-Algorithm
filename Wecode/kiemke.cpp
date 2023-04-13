#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isLessThan(string a, string b){
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] > b[i]) return false;
        else if (a[i] < b[i]) return true;
    }
    return false;
}

bool isEqual(string a, string b){
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]) return false;
    }
    return true;
}

void quickSort(vector<string> &str, int left, int right){
    if (left >= right) return;
    int i, j;
    i = left, j = right;
    string pivot = str[(left + right)/2];
    while (i <= j){ 
        while (i <= right && isLessThan(str[i], pivot)) i++;
        while (left <= j && isLessThan(pivot, str[j])) j--;
        if (i <= j){
            swap(str[i], str[j]);
            i++, j--;
        }
    }
    quickSort(str, left, j);
    quickSort(str, i, right);
}

int main(){
    int num;
    cin >> num;
    vector<string> str(num); 
    for (int i = 0; i < num; i++){
        cin >> str[i];        
    }
    quickSort(str, 0, num - 1);
    int cnt = 1;
    for (int i = 1; i < num; i++){
        if (!isEqual(str[i], str[i - 1])){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}