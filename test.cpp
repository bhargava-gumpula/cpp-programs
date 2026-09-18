// incomplete
 /*
 #include <stdio.h>
 #include <vector>
 #include <iostream>
 
 using namespace std;
 
 int main () {
    int k;
    int n;
    
    cin >> k >> n;
    

    int current_position;
    int current_speed;
    int time_passed;

    for (int i = 0; i < n; i++) {
        int speed_limit;
        cin >> speed_limit;
        
        
        // we have the speedlimit in vairable speed_limit
        // we have the total distance from the police station
        // as k
        
        current_position = 0;
        current_speed = 0;
        time_passed = 0; 
        while (true) {
            int dist_remaining = k - current_position;
            if (dist_remaining > 0 && current_position + current_speed + 1 < k) {
                current_speed ++;
                time_passed ++;
                current_position += current_speed;
            }
            else if (dist_remaining > 0 && current_position + current_speed+1 >= k) {
                if (current_speed <= speed_limit) {
                    current_position += current_speed;
                    time_passed ++;
                    break;
                }
                else {  // current speed > speed_limit;
                    current_position += current_speed;
                }
            }
            else {
                break;
            }
        }
    }

    cout << time_passed << endl;
 }

----------------------
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < n; j++) {
            grid.at(i).at(j) = temp[j] - '0';
        }
    }

    // we have our field as a n x n grid

    unordered_set<int> existing_cows;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid.at(i).at(j) != 0) {
                existing_cows.insert(grid.at(i).at(j));
            }
        }
    }

    unordered_set<int> cant_be;

    for (const auto& cow : existing_cows) {
        int min_row = n, max_row = -1;
        int min_col = n, max_col = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == cow) {
                    min_row = min(min_row, i);
                    max_row = max(max_row, i);
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }

        pair<int, int> top_left = {min_row, min_col};
        pair<int, int> bottom_right = {max_row, max_col};



        for (int i = top_left.first; i <= bottom_right.first; i++) {
            for (int j = top_left.second; j <= bottom_right.second; j++) {
                if (grid[i][j] != cow) {
                    cant_be.insert(grid[i][j]);
                }
            }
        }
    }

    int c = 0;
    for (const auto& cow : existing_cows) {
        if (cant_be.count(cow) == 0) {
            c++;
        }
    }
    cout << c << endl;
}
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {

    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    
    vector<vector<bool>> grid(2000);
    for (int i = 0; i < 2000; i++) {
        vector<bool> row (2000);
        for (int j = 0; j < 2000; j++){
            row[j] = false;
        }
        grid[i] = row;
    }

    int x1; 
    int x2; 
    int y1;
    int y2;

    fin >> x1 >> y1 >> x2 >> y2;
    x1+=1000;
    x2+=1000;
    y1+=1000;
    y2+=1000;

    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++) {
            grid[x][y] = true;
        }
    }

    fin >> x1 >> y1 >> x2 >> y2;
    x1+=1000;
    x2+=1000;
    y1+=1000;
    y2+=1000;

    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++) {
            grid[x][y] = false;
        }
    }


    pair<int, int> tcorner = {2001, 0};
    pair<int, int> bcorner = {0, 2001};

    for (int x = 0; x < 2000; x++) {
        for (int y = 0; y < 2000; y++) {
            if (grid[x][y] == true) {
                tcorner.first = min(tcorner.first, x);
                tcorner.second = max(tcorner.second, y);
                bcorner.first = max(bcorner.first, x);
                bcorner.second = min(bcorner.second, y); 
            }
        }
    }

    if (tcorner.first == 2001 && tcorner.second == 0 && bcorner.first == 0 && bcorner.second == 2001) {
        fout << 0 << endl;
    }
    else {
        fout << (bcorner.first - tcorner.first + 1) * (tcorner.second - bcorner.second + 1) << endl;
    }
    fin.close();
    fout.close();
}