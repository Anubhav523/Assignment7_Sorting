#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Returns top k elements by frequency.
// If two numbers have the same frequency, the larger number is preferred.
vector<int> topKFrequent(const vector<int>& arr, int k) {
    map<int,int> freq;
    for (int x : arr) freq[x]++;

    // Move map contents to a vector for sorting
    vector<pair<int,int>> items;
    items.reserve(freq.size());
    for (auto &p : freq) items.emplace_back(p.first, p.second); // (value, count)

    // Sort by: higher frequency first; if equal frequency, larger value first
    sort(items.begin(), items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    });

    vector<int> result;
    result.reserve(min(k, (int)items.size()));
    for (int i = 0; i < k && i < (int)items.size(); ++i) result.push_back(items[i].first);
    return result;
}

int main() {
    // Example 1
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1};
    int k1 = 2;
    vector<int> res1 = topKFrequent(arr1, k1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << "\n"; // Expected: 4 1

    // Example 2
    vector<int> arr2 = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k2 = 4;
    vector<int> res2 = topKFrequent(arr2, k2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << "\n"; // Expected: 5 11 7 10

    return 0;
}
