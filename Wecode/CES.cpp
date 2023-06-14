#include <bits/stdc++.h>
using namespace std;

class Sum_index {
public:
    int first_indx, second_indx;
    long long sum;

    Sum_index(int first_, int second_, long long sum_) {
        first_indx = first_;
        second_indx = second_;
        sum = sum_;
    }
};

bool compare(const Sum_index* a, const Sum_index* b) {
    return a->sum < b->sum;
}

bool trung(Sum_index* a, Sum_index* b) {
    if ((a->first_indx == b->first_indx) || (a->first_indx == b->second_indx) || (a->second_indx == b->first_indx) || (a->second_indx == b->second_indx)){
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    long long m;
    cin >> m;
    bool print = false;
    vector<long long> arr(n);
    vector<Sum_index*> Sums;
    vector<int> re;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Sums.push_back(new Sum_index(i, j, arr[i] + arr[j]));
        }
    }

    sort(Sums.begin(), Sums.end(), compare);

    // for (auto item : Sums) {
    //     cout << item->first_indx << " " << item->second_indx << " " << item->sum << endl;
    // }

    // for (int i = 0; i < Sums.size(); i++) {
        
    //     for (int j = i + 1; j < Sums.size(); j++) {
    //         if (Sums[i]->sum + Sums[j]->sum == m && !trung(Sums[i], Sums[j])) {
    //             cout << Sums[i]->first_indx << " " << Sums[i]->second_indx << " " << Sums[j]->first_indx << " " << Sums[j]->second_indx;
    //         }
    //     }
    // }
    int i = 0, j = Sums.size() - 1;
    while(i < Sums.size() && j >= 0){
        if(Sums[i]->sum + Sums[j]->sum == m && !trung(Sums[i], Sums[j])){
            re.push_back(Sums[i]->first_indx);
            re.push_back(Sums[i]->second_indx);
            re.push_back(Sums[j]->first_indx);
            re.push_back(Sums[j]->second_indx);
            sort(re.begin(),re.end());
            print = true;
            break;
        }
        else if(Sums[i]->sum + Sums[j]->sum < m){
            i++;
        }
        else {
            j--;
        }
    }

    for (auto item : Sums) {
        delete item;
    }
    if(print){
        for(auto item: re){
            cout << item + 1 << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}