#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &array, int left, int right){
    int i, j;
    i = left;
    j = right;
    int pivot = array[(left + right)/2];
    while (i <= j){
        while (array[i] < pivot) i++;
        while (pivot < array[j]) j--;
        if (i <= j){
            swap(array[i], array[j]);
            i++, j--;
        }
    }
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

int main(){
    int numLed, numChosenLed;
    cin >> numLed >> numChosenLed;
    vector<int> led(numLed);
    vector<bool> isChosen(numLed, false);
    int count = 0;
    for (int i = 0; i < numLed; i++){
        cin >> led[i];
    }
    quickSort(led, 0, numLed - 1);
    cout << led[0] << ' ';
    count++, isChosen[0] = true;
    for (int i = 1; i < numLed; i++){
        if (count == numChosenLed) break;
        if (led[i] != led[i - 1]){
            cout << led[i] << ' ';
            count++, isChosen[i] = true;
        }
    }
    for (int i = 0; i < numLed; i++){
        if (count == numChosenLed) break;
        if (!isChosen[i]){
            cout << led[i] << ' ';
            count++, isChosen[i] = true;
        }
    }
    return 0;
}
