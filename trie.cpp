//#ifndef _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//
//extern void init();
//
//extern int add(char str[]);
//
//extern int remove(char str[]);
//
//extern int search(char str[]);
//
///////////////////////////////////////////////////////////////////////////
//
//#define MAX_LEN 30
//#define CMD_INIT 1
//#define CMD_ADD 2
//#define CMD_REMOVE 3
//#define CMD_SEARCH 4
//
//static bool run() {
//    int q;
//    scanf("%d", &q);
//
//    char str[MAX_LEN + 1];
//    int cmd, ans, ret = 0;
//    bool okay = false;
//
//    for (int i = 0; i < q; ++i) {
//        scanf("%d", &cmd);
//        switch (cmd) {
//            case CMD_INIT:
//                init();
//                okay = true;
//                break;
//            case CMD_ADD:
//                scanf("%s %d", str, &ans);
//                ret = add(str);
//                printf("ADD %d\n", ret);
//                if (ans != ret)
//                    okay = false;
//                break;
//            case CMD_REMOVE:
//                scanf("%s %d", str, &ans);
//                ret = remove(str);
//                printf("REMOVE %d\n", ret);
//                if (ans != ret)
//                    okay = false;
//                break;
//            case CMD_SEARCH:
//                scanf("%s %d", str, &ans);
//                ret = search(str);
//                printf("SEARCH %d\n", ret);
//                if (ans != ret)
//                    okay = false;
//                break;
//            default:
//                okay = false;
//                break;
//        }
//    }
//    return okay;
//}
//
//int main() {
//    setbuf(stdout, NULL);
//    //freopen("sample_input.txt", "r", stdin);
//
//    int T, MARK;
//    scanf("%d %d", &T, &MARK);
//
//    for (int tc = 1; tc <= T; tc++) {
//        int score = run() ? MARK : 0;
//        printf("#%d %d\n", tc, score);
//    }
//
//    return 0;
//}
//
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <string>
//
//#define MAX_C 26 // 알파벳 소문자만을 고려
//using namespace std;
//
//class Trie {
//private:
//    struct TrieNode {
//        int child[MAX_C];
//        int count;
//
//        TrieNode() {
//            memset(child, -1, sizeof(child));
//            count = 0;
//        }
//    };
//
//    vector<TrieNode> nodes;
//
//    int addNode(const string& str) {
//        int node_id = 0;
//        for (char cur : str) {
//            if (cur == '\0') break; // 문자열의 끝에 도달했는지 확인
//            if (nodes[node_id].child[cur - 'a'] == -1) {
//                nodes[node_id].child[cur - 'a'] = nodes.size();
//                nodes.emplace_back();
//            }
//            node_id = nodes[node_id].child[cur - 'a'];
//        }
//        nodes[node_id].count += 1;
//        return nodes[node_id].count;
//    }
//
//    int searchNode(int cur_node, int pos, const string& str) const {
//        if (str[pos] == '\0') return nodes[cur_node].count;
//        if (str[pos] == '?') {
//            int ret = 0;
//            for (int next_node : nodes[cur_node].child) {
//                if (next_node != -1)
//                    ret += searchNode(next_node, pos + 1, str);
//            }
//            return ret;
//        } else {
//            int childIndex = nodes[cur_node].child[str[pos] - 'a'];
//            if (childIndex == -1) return 0; // 해당 문자로 시작하는 자식 노드가 없는 경우
//            return searchNode(childIndex, pos + 1, str);
//        }
//    }
//
//    int removeNode(int cur_node, int pos, const string& str) {
//        if (str[pos] == '\0') {
//            int ret = nodes[cur_node].count;
//            nodes[cur_node].count = 0;
//            return ret;
//        }
//        if (str[pos] == '?') {
//            int ret = 0;
//            for (int next_node : nodes[cur_node].child) {
//                if (next_node != -1)
//                    ret += removeNode(next_node, pos + 1, str);
//            }
//            return ret;
//        } else {
//            int childIndex = nodes[cur_node].child[str[pos] - 'a'];
//            if (childIndex == -1) return 0; // 해당 문자로 시작하는 자식 노드가 없는 경우
//            return removeNode(childIndex, pos + 1, str);
//        }
//    }
//
//public:
//    Trie() {
//        nodes.emplace_back(); // 루트 노드 추가
//    }
//
//    int add(const string& str) {
//        return addNode(str);
//    }
//
//    int search(const string& str) const {
//        return searchNode(0, 0, str);
//    }
//
//    int remove(const string& str) {
//        return removeNode(0, 0, str);
//    }
//};
//
//Trie trie;
//
//void init() {
//    trie = Trie();
//    return;
//}
//
//int add(char str[]) {
//    return trie.add(str);
//}
//
//int remove(char str[]) {
//    return trie.remove(str);
//}
//
//int search(char str[]) {
//    return trie.search(str);
//}