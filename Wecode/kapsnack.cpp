#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,w;
    cin >> n >> w;
    vector<long long> W(n + 1), V(n + 1);
    vector<vector<long long>> qhd(n + 1,vector<long long>(w + 1));
    for(int i = 1; i <= n; i++){
        cin >> W[i] >> V[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(i == 0 || j == 0){
                qhd[i][j] = 0;
            }
            else {
                // Không lấy W[i]
                qhd[i][j] = qhd[i - 1][j];
                // Lấy
                if(W[i] <= j){
                    qhd[i][j] = max(qhd[i - 1][j - W[i]] + V[i],qhd[i][j]);
                }
                
            }
        }
    }
    cout << qhd[n][w];


}