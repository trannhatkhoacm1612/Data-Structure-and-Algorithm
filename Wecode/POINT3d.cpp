#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point3D{
    int x;
    int y;
    int z;
    bool operator < (Point3D point) const {
        return ((x < point.x) || (x == point.x && 
                ((y > point.y) || (y == point.y && 
                z < point.z))));
    }
    void printPoint(){
        cout << x << ' ' << y << ' ' << z << '\n';
    }
};

void quickSort(vector<Point3D> &point, int left, int right){
    int i, j;
    i = left;
    j = right;
    Point3D p = point[(left + right)/2]; 
    while (i <= j) { 
        while (point[i] < p) i++;   
        while (p < point[j]) j--;
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
    vector<Point3D> point(numPoint);
    for (int i = 0; i < numPoint; i++){
        cin >> point[i].x >> point[i].y >> point[i].z;
    }  
    quickSort(point, 0, numPoint - 1);

    for (int i = 0; i < numPoint; i++){
        point[i].printPoint();
    }
    return 0;
}