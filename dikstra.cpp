#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define MAXN 50001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int T, N, M, X;
const ll INF = 2000000000LL * 500000LL;
ll dist[MAXN];
ll r_dist[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dist, 0, sizeof(dist));
		memset(r_dist, 0, sizeof(r_dist));
		cin >> N >> M >> X;
		vector<vector<pll>> edges(N + 1);
		vector<vector<pll>> r_edges(N + 1);

		priority_queue<pll, vector<pll>, greater<>> pq;

		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
			r_dist[i] = INF;
		}

		r_dist[X] = 0;
		dist[X] = 0;
		for (int i = 1; i <= M; i++) {
			ll a, b, c;
			cin >> a >> b >> c;
			edges[a].push_back({ b,c });
			r_edges[b].push_back({ a,c });
		}
		ll ans = -1;

		for (pll next : edges[X]) {
			ll next_node = next.first;
			ll next_dist = next.second;

			pq.push({ next_dist, next_node });
		}

		while (!pq.empty()) {
			pll f = pq.top();
			pq.pop();
			ll cur_dist = f.first;
			ll cur_node = f.second;

			if (dist[cur_node] != INF) continue;

			dist[cur_node] = cur_dist;

			for (pll next : edges[cur_node]) {
				ll next_dist = next.second + cur_dist;
				ll next_node = next.first;

				if (next_dist < dist[next_node]) {
					pq.push({ next_dist, next_node });
				}
			}
		}

		for (pll next : r_edges[X]) {
			ll next_node = next.first;
			ll next_dist = next.second;

			pq.push({ next_dist, next_node });
		}

		while (!pq.empty()) {
			pll f = pq.top();
			pq.pop();
			ll cur_dist = f.first;
			ll cur_node = f.second;

			if (r_dist[cur_node] != INF) continue;

			r_dist[cur_node] = cur_dist;

			for (pll next : edges[cur_node]) {
				ll next_dist = next.second + cur_dist;
				ll next_node = next.first;

				if (next_dist < r_dist[next_node]) {
					pq.push({ next_dist, next_node });
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			ans = max(ans, dist[i] + r_dist[i]);
		}

		cout << "#" << t << " " << ans << '\n';
	}
}