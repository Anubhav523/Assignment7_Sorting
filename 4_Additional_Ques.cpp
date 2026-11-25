#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortEvenOdd(vector<int>& arr) {
    vector<int> even, odd;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    sort(even.begin(), even.end());                  // increasing
    sort(odd.begin(), odd.end(), greater<int>());    // decreasing

    vector<int> res;
    res.insert(res.end(), even.begin(), even.end());
    res.insert(res.end(), odd.begin(), odd.end());
    return res;
}

int main() {
    // Example 1
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> res1 = sortEvenOdd(arr1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << "\n"; // Expected: 0 2 4 6 7 5 3 1

    // Example 2
    vector<int> arr2 = {3, 1, 2, 4, 5, 9, 13, 14, 12};
    vector<int> res2 = sortEvenOdd(arr2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << "\n"; // Expected: 2 3 5 12 13 14 9 4 1

    return 0;
}
