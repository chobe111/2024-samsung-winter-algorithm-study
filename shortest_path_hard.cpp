//#include<unordered_map>
//#include<unordered_set>
//#include<vector>
//#include<queue>
//#include<functional>
//
//using namespace std;
//typedef long long ll;
//typedef pair<ll, ll> pll;
//const ll INF = 1000000000 * 1000000LL;
//
//unordered_map <ll, vector<pll>> edges;
//unordered_map <ll, vector<pll>> r_edges;
//// �� ������� ���� �ִ� 600��
//unordered_set<ll> nodes;
//void clear() {
//	nodes.clear();
//	edges.clear();
//	r_edges.clear();
//}
//
//ll get_dijkstra_distance(ll start_node, unordered_map<ll, vector<pll>> &graph) {
//	// Time Complexity: O(N * logM) N = max 600 log(M) = max 11 => 6001
//	ll dijkstra_distance = 0;
//	unordered_map<ll, ll> dist;
//	for (ll node : nodes) {
//		dist.insert({ node, INF });
//	}
//	priority_queue<pll, vector<pll>, greater<>> pq;
//	pq.push({ 0, start_node });
//	while (!pq.empty()) {
//		pll f = pq.top();
//		ll cur_dist = f.first;
//		ll cur_node = f.second;
//		pq.pop();
//
//		if (dist.find(cur_node)->second != INF) continue;
//		dist.find(cur_node)->second = cur_dist;
//
//		for (pll next : (graph.find(cur_node)->second)) {
//			ll next_node = next.first;
//			ll next_distance = next.second + cur_dist;
//
//			if (next_distance < dist.find(next_node)->second) {
//				pq.push({ next_distance, next_node });
//			}
//		}
//	}
//
//	for (ll node : nodes) {
//		if (node != start_node) {
//			dijkstra_distance += dist.find(node)->second;
//		}
//	}
//	return dijkstra_distance;
//}
//
//void insert_to_graph(ll s_num, ll e_num, ll dist, unordered_map<ll, vector<pll>> &target_edges) {
//	if (target_edges.find(s_num) == target_edges.end()) {
//		vector<pll> vec;
//		vec.push_back({ e_num, dist });
//		target_edges.insert({ s_num,vec });
//	}
//	else {
//		target_edges.find(s_num)->second.push_back({e_num, dist});
//	}
//	return;
//}
//int init(int N, int sCity[], int eCity[], int mCost[]) {
//	// �׷��� �ʱ�ȭ
//	clear();
//	for (int i = 0; i < N; i++) {
//		ll s_num = sCity[i];
//		ll e_num = eCity[i];
//		ll dist = mCost[i];
//		if (nodes.find(s_num) == nodes.end()) {
//			nodes.insert(s_num);
//		}
//		if (nodes.find(e_num) == nodes.end()) {
//			nodes.insert(e_num);
//		}
//		insert_to_graph(s_num, e_num, dist, edges);
//		insert_to_graph(e_num, s_num, dist, r_edges);
//	}
//
//	return nodes.size();
//}
//
//void add(int sCity, int eCity, int mCost) {
//	insert_to_graph(sCity, eCity, mCost, edges);
//	insert_to_graph(eCity, sCity, mCost, r_edges);
//	return;
//}
//
//int cost(int mHub) {
//	return get_dijkstra_distance(mHub, edges) + get_dijkstra_distance(mHub, r_edges);
//}