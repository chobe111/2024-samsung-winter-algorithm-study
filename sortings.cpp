//
// Created by myungki cho on 2024/02/01.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void quick_sort() {

}

void merge_sort() {

}

void bubble_sort() {

}

int upper_bound(vector<int> &vec, int pos) {
    int s = 0, e = pos - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (vec[m] <= vec[pos]) s = m + 1;
        else e = m;
    }
    // 큰 원소를 찾지 못했을 경우
    if (vec[s] <= vec[pos]) return -1;
    return s;
}

const size_t RUN = 32;

void binary_insertion_sort(vector<int> &vec, int left, int right) {
    for (int i = left+1; i <= right; i++) {
        int small_pos = upper_bound(vec, i);
        int k = vec[i];
        if (small_pos == -1) continue;
        // 본인보다 큰 숫자가 존재하는 구간을 옆으로 한칸 shift 한다. 블록 이동
        move(vec.begin() + small_pos, vec.begin() + i, vec.begin() + small_pos + 1);
        vec[small_pos] = k;
    }
}

void merge(vector<int> &vec, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = vec[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = vec[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
        } else {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        vec[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        vec[k] = right[j];
        k++;
        j++;
    }
}

void timSort(vector<int> &vec, int n) {
    for (int i = 0; i < n; i += RUN)
        binary_insertion_sort(vec, i, min((i + 31), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(vec, left, mid, right);
        }
    }
}


int main() {
    vector<int> vec = {1, 4, 5, -2, -3, 5, 10};
    timSort(vec, (int)vec.size());
    for(int i: vec) cout << i << " ";
    return 0;
}