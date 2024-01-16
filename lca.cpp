////
//// Created by myungki cho on 2024/01/16.
////
//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//
//#define MAXN 10001
//using namespace std;
//typedef pair<int,int> pii;
//
//int T, V, E, t1, t2;
//
//int treeSize[MAXN];
//int parent[MAXN][18];
//int level[MAXN];
//
//void clear() {
//    memset(treeSize, 0, sizeof(treeSize));
//    memset(parent, 0, sizeof(parent));
//    memset(level, 0, sizeof(level));
//}
//
//void set_parent(int node, int p, int lv, vector<int> edges[MAXN]) {
//    level[node] = lv;
//    parent[node][0] = p;
//    for(int i = 1; i < 18; i++) {
//        parent[node][i] = parent[parent[node][i-1]][i-1];
//    }
//    for(auto next: edges[node]) {
//        if(next != p)
//        set_parent(next, node, lv+1, edges);
//    }
//}
//int make_graph(int cur, int p, vector<int> edges[MAXN]) {
//    int tree_size = 1;
//    for(auto next: edges[cur]) {
//        if(next != p)
//        tree_size += make_graph(next, cur, edges);
//    }
//    return treeSize[cur] = tree_size;
//}
//
//int lca(int a, int b) {
//    if(!a || !b) return 0;
//
//    int low_level = a, high_level = b;
//    if(level[low_level] > level[high_level]) {
//        swap(low_level, high_level);
//    }
//
//    if(level[low_level] != level[high_level]) {
//        for(int i = 17; i>= 0; i--) {
//            if(level[parent[high_level][i]] >= level[low_level]) {
//                high_level = parent[high_level][i];
//            }
//        }
//    }
//
//    int ret = high_level;
//    if(high_level != low_level) {
//        for(int i = 17; i >= 0; i--) {
//            if(parent[high_level][i] != parent[low_level][i]) {
//                high_level = parent[high_level][i];
//                low_level = parent[low_level][i];
//            }
//            ret = parent[high_level][i];
//        }
//    }
//    return ret;
//}
//
//
//pii solve(int t1, int t2, vector<int> edges[MAXN]) {
//    set_parent(1,0,0, edges);
//    make_graph(1,1, edges);
//    int lca_node = lca(t1,t2);
//    return {lca_node, treeSize[lca_node]};
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//    for (int i = 1; i <= T; i++) {
//        vector<int> edges[MAXN];
//        cin >> V >> E >> t1 >> t2;
//        for(int j = 0; j < E; j++) {
//            int p, c;
//            cin >> p >> c;
//            edges[p].push_back(c);
//            edges[c].push_back(p);
//        }
//        pii ans = solve(t1, t2, edges);
//        clear();
//        cout << "#" << i << " " << ans.first << " " << ans.second << "\n";
//    }
//    return 0;
//}
//
