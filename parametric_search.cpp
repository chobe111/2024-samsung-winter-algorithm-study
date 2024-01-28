////
//// Created by myungki cho on 2024/01/20.
////
//#include<iostream>
//#include<vector>
//#include<cstring>
//
//#define MAXN 1300002
//
//#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
//using namespace std;
//int T, N, P;
//
//int psum[MAXN];
//
//int main() {
//    fastIO;
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//        memset(psum, 0, sizeof(psum));
//        int ans = -1;
//        cin >> N >> P;
//        int MAX_N = -1;
//        for (int i = 0; i < N; i++) {
//            int num;
//            cin >> num;
//            if(num+1 > MAX_N) {
//                MAX_N = num+1;
//            }
//            psum[num + 1] = 1;
//        }
//        for (int i = 1; i < MAX_N+1; i++) {
//            if (!psum[i]) psum[i] = 1 + psum[i - 1];
//            else psum[i] = psum[i - 1];
//        }
//
//        for (int i = 1; i < MAX_N+1; i++) {
//            int s = i, e = MAX_N+1;
//            while (s < e) {
//                int m = (s + e) / 2;
//                int empty_numbers = psum[m] - psum[i - 1];
//                if (empty_numbers <= P) {
//                    ans = max(ans, m - i + 1 + P - empty_numbers);
//                    s = m + 1;
//                } else {
//                    e = m;
//                }
//            }
//        }
//        cout << "#" << t << " " << ans << "\n";
//    }
//}