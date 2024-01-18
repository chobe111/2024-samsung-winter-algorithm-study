//
// Created by myungki cho on 2024/01/18.
//
#include<iostream>
#include<queue>
#include<functional>
#include<vector>

#define MOD 20171109
using namespace std;

/**
 * sum = 9 - 6 => 3
 * 1 2 3 4 5
 * 1 (3) 5
 * 5
 *1 3
 *  5 6 8 9
 * 1 2 3
 *
 * 5 (3) 1
 * @return
 */

int T, N;

void add_to_queue(int num,
                  priority_queue<int, vector<int>, less<>> &maxHeap,
                  priority_queue<int, vector<int>, greater<>> &minHeap) {

    int max_val = maxHeap.top();
    if (num < max_val) {
        maxHeap.push(num);
    } else minHeap.push(num);

    // Rebalancing queue
    if (maxHeap.size() > minHeap.size() + 1) {
        maxHeap.pop();
        minHeap.push(max_val);
    } else if (minHeap.size() > maxHeap.size()) {
        int min_val = minHeap.top();
        minHeap.pop();
        maxHeap.push(min_val);
    }
}

int get_median(priority_queue<int, vector<int>, less<>> &maxHeap) {
    return maxHeap.top() % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " ";
        priority_queue<int, vector<int>, less<>> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        int sum = 0;
        int init_num;
        cin >> N >> init_num;
        maxHeap.push(init_num);
        for (int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;
            add_to_queue(a, maxHeap, minHeap);
            add_to_queue(b, maxHeap, minHeap);

            int median = get_median(maxHeap);
            sum += median;
            sum %= MOD;
        }
        cout << sum << "\n";
    }

}