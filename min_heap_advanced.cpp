//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include<set>
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<ll, ll> pll;
//typedef pair<pll, pll> pllll;
//ll T, N, K;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//        ll ans = -1;
//        cin >> N;
//        vector<ll> vec(N);
//        for (int i = 0; i < N; i++) cin >> vec[i];
//        sort(vec.begin(), vec.end());
//        cin >> K;
//        priority_queue<pllll, vector<pllll>, greater<>> pq;
//        // cnt x remain d
//        pq.push({{0, K},
//                 {0, 1}});
//        while (!pq.empty()) {
//            pllll f = pq.top();
//            pq.pop();
//
//            ll cnt = f.first.first;
//            ll x = f.first.second;
//            ll remain = f.second.first;
//            ll d = f.second.second;
//
//            cout << cnt << " " << x << " " << remain << " " << d << "\n";
//
//            if (x == 0) {
//                ans = cnt;
//                break;
//            }
//
//            for (ll next_d: vec) {
//                // cnt x remain d
//                // 만약 현재 숫자가 커버리면
//                if (next_d > x) {
//                    pq.push({{cnt + x, remain},
//                             {0,       1}});
//                } else {
//                    pq.push({{cnt, x / next_d},
//                             {remain + (x % next_d) * d,   next_d * d}});
//                }
//            }
//
//        }
//        cout << "#" << t << " " << ans << "\n";
//
//    }
//
//    return 0;
//}
//
