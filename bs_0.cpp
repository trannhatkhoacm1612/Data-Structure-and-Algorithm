#include <iostream>
using namespace std;

int Binary_search(int a[],int x,int n){
    int from = 0, to = n - 1;
    int mid;
    while(from <= to){
        mid = (from + to) / 2;
        if(a[mid] == x){
            return mid;
        }
        else {
            if(a[mid] > x){
                to = mid - 1;
            }
            else {
                from = mid + 1;
            }
        }
    }
    return -1;
}