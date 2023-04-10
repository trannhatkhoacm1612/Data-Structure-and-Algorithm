#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;



void quickSort(vector<int>& arr, int left, int right) {
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


void selectionSort(vector<pair<int, int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].second > arr[max_idx].second || (arr[j].second == arr[max_idx].second && arr[j].first < arr[max_idx].first)) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(arr[max_idx], arr[i]);
        }
    }
}


int main(){
    // int n, vari;
    // cin >> n;
    // vector<int> arr(n),arr_count(10000,0),labels;
    // for(int i =0 ; i < n; i++){
    //     cin >> vari;
    //     arr_count[vari] ++;
    //     if(labels.size() == 0){
    //         labels.push_back(vari);
    //     }
    //     else {
    //         if(find(labels.begin(), labels.end(),vari) == labels.end()){
    //             labels.push_back(arr[i]);
    //         }
    //     }
    // }
    // for(auto item: labels){
    //     cout << item << " ";
    
    int n, vari;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int,int>> dem;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    quickSort(arr,0,n - 1);
    
    int i = 0,count = 1;
    while(i < n){
        if(arr[i] == arr[i + 1] ){
            count ++;
        }
        else {
            dem.push_back({arr[i],count});
            count = 1;
        }
        i++;
    }
    selectionSort(dem);
    for(auto item: dem){
        cout << item.first << " " << item.second << endl;
    }
    
}