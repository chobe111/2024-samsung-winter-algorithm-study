////
//// Created by myungki cho on 2024/01/19.
////
//#include<iostream>
//
//typedef long long ll;
//using namespace std;
//
//int T;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    cin >> T;
//
//    for (int i = 1; i <= T; i++) {
//        ll N;
//        cin >> N;
//
//        ll ans = -1;
//        ll s = 0;
//        ll e = 2 * 10e9;
//        while (s <= e) {
//            ll m = (s + e) / 2;
//            ll sum = m * (m + 1) / 2;
//            if (sum == N) {
//                ans = m;
//                break;
//            }
//            if (sum > N) {
//                e = m - 1;
//            } else {
//                s = m + 1;
//            }
//        }
//
//        cout << "#" << i << " " << ans << '\n';
//    }
//    return 0;
//}