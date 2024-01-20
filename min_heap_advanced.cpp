//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<ll, ll> pll;
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
//        priority_queue<pll, vector<pll>, greater<>> pq;
//        for (int i = 0; i < N; i++) {
//            cin >> vec[i];
//        }
//        cin >> K;
//        pq.push({0, K});
//        while (!pq.empty()) {
//            pll f = pq.top();
//            pq.pop();
//            ll cnt = f.first;
//            ll x = f.second;
//
//            if(x==0) {
//                ans = cnt;
//                break;
//            }
//
//            for (ll next: vec) {
//                pq.push({cnt + x % next, x / next});
//            }
//        }
//        cout << "#" << t << " " << ans << "\n";
//    }
//
//    return 0;
//}
//
