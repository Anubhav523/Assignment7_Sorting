#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<int> maxSumCombination(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int n = a.size();

    // Max heap: stores {sum, {i,j}}
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;

    pq.push({a[0] + b[0], {0,0}});
    s.insert({0,0});

    vector<int> res;
    while (k-- && !pq.empty()) {
        auto top = pq.top(); pq.pop();
        res.push_back(top.first);

        int i = top.second.first, j = top.second.second;

        if (i + 1 < n && !s.count({i+1, j})) {
            pq.push({a[i+1] + b[j], {i+1, j}});
            s.insert({i+1, j});
        }
        if (j + 1 < n && !s.count({i, j+1})) {
            pq.push({a[i] + b[j+1], {i, j+1}});
            s.insert({i, j+1});
        }
    }
    return res;
}

int main() {
    // Example 1
    vector<int> a1 = {3, 2};
    vector<int> b1 = {1, 4};
    int k1 = 2;
    vector<int> res1 = maxSumCombination(a1, b1, k1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << "\n"; // Expected: 7 6

    // Example 2
    vector<int> a2 = {1, 4, 2, 3};
    vector<int> b2 = {2, 5, 1, 6};
    int k2 = 3;
    vector<int> res2 = maxSumCombination(a2, b2, k2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << "\n"; // Expected: 10 9 9

    return 0;
}
