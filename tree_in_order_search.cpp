////
//// Created by myungki cho on 2024/01/16.
////
////
//// Created by myungki cho on 2024/01/15.
////
//#include<iostream>
//#include<stack>
//#include<sstream>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//#define MAXN 201
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
//// [2 3]
//bool solve() {
//    memset(tree,0,sizeof(tree));
//    memset(node_info,0,sizeof (node_info));
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
//        if(input.size() >=3) {
//            int left = stoi(input[2]);
//            tree[num][0] = left;
//        }
//        if(input.size() >= 4) {
//            int right = stoi(input[3]);
//            tree[num][1] = right;
//        }
//    }
//
//    vector<pair<string,int>> in_order_search;
//    int current = 1;
//    while (!st.empty() || current) {
//        // 왼쪽 노드가 없을때 까지 푸쉬
//        while (current) {
//            st.push(current);
//            current = tree[current][0];
//        }
//
//        current = st.top();
//        st.pop();
//        in_order_search.push_back({node_info[current], current});
//        current = tree[current][1];
//    }
//
//    // 모든 피연산자가 반드시 리프노드여야함 모든 연산자는 반드시 두개의 자식을 가지고 있어야함
//    for(int i = 0; i < in_order_search.size(); i++) {
//        string component = in_order_search[i].first;
//        int pos = in_order_search[i].second;
//
//        // 피연산자일 경우
//        if(all_of(component.begin(), component.end(), ::isdigit)) {
//            if(tree[pos][0] || tree[pos][1]) return false;
//        }
//            // 연산자일 경우
//        else {
//            if(! (tree[pos][0] && tree[pos][1])) return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    for (int i = 0; i < 10; i++) {
//        cout << "#"  <<i+1 << " ";
//        cout << int(solve());
//        cout << "\n";
//    }
//    return 0;
//}