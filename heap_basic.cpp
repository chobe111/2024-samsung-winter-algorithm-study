//#define _CRT_SECURE_NO_WARNINGS
//
//
//#define MAX_INPUT 10000
//#define MAX_NUM 30000
//
//struct Person {
//    int uid;
//    int height;
//};
//
//class MaxHeap {
//private:
//    static constexpr int MAXN = 100001;
//    Person data[MAXN + 1];
//    int size = 0;
//public:
//    MaxHeap() = default;
//
//    void swap(Person &a, Person &b) {
//        Person temp = a;
//        a = b;
//        b = temp;
//    }
//
//    // 데이터삽입
//    void push(Person p) {
//        data[++size] = p;
//        int cur_index = size;
//        int parent_index = (cur_index >> 1);
//
//        while (parent_index != 0 && data[cur_index].height >= data[parent_index].height) {
//            // 만약 높이가 같으면
//            if (data[cur_index].height == data[parent_index].height) {
//                if (data[cur_index].uid < data[parent_index].uid) {
//                    swap(data[parent_index], data[cur_index]);
//                }
//            } else {
//                swap(data[parent_index], data[cur_index]);
//            }
//            cur_index = cur_index >> 1;
//            parent_index = cur_index >> 1;
//        }
//    }
//
//    bool empty() {
//        return size == 0;
//    }
//
//    Person top() {
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
//            if (left <= size && data[left].height >= data[large].height) {
//                if (data[left].height == data[large].height) {
//                    if (data[left].uid < data[large].uid) {
//                        large = left;
//                    }
//                } else {
//                    large = left;
//                }
//            }
//            if (right <= size && data[right].height >= data[large].height) {
//                if (data[right].height == data[large].height) {
//                    if (data[right].uid < data[large].uid) {
//                        large = right;
//                    }
//                } else {
//                    large = right;
//                }
//            }
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
//MaxHeap hp;
//
//void init() {
//    hp = MaxHeap();
//}
//
//void addUser(int uID, int height) {
//    hp.push({uID, height});
//}
//
//int getTop10(int result[10]) {
//    int ret = 0;
//
//    MaxHeap tmp = MaxHeap();
//    while (!hp.empty() && ret < 10) {
//        Person top = hp.top();
//        result[ret++] = top.uid;
//        hp.pop();
//        tmp.push(top);
//    }
//
//    while(!tmp.empty()) {
//        Person top = tmp.top();
//        hp.push(top);
//        tmp.pop();
//    }
//    return ret;
//}
//
///*
// * partialsort
// * (10) (n-10)
// * result[11]
// * (0,1), (0,1)
// * 힙은 하나의 원소만 보장
// * 지금 까지 본 Uid 중에 가장 큰 것
// * 힙의 단점
// *  캐시가 힘듬??
// *
// * */
//
//
//extern void init();
//
//extern void addUser(int uID, int income);
//
//extern int getTop10(int result[10]);
//
//static int input[MAX_INPUT];
////
////static unsigned int seed = 13410;
////
////static unsigned int pseudoRand() {
////    seed = seed * 214013 + 2531011;
////    return (unsigned int)(seed >> 11) % MAX_NUM;
////}
////
////static void makeInput(int inputLen) {
////    for (int i = 0; i < inputLen; i++) {
////        input[i] = pseudoRand();
////    }
////}
////
////static int run() {
////    int N, userNum, uID = 0;
////    int score = 100, result[10], cnt;
////    int sum, check;
////    scanf("%d", &N);
//// N => 4 0 1 2 3
////    for (int i = 0; i < N; i++) {
////        scanf("%d", &userNum);
////        makeInput(userNum);
////        for (int j = 0; j < userNum; j++) {
////            addUser(uID++, input[j]);
////        }
////        cnt = getTop10(result);
////
////        sum = 0;
////        for (int j = 0; j < cnt; j++)
////            sum += result[j];
////        scanf("%d", &check);
////        if (check != sum)
////            score = 0;
////    }
////    return score;
////}
//
//int main(void) {
//    setbuf(stdout, NULL);
//    //freopen("partial_sort_input.txt", "r", stdin);
//    int T;
//    scanf("%d", &T);
//
//    for (int tc = 1; tc <= T; tc++) {
//        int result[10];
//        init();
//        addUser(0, 10);
//        addUser(1, 5);
//        addUser(2, 30);
//        getTop10(result);
//        for (int i = 0; i < 10; i++) std::cout << result[i]
//
//    }
//    return 0;
//}