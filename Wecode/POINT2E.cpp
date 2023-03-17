#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class POINT2D{
    public:
    int x,y;
    void set(int x0,int y0){
        x = x0;
        y = y0;
    }
};
bool compare(const POINT2D& a, const POINT2D& b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x < b.x;
}


int main(){
    int n;
    cin >> n;
    vector<POINT2D> arr;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i].set(a,b);
    }
    sort(arr.begin(),arr.end(), compare);
    for (auto POINT2D : arr) {
        cout << POINT2D.x  << " " << POINT2D.y << endl;
    }

}