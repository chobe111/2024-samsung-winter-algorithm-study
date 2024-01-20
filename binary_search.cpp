//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<long long> candies;
//
//long long binarySearchForMaxCandiesPerBag(long long bags, long long maxCandyCount) {
//    long long low = 1, high = maxCandyCount;
//    long long optimalCandiesPerBag = 0;
//    while (high >= low) {
//        long long mid = low + (high - low) / 2;
//        long long requiredBags = 0;
//        for (auto candyCount : candies) {
//            requiredBags += candyCount / mid;
//        }
//        if (requiredBags < bags) {
//            high = mid - 1;
//        } else {
//            optimalCandiesPerBag = mid;
//            low = mid + 1;
//        }
//    }
//    return optimalCandiesPerBag;
//}
//
//void solveProblems(int testCases) {
//
//    for (int i = 0; i < testCases; ++i) {
//        long long numOfCandies, numOfBags, maxCandyCount = 0;
//        cin >> numOfCandies >> numOfBags;
//        candies.resize(numOfCandies);
//        for (long long &candyCount : candies) {
//            cin >> candyCount;
//            maxCandyCount = max(maxCandyCount, candyCount);
//        }
//        cout << '#' << i + 1 << ' ' << binarySearchForMaxCandiesPerBag(numOfBags, maxCandyCount) << '\n';
//        candies.clear();
//    }
//}
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int testCases;
//    cin >> testCases;
//    solveProblems(testCases);
//    return 0;
//}