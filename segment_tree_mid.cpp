#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_UPDATE 300
#define CMD_UPDATE_TYPE 400
#define CMD_CALC 500

void init(int N, int M, int mType[], int mTime[]);
void destroy();
void update(int mID, int mNewTime);
int updateByType(int mTypeID, int mRatio256);
int calculate(int mA, int mB);

#define MAX_N 100000

static int mType[MAX_N];
static int mTime[MAX_N];

static int run()
{
	int C;
	int isOK = 0;
	int cmd, ret, chk;

	int N, M;
	int mID, mTypeID, mNewTime, mRatio;
	int mA, mB;

	scanf("%d", &C);

	for (int c = 0; c < C; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d %d ", &N, &M);
			for (int i = 0; i < N - 1; i++) scanf("%d", &mType[i]);
			for (int i = 0; i < N - 1; i++) scanf("%d", &mTime[i]);
			init(N, M, mType, mTime);
			isOK = 1;
			break;

		case CMD_UPDATE:
			scanf("%d %d", &mID, &mNewTime);
			update(mID, mNewTime);
			break;

		case CMD_UPDATE_TYPE:
			scanf("%d %d", &mTypeID, &mRatio);
			ret = updateByType(mTypeID, mRatio);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		case CMD_CALC:
			scanf("%d %d", &mA, &mB);
			ret = calculate(mA, mB);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}
	destroy();
	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#define MAXN 100001
using namespace std;

int tree[MAXN << 2 + 1];
int arr[MAXN];
int N_SIZE;
vector<int> m_vec[1001];

int make_tree(int s,int e, int ti) {
	if (s == e) return tree[ti] = arr[s];
	int m = (s + e) / 2;
	return tree[ti] = make_tree(s, m, ti * 2) + make_tree(m + 1, e, ti * 2 + 1);
}

void update_tree(int s,int e, int ti, int target_index, int target_value, bool ratio_mode, int &total) {
	if (s == e) {
		if (target_index == s) {
			if (ratio_mode) {
				tree[ti] = tree[ti] * target_value / 256;
			}
			else {
				tree[ti] = target_value;
			}
			total = total + tree[ti];
		}
		return;
	}
	int m = (s + e) / 2;
	if (target_index <= m) {
		update_tree(s, m, ti * 2, target_index, target_value, ratio_mode, total);
	}
	else {
		update_tree(m + 1, e, ti * 2 + 1, target_index, target_value, ratio_mode, total);
	}

	tree[ti] = tree[ti * 2] + tree[ti * 2 + 1];
}

int find(int s,int e, int l, int r, int ti) {
	if (r < s || l > e) return 0;
	if (l <= s && e <= r) return tree[ti];
	if (s == e) return tree[ti];
	int m = (s + e) / 2;
	return find(s, m, l, r, ti * 2) + find(m + 1, e, l, r, ti * 2 + 1);
}

void init(int N, int M, int mType[], int mTime[])
{
	N_SIZE = N - 2;
	for (int i = 0; i < N-1; i++) {
		arr[i] = mTime[i];
		m_vec[mType[i]].push_back(i);
	}
	make_tree(0, N_SIZE, 1);
}

void destroy()
{
	memset(tree, 0, sizeof(tree));
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 1001; i++) {
		m_vec[i].clear();
	}
}

void update(int mID, int mNewTime)
{
	int temp = 0;
	update_tree(0, N_SIZE, 1, mID, mNewTime, false, temp);
}

int updateByType(int mTypeID, int mRatio256)
{
	int total = 0;
	for (int mID : m_vec[mTypeID]) {
		update_tree(0, N_SIZE, 1, mID, mRatio256, true, total);
	}
	cout <<"update: " << total << '\n';
	return total;
}

int calculate(int mA, int mB) {
	if (mA > mB) {
		int temp = mA;
		mA = mB;
		mB = temp;
	}

	int ans = find(0, N_SIZE, mA, mB - 1, 1);
	cout <<"ans: " << ans << '\n';
	return find(0, N_SIZE, mA, mB - 1, 1);
}