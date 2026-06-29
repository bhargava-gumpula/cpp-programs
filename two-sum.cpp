// CSES SORTING AND SEARCHING PROBLEM

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct custom_hash {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x;
    }
};



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int target;
    cin >> n >> target;

    if (target == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    unordered_map<int, int, custom_hash> check;
    bool found = false;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (check.count(target-num) > 0) {
            cout << check[target-num] << " " << i+1 << endl;
            found = true;
            break;
        }

        check[num] = i+1;
    }

    if (found == false) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
    
}