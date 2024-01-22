#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int T, N;
char arr[101][101];
bool chk[101][101];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool in_range(int x, int y) {
	return 1 <= x && x <= N && 1 <= y && y <= N && !chk[x][y];
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		cin >> N;
		int ans = -1;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}

		priority_queue<piii, vector<piii>, greater<>> pq;
		pq.push({ 0,{1,1} });
		chk[1][1] = 1;
		while (!pq.empty()) {
			piii f = pq.top();
			pq.pop();

			int cnt = f.first;
			int cx = f.second.first;
			int cy = f.second.second;

			if (cx == N && cy == N) {
				ans = cnt;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (in_range(nx, ny)) {
					chk[nx][ny] = 1;
					int next_dist = cnt + arr[nx][ny] - '0';
					pq.push({ next_dist,{nx,ny} });
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	} 

	return 0;

}