#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void quickSort(vector<long long> &arr, long long left, long long right) {
    long long i = left, j = right;
    long long pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

void quickSort(vector<long long> &arr,vector<long long> &index, long long left, long long right) {
    long long i = left, j = right;
    long long pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            swap(index[i],index[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr,index, left, j);
    }
    if (i < right) {
        quickSort(arr,index, i, right);
    }
}

vector<long long> binary_search(vector<long long> arr, long long x) { // Trả về vị trí 
    vector<long long> positions;
    long long left = 0, right = arr.size() - 1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (arr[mid] == x) {
            positions.push_back(mid);
            long long i = mid - 1;
            while (i >= 0 && arr[i] == x) {
                positions.push_back(i);
                i--;
            }
            i = mid + 1;
            while (i < arr.size() && arr[i] == x) {
                positions.push_back(i);
                i++;
            }
            break;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return positions;
}

int main(){
    long long n,q,qr = 1,x,y;
    cin >> n >> q;
    vector<long long> arr(n),index(n),pos_main;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        index[i] = i;
    }
    quickSort(arr,index,0,n - 1); // index chứa vị trí đã được sắp xếp ban đầu, arr cũng đc sắp xếp
    while(qr <= q){
        cin >> x >> y;
        if(x == 1){
            vector<long long> position = binary_search(arr,y); // trả về vector chứa vị trí của y
            if(position.size() == 0){
                cout << -1 << "\n";
                qr++;
                continue;
            }
            vector<long long> pos_main;
            for(auto item: position){
                pos_main.push_back(index[item]);
            }
            long long final = pos_main.size() - 1;
            quickSort(pos_main,0,final);
            cout << pos_main[0] + 1 << "\n";

        }
        else {
            vector<long long> position = binary_search(arr,y); // trả về vector chứa vị trí của y
            if(position.size() == 0){
                cout << -1 << "\n";
                qr++;
                continue;
            }
            vector<long long> pos_main;
            for(auto item: position){
                pos_main.push_back(index[item]);
            }
            int final = pos_main.size() - 1;
            quickSort(pos_main,0,final);
            cout << pos_main[final] + 1 << "\n";

        }
        
        qr++;
    }

}