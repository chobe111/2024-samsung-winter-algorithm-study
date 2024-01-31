/*
#include<iostream>
#include<functional>
#include<vector>
#include<cstring>
#include<algorithm>

#define MAXN 200001
using namespace std;
int W[MAXN], N, K, S[MAXN];

// O(N)
bool possible(int w) {
    vector<int> ret;
    int dist = 0;
    for (int i = 0; i < N; i++) {
        if (W[i] > w) {
            if (dist != 0) ret.push_back(dist);
            dist = 0;
            continue;
        }
        ++dist;
    }
    if (dist != 0) {
        ret.push_back(dist);
    }

    int ret_size = int(ret.size());
    if (ret_size == 0) return false;

    int ri = 0;
    int remain = ret[ri];

    for (int i = 0; i < S.size(); i++) {
        if (remain >= S[i]) {
            remain -= S[i];
        } else {
            bool flag = true;
            ri++;
            while(ri != ret.size()) {
                remain = ret[ri];
                if (remain >= S[i]) {
                    remain -= S[i];
                    flag = false;
                    break;
                }
                ri++;
            }
            if(flag) return false;
        }
    }
    return true;
}


int solve() {
    memset(W, 0, sizeof(W));
    memset(S,0,sizeof(S));
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> W[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> S[i];
    }
    int s = 0;
    int e = MAXN-1;
    while (s < e) {
        int m = (s + e) / 2;
        if (possible(m)) {
            e = m;
        } else {
            s = m + 1;
        }
    }
    return e;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "#" << i << " " << solve() << "\n";
    }
    return 0;
}*/
