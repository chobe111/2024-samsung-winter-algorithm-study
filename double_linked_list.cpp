////
//// Created by myungki cho on 2024/01/15.
////
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int T, N, M, L;
//
//class LinkedList {
//private:
//    struct Node {
//        int x;
//        Node *next;
//        Node *prev;
//
//        Node(int x) {
//            this->x = x;
//            this->next = nullptr;
//            this->prev = nullptr;
//        }
//    };
//
//    Node *head;
//    Node *tail;
//
//    void Add(int x) {
//        Node* newNode = new Node(x);
//        if (!head) {
//            head = tail = newNode;
//        } else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//    }
//
//    void AddFront(Node *node, int x) {
//        Node* newNode = new Node(x);
//        if (!node) {
//            return;
//        }
//
//        if (node->prev) {
//            node->prev->next = newNode;
//            newNode->prev = node->prev;
//        } else {
//            head = newNode;
//        }
//
//        newNode->next = node;
//        node->prev = newNode;
//    }
//
//    void Remove(Node* node) {
//        if (!node) {
//            return;
//        }
//
//        if (node->prev) {
//            node->prev->next = node->next;
//        } else {
//            head = node->next;
//        }
//
//        if (node->next) {
//            node->next->prev = node->prev;
//        } else {
//            tail = node->prev;
//        }
//
//        delete node;
//    }
//
//    void Replace(Node *replace_node, int replace_target) {
//        replace_node->x = replace_target;
//    }
//
//    Node *findNode(int x) {
//        Node *cur_node = head;
//        while (x-- && cur_node != nullptr) {
//            cur_node = cur_node->next;
//        }
//        return cur_node;
//    }
//
//public:
//    LinkedList() {
//        this->head = nullptr;
//        this->tail = nullptr;
//    }
//
//    void add(int x) {
//        this->Add(x);
//    }
//
//    void insert(int x, int target) {
//        Node *insert_node = findNode(x);
//        this->AddFront(insert_node, target);
//    }
//
//    void remove(int x) {
//        Node *remove_node = findNode(x);
//        this->Remove(remove_node);
//    }
//
//    void replace(int index, int target) {
//        Node *replace_node = findNode(index);
//        this->Replace(replace_node, target);
//    }
//
//    int find(int index) {
//        Node* find_node = findNode(index);
//        if(find_node == nullptr) return -1;
//        return find_node->x;
//    }
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    cin >> T;
//
//    for (int turn = 1; turn <= T; turn++) {
//        LinkedList lst = LinkedList();
//        cin >> N >> M >> L;
//        for (int i = 0; i < N; i++) {
//            int num;
//            cin >> num;
//            lst.add(num);
//        }
//
//        for (int i = 0; i < M; i++) {
//            char q;
//            cin >> q;
//            if (q == 'I') {
//                int index, target;
//                cin >> index >> target;
//                lst.insert(index, target);
//            }
//            if (q == 'D') {
//                int index;
//                cin >> index;
//                lst.remove(index);
//            }
//            if (q == 'C') {
//                int index, target;
//                cin >> index >> target;
//                lst.replace(index, target);
//            }
//        }
//
//        cout << "#" << turn << " " << lst.find(L) << "\n";
//    }
//}