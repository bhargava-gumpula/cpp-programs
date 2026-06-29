// CSES SORTING AND SEARCHING PROBLEM

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int distinct = unique(nums.begin(), nums.end()) - nums.begin();

    cout << distinct << "\n";
}
