#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int T;
string solve() {
	int N;
	cin >> N;
	string s;
	cin >> s;

	set<string> vec;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= s.size() - i; j++) {
			string substr = s.substr(i, j);
			if (vec.find(substr) == vec.end()) vec.insert(substr);
		}
	}

	if (N > vec.size()) {
		return "none";
	}

	int cnt = 0;
	
	for (string sub_str : vec) {
        if (cnt == N - 1) return sub_str;
		cnt += 1;
	}
}
int main() {
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << solve() << "\n";
	}
}