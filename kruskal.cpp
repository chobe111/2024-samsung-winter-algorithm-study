////
//// Created by myungki cho on 2024/01/17.
////
//
///*
// * 1 2
// * 2 5
// * 5 1
// *
// *
// * */
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//typedef long long ll;
//typedef pair<ll, ll> pii;
//ll T, N;
//double E;
//ll arr_x[1001], arr_y[1001], parent[1001];
//
//ll get_parent(ll p) {
//    if (p == parent[p]) return p;
//    return parent[p] = get_parent(parent[p]);
//}
//
//void clear() {
//    for(ll i = 1; i <= N; i++) {
//        parent[i] = i;
//    }
//    memset(arr_x, 0, sizeof(arr_x));
//    memset(arr_y, 0, sizeof(arr_y));
//}
//
//void union_parent(ll a, ll b) {
//    a = get_parent(a);
//    b = get_parent(b);
//    if (a < b) {
//        parent[b] = a;
//    } else {
//        parent[a] = b;
//    }
//}
//
//long long solve() {
//    double ans = 0;
//
//    vector<pair<double, pii> > vec;
//
//    for (ll i = 1; i <= N; i++) {
//        for (ll j = i + 1; j <= N; j++) {
//            ll x1 = arr_x[i];
//            ll y1 = arr_y[i];
//
//            ll x2 = arr_x[j];
//            ll y2 = arr_y[j];
//
//            double dist = static_cast<double>(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))) * E;
//
//            vec.push_back({dist, {i, j}});
//        }
//    }
//
//    sort(vec.begin(), vec.end());
//
//    for (ll i = 0; i < vec.size(); i++) {
//        pair<double, pii> dpii = vec[i];
//        double dist = dpii.first;
//        ll a = dpii.second.first;
//        ll b = dpii.second.second;
//
//        if (get_parent(a) != get_parent(b)) {
//            union_parent(a, b);
//            ans += dist;
//        }
//    }
//
//    return round(ans);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//    for (ll t = 1; t <= T; t++) {
//        cin >> N;
//        for(ll i = 1; i <= N; i++) {
//            parent[i] = i;
//        }
//        memset(arr_x, 0, sizeof(arr_x));
//        memset(arr_y, 0, sizeof(arr_y));
//        for (ll i = 1; i <= N; i++) cin >> arr_x[i];
//        for (ll i = 1; i <= N; i++) cin >> arr_y[i];
//        cin >> E;
//        cout << "#" << t << " " << solve() << "\n";
//    }
//
//    return 0;
//}