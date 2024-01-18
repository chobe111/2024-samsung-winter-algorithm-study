////
//// Created by myungki cho on 2024/01/18.
////
///**
//* 힙
// * 힙 구현의 기본은 완전이진트리라고 가정
// * push pop top 구현
// * 시간 복잡도
// *  최대 혹은 최소 찾기: O(1)
// *  create : O(N)
// *  삽입, 삭제 : O(logN)
//*/
//#include<iostream>
//
//using namespace std;
//
//int T, N;
//
//class MaxHeap {
//private:
//    static constexpr size_t MAXN = 100001;
//    int data[MAXN + 1];
//    int size = 0;
//public:
//    MaxHeap() = default;
//
//    void swap(int &a, int &b) {
//        a = a ^ b;
//        b = a ^ b;
//        a = a ^ b;
//    }
//
//    // 데이터삽입
//    void push(int x) {
//        data[++size] = x;
//        int cur_index = size;
//        int parent_index = (cur_index >> 1);
//
//        while (parent_index != 0 && data[cur_index] > data[parent_index]) {
//            swap(data[parent_index], data[cur_index]);
//            cur_index = cur_index >> 1;
//            parent_index = cur_index >> 1;
//        }
//    }
//
//    int check_top_and_pop() {
//        if (size == 0) return -1;
//        int ret = top();
//        pop();
//        return ret;
//    }
//
//    int top() {
//        return data[1];
//    }
//
//    void pop() {
//        data[1] = data[size--];
//        int parent_index = 1;
//        int large = parent_index;
//        int left = parent_index * 2;
//        int right = parent_index * 2 + 1;
//
//        while (true) {
//            if (left <= size && data[left] > data[large]) large = left;
//            if (right <= size && data[right] > data[large]) large = right;
//            // 이미 힙구조 만족
//            if (large == parent_index) break;
//            swap(data[large], data[parent_index]);
//            parent_index = large;
//            left = parent_index * 2;
//            right = parent_index * 2 + 1;
//        }
//    }
//
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//        MaxHeap heap = MaxHeap();
//        cin >> N;
//        cout << "#" << t << " ";
//        for (int i = 0; i < N; i++) {
//            int q;
//            cin >> q;
//            if (q == 1) {
//                int num;
//                cin >> num;
//                heap.push(num);
//            } else {
//                cout << heap.check_top_and_pop() << " ";
//            }
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}