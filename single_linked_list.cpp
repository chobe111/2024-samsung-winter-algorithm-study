////
//// Created by myungki cho on 2024/01/15.
////
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class LinkedList {
//private:
//    struct Node {
//        int x;
//        Node *next;
//
//        Node(int x) {
//            this->x = x;
//            this->next = nullptr;
//        }
//    };
//
//    Node *head;
//    Node *tail;
//
//    Node *findNode(int x) {
//        // 앞에서 부터 x 번째 노드를 찾는다
//        Node *cur = head;
//        x -= 1;
//        while (x-- && cur->next != nullptr) {
//            cur = cur->next;
//        }
//        return cur;
//    }
//
//    void addBack(int x) {
//        if (head == nullptr && tail == nullptr) {
//            head = new Node(x);
//            tail = head;
//            return;
//        }
//        Node *new_node = new Node(x);
//        tail->next = new_node;
//        tail = new_node;
//    }
//
//    void addFront(int x) {
//        if (head == nullptr && tail == nullptr) {
//            head = new Node(x);
//            tail = head;
//            return;
//        }
//        Node *new_node = new Node(x);
//        new_node->next = head;
//        head = new_node;
//    }
//
//public:
//    LinkedList() {
//        this->head = nullptr;
//        this->tail = nullptr;
//    }
//
//    void insert(int x, int y, vector<int> &encrypted_num_list) {
//        if (x == 0) {
//            for(int i = y-1; i >=0; i--) {
//                this->addFront(encrypted_num_list[i]);
//            }
//            return;
//        }
//        Node *start_node = findNode(x);
//        Node *cur_node = start_node;
//        Node *end_node = cur_node->next;
//        for (int i = 0; i < y; i++) {
//            Node *new_node = new Node(encrypted_num_list[i]);
//            cur_node->next = new_node;
//            cur_node = new_node;
//        }
//        cur_node->next = end_node;
//        // 앞에서부터 x 개 다음에 y개의 입력데이터 인풋
//    }
//
//    void remove(int x, int y) {
//        Node *start_node = findNode(x);
//        Node *cur_node = start_node->next;
//        while (y--) {
//            Node *remove_node = cur_node;
//            cur_node = cur_node->next;
//            free(remove_node);
//        }
//        start_node->next = cur_node;
//    }
//
//    void insert(int x) {
//        this->addBack(x);
//    }
//
//    void print() {
//        Node *cur = this->head;
//        for(int i = 0; i < 10; i++) {
//            cout << cur->x << " ";
//            cur = cur->next;
//        }
//    }
//};
//
//LinkedList linkedList;
//
//void Insert() {
//    int x, y;
//    cin >> x >> y;
//    vector<int> vec;
//    for (int i = 0; i < y; i++) {
//        int num;
//        cin >> num;
//        vec.push_back(num);
//    }
//    linkedList.insert(x, y, vec);
//}
//
//void Delete() {
//    int x, y;
//    cin >> x >> y;
//    linkedList.remove(x, y);
//}
//
//void Add() {
//    int y;
//    cin >> y;
//    vector<int> vec;
//    for(int i = 0; i < y; i++) {
//        int num;
//        cin >> num;
//        linkedList.insert(num);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    for(int t=1; t <= 10; t++) {
//        linkedList = LinkedList();
//        int N, query;
//        cin >> N;
//        for (int i = 0; i < N; i++) {
//            int num;
//            cin >> num;
//            linkedList.insert(num);
//        }
//        cin >> query;
//        for (int q = 0; q < query; q++) {
//            char ty;
//            cin >> ty;
//            if (ty == 'I') {
//                Insert();
//            }
//            if (ty == 'D') {
//                Delete();
//            }
//            if (ty == 'A') {
//                Add();
//            }
//        }
//        cout << "#" << t << " ";
//        linkedList.print();
//        cout << "\n";
//    }
//
//}