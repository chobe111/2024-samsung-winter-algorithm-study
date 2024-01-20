//
// Created by myungki cho on 2024/01/20.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define all(v) v.begin(), v.end()
using namespace std;
int T, N, M, c1, c2;

int lower_bound(vector<int> &vec, int target) {
    int ret = 987654321;
    int s = 0;
    int e = int(vec.size()) - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (vec[m] <= target) {
            ret = vec[m];
            s = m + 1;
        } else {
            e = m;
        }
    }
    return ret;
}

int upper_bound(vector<int> &vec, int target) {
    int s = 0;
    int e = int(vec.size()) - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (vec[m] <= target) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return vec[s];
}

int main() {
    fastIO;
    cin >> T;
    vector<int> tvec;
    tvec.push_back(1);
    tvec.push_back(4);
    tvec.push_back(5);
    tvec.push_back(7);
    sort(all(tvec));

//    cout << lower_bound(tvec, 6) << " " << upper_bound(tvec, 6) << "\n";

    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> c1 >> c2;
        int c_dist = abs(c1 - c2);
        vector<int> vec;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            vec.push_back({num});
        }
        // 1 3 5
        //    4
        int min_dist = 300000000;
        int cnt = 0;
        sort(all(vec));
        for (int i = 0; i < M; i++) {
            int num;
            cin >> num;
            int upper_num = upper_bound(vec, num);
            int lower_num = lower_bound(vec, num);

            int tp1 = abs(upper_num - num);
            int tp2 = abs(lower_num - num);
            int cur_min = min(tp1, tp2);

            int cur_cnt = 0;
            if (tp1 == cur_min) cur_cnt++;
            if (tp2 == cur_min) cur_cnt++;

            if (cur_min < min_dist) {
                min_dist = cur_min;
                cnt = cur_cnt;
            } else if (cur_min == min_dist) {
                cnt += cur_cnt;
            }
        }

        cout << "#" << t << " " << min_dist + c_dist << " " << cnt << "\n";
    }
}