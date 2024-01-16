////
//// Created by myungki cho on 2024/01/15.
////
//#include<iostream>
//#include<stack>
//#include<sstream>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//
//#define MAXN 1001
//using namespace std;
//
//int tree[(MAXN << 2) + 1][2];
//string node_info[MAXN];
//
//std::vector<std::string> split(const std::string &s, char delimiter) {
//    std::vector<std::string> tokens;
//    std::stringstream ss(s);
//    std::string token;
//
//    while (std::getline(ss, token, delimiter)) {
//        tokens.push_back(token);
//    }
//
//    return tokens;
//}
//
//int get_num(int cur) {
//    int left = tree[cur][0];
//    int right = tree[cur][1];
//    string node = node_info[cur];
//
//    if (all_of(node.begin(), node.end(), ::isdigit)) {
//        return stoi(node);
//    }
//
//    int left_sum = get_num(left);
//    int right_sum = get_num(right);
//
//    if(node == "/") {
//        return left_sum / right_sum;
//    }
//    else if(node == "*") {
//        return left_sum * right_sum;
//    }
//    else if(node == "-") {
//        return left_sum - right_sum;
//    }
//    else {
//        return left_sum + right_sum;
//    }
//}
//
//int solve() {
//    memset(tree, 0, sizeof(tree));
//    memset(node_info, 0, sizeof(node_info));
//    int N;
//    cin >> N;
//    cin.ignore();
//    stack<int> st;
//    for (int i = 1; i <= N; i++) {
//        string s;
//        getline(cin, s);
//        vector<string> input = split(s, ' ');
//        int num = stoi(input[0]);
//        node_info[num] = input[1];
//        if (input.size() >= 3) {
//            int left = stoi(input[2]);
//            tree[num][0] = left;
//        }
//        if (input.size() >= 4) {
//            int right = stoi(input[3]);
//            tree[num][1] = right;
//        }
//    }
//
//    return get_num(1);
//}
//
//int main() {
//    for (int i = 0; i < 10; i++) {
//        cout << "#" << i + 1 << " ";
//        cout << solve();
//        cout << "\n";
//    }
//    return 0;
//}