////
//// Created by myungki cho on 2024/01/16.
////
//
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<set>
//
//#define MAXN 101
//
//using namespace std;
//
//int T, N, M;
//
//int parent[MAXN];
//
//int get_parent(int n) {
//    if (parent[n] == n) {
//        return parent[n];
//    }
//    return parent[n] = get_parent(parent[n]);
//}
//
//void union_parent(int a, int b) {
//    int a_parent = get_parent(a);
//    int b_parent = get_parent(b);
//
//    if (a_parent < b_parent) {
//        parent[b_parent] = a_parent;
//    } else {
//        parent[a_parent] = b_parent;
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//
//    for (int t=1; t<= T; t++) {
//        memset(parent,0,sizeof(parent));
//        cin >> N >> M;
//        set<int> st;
//        // 부모 초기화
//        for (int i = 1; i <= N; i++) {
//            parent[i] = i;
//        }
//
//        for (int i = 1; i <= M; i++) {
//            int a, b;
//            cin >> a >> b;
//            union_parent(a, b);
//        }
//
//        for(int i = 1; i <= N; i++) {
//            st.insert(get_parent(parent[i]));
//        }
//
//        cout << "#" << t << " " <<st.size() << '\n';
//    }
//    return 0;
//}