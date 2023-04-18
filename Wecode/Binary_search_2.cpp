#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void quickSort(vector<int> &arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

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

void quickSort(vector<int> &arr,vector<int> &index, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

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

vector<int> binary_search(vector<int> arr, int x) { // Trả về vị trí
    vector<int> positions;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            positions.push_back(mid);
            int i = mid - 1;
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
    //freopen("sinhvien.txt","r",stdin);
    string cc;
    int n,q,qr = 1,x,y;
    cin >> n >> q;
    vector<int> arr(n),index(n),pos_main;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        index[i] = i;
    }
    quickSort(arr,index,0,n - 1); // index chứa vị trí đã được sắp xếp ban đầu, arr cũng đc sắp xếp
    while(qr <= q){
        cin>>cc;
        cin >> x >> y;
        if(x == 1){
            vector<int> position = binary_search(arr,y); // trả về vector chứa vị trí của y
            if(position.size() == 0){
                cout << -1<<endl;;
                qr++;
                continue;
            }
            vector<int> pos_main;
            for(auto item: position){
                pos_main.push_back(index[item]);
            }
            int final = pos_main.size() - 1;
            quickSort(pos_main,0,final);
            cout << pos_main[0] + 1 << "\n";

        }
        else {
            vector<int> position = binary_search(arr,y); // trả về vector chứa vị trí của y
            if(position.size() == 0){
                cout << -1<<endl;
                qr++;
                continue;
            }
            vector<int> pos_main;
            for(auto item: position){
                pos_main.push_back(index[item]);
            }
            int final = pos_main.size() - 1;
            quickSort(pos_main,0,final);
            cout << pos_main[final] + 1 << "\n";

        }

        qr++;
        //cout <<qr;
    }

}
