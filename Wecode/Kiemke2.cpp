#include <bits/stdc++.h>
using namespace std;

const int mN = 1e5 + 10;
using si = pair<string, int>;
int res;
string sto[mN];

bool cmpString(const string &s1, const string &s2) {
    if (s1.size() > s2.size()) return false;
    if (s1.size() < s2.size()) return true;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) return false;
        if (s1[i] < s2[i]) return true;
    }
}

bool cmp(const si &u, const si &v) {
    return (u.second > v.second) || (u.second == v.second && cmpString(u.first, v.first));
}

class Heap {
private:
    vector<si> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    void heapifyUp(int i) {
        if (i && !cmp(heap[parent(i)], heap[i])) {
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && cmp(heap[l], heap[largest])) {
            largest = l;
        }

        if (r < heap.size() && cmp(heap[r], heap[largest])) {
            largest = r;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    Heap() {}

    void push(si val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (!heap.empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    si top() {
        if (!heap.empty()) {
            return heap[0];
        }
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
} pq;

class HeapString {
private:
    vector<string> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    void heapifyUp(int i) {
        if (i && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    HeapString() {}

    void push(string val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (!heap.empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    string top() {
        if (!heap.empty()) {
            return heap[0];
        }
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
} HeapString;

string b[mN];
si c[mN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    string str;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        HeapString.push(str);
    }
    for (int i = 1; i <= n; i++) {
        sto[i] = HeapString.top();
        HeapString.pop();
    }
    string lastVal = "", val;
    for (int i = 1; i <= n; i++) {
        val = sto[i];
        if (val == lastVal) c[cnt].second++;
        else {
            c[++cnt] = {val, 1};
            lastVal = val;
        }
    }
    for (int i = 1; i <= cnt; i++) pq.push(si(c[i]));
    while (pq.size()) {
        si x = pq.top();
        pq.pop();
        cout << x.first << " " << x.second << "\n";
    }
}
