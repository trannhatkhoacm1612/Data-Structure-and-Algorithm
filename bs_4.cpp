// Cho mnagr số nguyên a gồm m dòng, n cột(m, n > 0). Mnagr a có tính chất là các số trên mỗi dòng sắp tăng dần. Hẫy viết hàm kiểm tra xem nagr a có phần tử nào có giá trị là x hay không

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> Binary_search(vector<vector<int>> arr, int n, int m, int x){
    vector<pair<int,int>> re;
    for(int i = 0; i < n; i++){
        int from = 0, to = m - 1, mid;
        bool found = false;
        while(from <= to && found == false){
            mid = (from + to) / 2;
            if(arr[i][mid] == x ){
                re.push_back({i,mid});
                found = true;
            }
            else if(arr[i][mid] < x){
                from = mid + 1;
            }
            else {
                to = mid - 1;
            }
        }
    }
    return re;

}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    vector<pair<int,int>> re = Binary_search(arr,n,m,5);
    for(auto item: re){
        cout << item.first << " " << item.second << " \n";
    }
}