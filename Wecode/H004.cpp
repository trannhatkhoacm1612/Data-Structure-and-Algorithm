#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long n, S, re = 0;
    cin >> n >> S;
    
    priority_queue<long, vector<long long>, greater<long long>> pq; // Hàng đợi ưu tiên tăng dần
    
    for (int i = 0; i < n; i++) {
        long long ai;
        cin >> ai;
        pq.push(ai);
    }
    
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        
        long long b = pq.top();
        pq.pop();
        
        re += a + b;
        
        pq.push(a + b); // Thêm đoạn gỗ đã cắt thành công vào hàng đợi
    }
    
    cout << re << endl;
    
    return 0;
}
