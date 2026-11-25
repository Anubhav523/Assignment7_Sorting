#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    int maxCost = *max_element(costs.begin(), costs.end());
    vector<int> count(maxCost + 1, 0);

    for (int c : costs) count[c]++;

    int bars = 0;
    for (int price = 1; price <= maxCost; price++) {
        while (count[price] > 0 && coins >= price) {
            coins -= price;
            bars++;
            count[price]--;
        }
    }
    return bars;
}

int main() {
    // Example 1
    vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;
    cout << "Output 1: " << maxIceCream(costs1, coins1) << endl; // Expected: 4

    // Example 2
    vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    int coins2 = 5;
    cout << "Output 2: " << maxIceCream(costs2, coins2) << endl; // Expected: 0

    // Example 3
    vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;
    cout << "Output 3: " << maxIceCream(costs3, coins3) << endl; // Expected: 6

    return 0;
}
