#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

#define CMD_INIT    1
#define CMD_APPEND  2
#define CMD_CUT     3
#define CMD_REVERSE 4
#define CMD_COUNT   5

extern void init(char mStr[]);
extern void appendWord(char mWord[]);
extern void cut(int k);
extern void reverse();
extern int countOccurrence(char mWord[]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
	bool correct = false;
	int queryCnt;
	scanf("%d", &queryCnt);
	static char mStr[30001], mWord[5];

	while (queryCnt--)
	{
		int cmd;
		scanf("%d", &cmd);

		if (cmd == CMD_INIT)
		{
			scanf("%s", mStr);
			init(mStr);
			correct = true;
		}
		else if (cmd == CMD_APPEND)
		{
			scanf("%s", mWord);

			if (correct)
			{
				appendWord(mWord);
			}
		}
		else if (cmd == CMD_CUT)
		{
			int k;
			scanf("%d", &k);

			if (correct)
			{
				cut(k);
			}
		}
		else if (cmd == CMD_REVERSE)
		{
			if (correct)
			{
				reverse();
			}
		}
		else if (cmd == CMD_COUNT)
		{
			scanf("%s", mWord);

			int ret = -1;
			if (correct)
			{
				ret = countOccurrence(mWord);
				//cout << "CMD_COUNT: " << ret << "\n";
			}

			int ans;
			scanf("%d", &ans);
			if (ret != ans)
			{
				correct = false;
			}
		}
	}
	return correct;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
	return 0;
}


bool is_reverse = false;

deque<char> deq;
int hash_info[1000001];
//        3  4  5 6
// a b c d e f

void front_hash(bool remove) {
	for (int i = 0; i < min(int(deq.size()), 4); i++) {
		int cur_hash = 0;
		for (int j = i; j >= 0; j--) {
			int multi = 1;
			int multi_cnt = i - j;
			while (multi_cnt--) multi *= 26;
			cur_hash += multi * (int(deq[j] - 'a') + 1);
		}
		if (remove) {
			hash_info[cur_hash] -= 1;
		}
		else {
			hash_info[cur_hash] += 1;
		}
	}
}

void back_hash(bool remove) {
	int start_pos = deq.size() - 1;
	int cur_hash = 0;
	for (int i = 0; i < 4; i++) {
		if (start_pos - i < 0) break;
		int multi = 1;
		int multi_cnt = i;
		while (multi_cnt--) {
			multi *= 26;
		}
		cur_hash += multi * (int(deq[start_pos - i] - 'a') + 1);
		if (remove) {
			hash_info[cur_hash] -= 1;
		}
		else {
			hash_info[cur_hash] += 1;
		}
	}
}

void init(char mStr[])
{
	memset(hash_info, 0, sizeof(hash_info));
	deq.clear();
	is_reverse = false;
	int cnt = 0;
	while (mStr[cnt] != '\0') {
		deq.push_back(mStr[cnt]);
		back_hash(false);
		cnt++;
	}
}

void appendWord(char mWord[])
{
	int cnt = 0;
	while (mWord[cnt] != '\0') {
		if (is_reverse) {
			deq.push_front(mWord[cnt]);
			front_hash(false);
		}
		else {
			deq.push_back(mWord[cnt]);
			back_hash(false);
		}
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {

	}
}

void cut(int k)
{
	for (int i = 0; i < k; i++) {
		if (is_reverse) {
			front_hash(true);
			deq.pop_front();
		}
		else {
			back_hash(true);
			deq.pop_back();
		}
	}
}

void reverse()
{
	is_reverse = !is_reverse;
}

int countOccurrence(char mWord[])
{
	int m_hash = 0;
	int word_size = 0;
	while (mWord[word_size] != '\0') {
		word_size++;
	}
	if (is_reverse) {
		for (int i = 0; i < word_size; i++) {
			int multi = 1;
			int multi_cnt = i;
			while (multi_cnt--) {
				multi *= 26;
			}
			m_hash += multi * (int(mWord[i] - 'a') + 1);
		}
	}
	else {
		for (int i = 0; i < word_size; i++) {
			int multi = 1;
			int multi_cnt = word_size - i - 1;
			while (multi_cnt--) {
				multi *= 26;
			}
			m_hash += multi * (int(mWord[i] - 'a') + 1);
		}
	}
	return hash_info[m_hash];
}


