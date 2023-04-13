#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point2D{
    int x;
    int y;
    bool operator < (Point2D point) const {
        return ((x < point.x) || (x == point.x && y > point.y));
    } 
    bool operator > (Point2D point) const{
        return ((x > point.x) || (x == point.x && y < point.y));
    }
};

void quickSort(vector<Point2D> &point, int left, int right){
    int i, j;
    i = left;
    j = right;
    Point2D p = point[(left + right)/2]; 
    while (i <= j) { 
        while (point[i] < p) i++;   
        while (point[j] > p) j--;
        if (i <= j){
            swap(point[i], point[j]);    
            i++, j--;
        }
    }
    if (left < j) quickSort(point, left, j);        
    if (i < right) quickSort(point, i, right);    
}

int main(){
    int numPoint;
    cin >> numPoint;
    vector<Point2D> point(numPoint);
    for (int i = 0; i < numPoint; i++){
        cin >> point[i].x >> point[i].y;
    }  
    quickSort(point, 0, numPoint - 1);

    for (int i = 0; i < numPoint; i++){
        cout << point[i].x << ' ' << point[i].y << '\n';
    }
    return 0;
}