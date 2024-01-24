#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAXN 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 10e11;
pll tree[MAXN << 2 + 1];
ll arr[MAXN];
int T;

// min max divide and conquer segment tree Time Complexity: O(N) * log(N)
pll make_tree(int s,int e, int ti) {
	if (s == e) return  tree[ti] = {arr[s], arr[s]};
	int m = (s + e) / 2;

	pll left = make_tree(s, m, ti*2);
	pll right = make_tree(m + 1, e, ti*2 + 1);
	
	return tree[ti] = { min(left.first, right.first), max(left.second, right.second) };
}

// Time Complexity: log(N)
void update_tree(int s,int e, int ti, int target_index, ll target_value) {
	if (s == e) {
		if(s==target_index)
		tree[ti] = { target_value, target_value };
		return;
	}
	int m = (s + e) / 2;
	if (target_index <= m) {
		update_tree(s, m, ti * 2, target_index, target_value);
	}
	else {
		update_tree(m + 1, e, ti * 2 + 1, target_index, target_value);
	}
	tree[ti] = { min(tree[ti * 2].first, tree[ti * 2 + 1].first), max(tree[ti * 2].second, tree[ti * 2 + 1].second) };
}

// 0 1 2 3 4 5
// min max
pll find(int s, int e, int l, int r, int ti) {
	if (l > e || r < s) return { INF, -1 };
	if (l <= s && e <= r) return tree[ti];
	if (s == e) return tree[ti];

	int m = (s + e) / 2;
	pll left = find(s, m, l, r, ti * 2);
	pll right = find(m + 1, e, l, r, ti * 2 + 1);

	return { min(left.first, right.first), max(left.second, right.second) };
}

void query(int array_size, vector<ll> &ans_list) {
	int query_type;
	cin >> query_type;

	if (query_type == 0) {
		// update_tree
		int target_index;
		ll target_value;
		cin >> target_index >> target_value;
		update_tree(0, array_size, 1, target_index, target_value);
	}
	else {
		int l, r;
		cin >> l >> r;
		pll ans = find(0, array_size, l, r-1, 1);
		ans_list.push_back(ans.second - ans.first);
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(arr, 0, sizeof(arr));
	memset(tree, 0, sizeof(tree));
	int n, q;
	vector<ll> ans_list;
	cin >> n >> q;
	// 0-based
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// initialize tree
	make_tree(0, n - 1, 1);
	for (int i = 1; i <= q; i++) {
		query(n-1, ans_list);
	}

	for (ll ans_c : ans_list) {
		cout << ans_c << " ";
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " ";
		solve();
		cout << '\n';
	}
}