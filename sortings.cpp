//
// Created by myungki cho on 2024/02/01.
//
#include<iostream>
#include<vector>

using namespace std;

void quick_sort() {

}

void merge_sort() {

}

void bubble_sort() {

}

void insertion_sort(vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && key < vec[j]) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j] = key;
    }
}

void selection_sort(vector<int> &vec) {
    /*
     * 오름차순 정렬
     * 선택 정렬: 기준 잡고 뒤에서 젤 작은거 선택해서 정렬
     * 평균, 최악, 최선 시간복잡도: O(N^2)
     * 메모리: O(N)
     */
    for (int i = 0; i < vec.size(); i++) {
        int tmp = i;
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[tmp]) {
                tmp = j;
            }
        }
        swap(vec[i], vec[tmp]);
    }
}

int main() {

    return 0;
}