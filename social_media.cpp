#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<cstring>
using namespace std;

int timestamp_pid[100001];
int timestamp_user[100001];
int like_info[100001];
unordered_set<int> follow_info[1001];


void init(int N)
{
	memset(timestamp_pid, 0, sizeof(timestamp_user));
	memset(timestamp_user, 0, sizeof(timestamp_user));
	memset(like_info, 0, sizeof(timestamp_user));
	for (int i = 1; i <= N; i++) follow_info[i].clear();
}

// O(1)
void follow(int uID1, int uID2, int timestamp)
{
	follow_info[uID1].insert(uID2);
}

// O(1)
void makePost(int uID, int pID, int timestamp)
{
	timestamp_user[timestamp] = uID;
	timestamp_pid[timestamp] = pID;
}

// O(1)
void like(int pID, int timestamp)
{
	like_info[pID] += 1;
}

// O(N) 
void getFeed(int uID, int timestamp, int pIDList[])
{
	vector<pair<int, int>> vec;
	int criteria_timestamp = max(0, timestamp - 1000);
	for (int i = criteria_timestamp; i <= timestamp; i++) {
		if (timestamp_user[i] == uID || follow_info[uID].find(timestamp_user[i]) != follow_info[uID].end()) {
			vec.push_back({ like_info[timestamp_pid[i]], i });
		}
	}
	// ÃÖ´ë 1000°³
	sort(vec.begin(), vec.end(), greater<>());
	for (int i = 0; i < min(10, (int)vec.size()); i++) {
		pIDList[i] = timestamp_pid[vec[i].second];
	}

	if (vec.size() < 10) {
		int needed_cnt = 10 - vec.size();
		int append_index = 10 - needed_cnt;

		for (int i = criteria_timestamp - 1; i >= 0; i--) {
			if (needed_cnt == 0) break;
			if (timestamp_user[i] == uID || follow_info[uID].find(timestamp_user[i]) != follow_info[uID].end()) {
				pIDList[append_index] = timestamp_pid[i];
				needed_cnt -= 1;
				append_index += 1;
			}
		}
	}
}