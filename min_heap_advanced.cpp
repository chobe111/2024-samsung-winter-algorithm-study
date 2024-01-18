//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include<set>
//#include<functional>
//
//using namespace std;
//
//typedef long long ll;
//
//struct Node {
//    ll x;
//    ll cnt;
//    ll d;
//};
//
//struct Compare {
//    bool operator()(Node &a, Node &b) {
//        return a.cnt > b.cnt;
//    }
//};
//
//ll T, N, K;
//
//
//void print_ans(int testcase, ll ans) {
//    cout << "#" << testcase << " " << ans << "\n";
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//        ll ans = -1;
//        cin >> N;
//        set<pair<ll, ll>> chk;
//        vector<ll> vec(N);
//        sort(vec.begin(), vec.end(), greater<>());
//        for (int i = 0; i < N; i++) cin >> vec[i];
//        cin >> K;
//        priority_queue<Node, vector<Node>, Compare> pq;
//        pq.push({0, 0, 1});
//
//        while (!pq.empty()) {
//            Node top = pq.top();
//            ll x = top.x;
//            ll d = top.d;
//            ll cnt = top.cnt;
//            pq.pop();
//
//            if (x == K) {
//                ans = cnt;
//                break;
//            }
//            if (chk.find({x + d, d}) == chk.end() && x + d <= K && (K-x) % d == 0) {
//                chk.insert({x+d,d});
//                pq.push({x+d, cnt + 1, d});
//            }
//
//            for (ll nd: vec) {
//                ll next_d = nd * d;
//                if (chk.find({x, next_d}) == chk.end() && x + next_d <= K && ((K - x) % next_d == 0)) {
//                    chk.insert({x,next_d});
//                    pq.push({K, cnt + (K - x) / next_d , next_d});
//                }
//            }
//        }
//
//        print_ans(t, ans);
//    }
//
//    return 0;
//}
//
